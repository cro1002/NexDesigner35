#pragma once

#include <string>
#include <vector>
#include <utility>
#include <memory>

using namespace std;

struct SKINDATAJS {
	wstring							type, id;
	vector <pair<wstring,wstring>>	attrs;

	SKINDATAJS*						parent;
	vector <shared_ptr<SKINDATAJS>>	children;

	SKINDATAJS(SKINDATAJS* _parent=nullptr) { parent = _parent; };
};

struct SKINDATACSS {
	wstring				selector;
	vector <wstring>	props;
};

class SkinParser
{
public:
	bool LoadJS	(const wstring& path, SKINDATAJS& retData);
	bool LoadCSS(const wstring& path, SKINDATACSS& retData);
	
	SkinParser();
	virtual ~SkinParser();
};