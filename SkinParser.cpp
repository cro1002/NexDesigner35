#include "stdafx.h"
#include "SkinParser.h"

#include <fstream>
#include <codecvt>
#include <algorithm>

SkinParser::SkinParser()
{
}


SkinParser::~SkinParser()
{
}

bool SkinParser::LoadJS(const wstring& path, SKINDATAJS& retData)
{
	const UINT	MAX_LINE = 1024;
	wchar_t		wtexts	[MAX_LINE] = { NULL };

	vector<wstring> textdata;
	wstring tmpStr;
	
	wifstream	inFile(path, ios_base::binary);
	inFile.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));

	size_t pos;
	auto IS_SPACE = [](const wchar_t ch) -> bool { return (ch == L'\t' || ch == L'\r' || ch == L'\n'); };

	while (!inFile.eof()) {
		inFile.getline(wtexts, MAX_LINE);
		if (nullptr != wcsstr(wtexts, L"eBookSkin.objects")) {
			while (!inFile.eof()) {
				inFile.getline(wtexts, MAX_LINE);
				tmpStr = wtexts;
				
				// 공백제거
				tmpStr.erase(remove_if(tmpStr.begin(), tmpStr.end(), IS_SPACE), tmpStr.end());

				// 주석제거
				while (wstring::npos != (pos = tmpStr.find(L"/*"))) {
					const size_t pos_ed = tmpStr.find(L"*/");
					if (wstring::npos != pos_ed) {
						tmpStr = tmpStr.substr(0, pos+2) + tmpStr.substr(pos_ed+2, tmpStr.length()-pos_ed-2);
					} else {
						while (wstring::npos == (pos = tmpStr.find(L"*/"))) {}
						tmpStr = tmpStr.substr(pos+2, tmpStr.length() - pos - 2);
						textdata.push_back(tmpStr);
						continue;
					}
				}
				pos = tmpStr.find(L"//");
				if (wstring::npos != pos) {
					tmpStr = tmpStr.substr(0, pos);
				}


				if (tmpStr.empty()) { continue; }
				if (nullptr != wcsstr(wtexts, L"];")) {
					break;
				}
				textdata.push_back(tmpStr);
			}
			break;
		}
	}
	inFile.close();


	// textdata 를 기준으로 SKINDATAJS 객체 작성
	SKINDATAJS	*target = nullptr,
				*parent = &retData;
	for (size_t i = 0; i < textdata.size(); ++i) {

		const auto&	text = textdata[i];

		if (wstring::npos != (pos = text.find(L"]},"))) {// 하위객체 끝 처리
			target = target->parent;
			parent = target->parent;
			if (nullptr == parent) { break; }
		
		} else {
			// 루프에서 최상위 객체에서 하위객체에 추가
			parent->children.push_back(make_shared<SKINDATAJS>(parent));
			target = parent->children.back().get();

			wstring label, value;
			size_t pos_split=0;
			while (wstring::npos != (pos = text.find(L":", pos_split))) {

				const size_t label_st = text.find_last_of(L" {,\t",pos-1);
				label = text.substr(label_st+1, pos - label_st - 1);
				label.erase(remove_if(label.begin(), label.end(), [](wchar_t ch) { return (ch == L'\'' || ch == L'\"'); }), label.end());

				const size_t value_ed = text.find_first_of(L"}[,", pos + 1);
				value = text.substr(pos+1, value_ed - pos - 1);
				value.erase(remove_if(value.begin(), value.end(), [](wchar_t ch) { return (ch == L'\'' || ch == L'\"'); }), value.end());
				
				// 라벨 분석 처리
				if (wstring::npos != label.find(L"type")) {
					target->type = value;
				}
				else if (wstring::npos != label.find(L"id")) {
					target->id = value;
				}
				else if (wstring::npos != label.find(L"children")) {
					parent = target;
				}
				else {
					target->attrs.push_back(make_pair(label, value));
				}

				pos_split = pos + 1;
			}
		}
	}

	return TRUE;
}

bool SkinParser::LoadCSS(const wstring& path, SKINDATACSS& retData)
{




	return TRUE;
}