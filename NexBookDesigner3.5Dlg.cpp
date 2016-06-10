
// NexBookDesigner3.5Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "NexBookDesigner3.5.h"
#include "NexBookDesigner3.5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNexBookDesigner35Dlg 대화 상자

BEGIN_DHTML_EVENT_MAP(CNexBookDesigner35Dlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
	DHTML_EVENT_ONCLICK(_T("new_ok"), OnNewOk)
END_DHTML_EVENT_MAP()


CNexBookDesigner35Dlg::CNexBookDesigner35Dlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(IDD_NEXBOOKDESIGNER35_DIALOG, IDR_HTML_NEXBOOKDESIGNER35_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNexBookDesigner35Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNexBookDesigner35Dlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_NEW, &CNexBookDesigner35Dlg::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CNexBookDesigner35Dlg::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CNexBookDesigner35Dlg::OnFileSave)
	ON_COMMAND(ID_FILE_SAVEAS, &CNexBookDesigner35Dlg::OnFileSaveas)
	ON_COMMAND(ID_APP_EXIT, &CNexBookDesigner35Dlg::OnAppExit)
	ON_COMMAND(ID_APP_OPTION, &CNexBookDesigner35Dlg::OnAppOption)
	ON_COMMAND(ID_APP_HELP, &CNexBookDesigner35Dlg::OnAppHelp)
	ON_COMMAND(ID_APP_INFO, &CNexBookDesigner35Dlg::OnAppInfo)
END_MESSAGE_MAP()


// CNexBookDesigner35Dlg 메시지 처리기

BOOL CNexBookDesigner35Dlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	ShowWindow(SW_MAXIMIZE);

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CNexBookDesigner35Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CNexBookDesigner35Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CNexBookDesigner35Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CNexBookDesigner35Dlg::OnButtonOK(IHTMLElement* pElement)
{
	// CSS 얻기 테스트
	IHTMLStyle* css = nullptr; {
		pElement->get_style(&css);
		BSTR txt = nullptr; {
			css->get_cssText(&txt);
			AfxMessageBox(txt);
			::SysFreeString(txt);
		}
		css->Release();
	}
	
	AfxMessageBox(L"OK!");
	OnOK();
	return S_OK;
}

HRESULT CNexBookDesigner35Dlg::OnButtonCancel(IHTMLElement* pElement)
{
	AfxMessageBox(L"Cancel!");
	OnCancel();
	return S_OK;
}

HRESULT CNexBookDesigner35Dlg::OnNewOk(IHTMLElement* pElement)
{
	HRESULT			hr = S_OK;
	CString			skinPath;
	BSTR			str;
	IHTMLElement*	e;
	hr = GetElement(L"new_preview", &e);
	if (!SUCCEEDED(hr)) {
		return hr;
	}
	e->get_outerHTML(&str);
	skinPath = str;
	::SysFreeString(str);

	const auto stPos = skinPath.Find(L"file://") + 7;
	const auto cnt = skinPath.Find(L".jpg", stPos) - stPos;

	skinPath = skinPath.Mid(stPos, cnt);
	
	// 선택된 이미지 경로를 받아서 폴더복사 수행
	WCHAR* workpath = L"c:\\ProgramData\\FBookStudio\\NexBook35\\Designer\\workspace\\assets\\theme";
	int pathLen = wcslen(workpath);
	WCHAR* pszPath = new WCHAR[pathLen + 2];
	wcscpy_s(pszPath, pathLen+2, workpath);
	pszPath[pathLen]	 = NULL;
	pszPath[pathLen + 1] = NULL;
	
	// 폴더 초기화
	SHFILEOPSTRUCT shfo = { NULL, FO_DELETE, pszPath, NULL, FOF_SILENT | FOF_NOERRORUI | FOF_NOCONFIRMATION, FALSE, NULL, NULL };
	SHFileOperation(&shfo);

	delete[] pszPath;

	// 폴더 생성
	CreateDirectory(workpath, NULL);

	// 파일 복사
	FileCopy(skinPath, workpath);

	// 로고이미지 복사

	
	// 복사된 파일로 화면에 출력
	hr = GetElement(L"skinview", &e);
	if (!SUCCEEDED(hr)) {
		return hr;
	}
	str = _bstr_t(L"<iframe src=\"file:///c:/ProgramData/FBookStudio/NexBook35/Designer/workspace/index.html\" style=\"width:100%;height:100%;\" />");
	e->put_innerHTML(str);
	::SysFreeString(str);

	CStringArray arg;
	arg.Add(L"#skinview");
	CallJScript(L"openDiv", arg);

	// 창닫기
	arg.RemoveAll();
	arg.Add(L"#wnd_new");
	CallJScript(L"closeDiv", arg);

	return S_OK;
}

int CNexBookDesigner35Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDHtmlDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 메뉴바 생성
	m_menu.LoadMenuW(IDR_MENU);
	SetMenu(&m_menu);

	// 툴바 생성
	if (!m_toolbar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_TOOLTIPS | CBRS_FLYBY)
	||	!m_toolbar.LoadToolBar(IDR_TOOLBAR))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}
	return 0;
}


void CNexBookDesigner35Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);// CDialog 호출로 깜빡임방지 CDHtmlDialog::OnSize(nType, cx, cy);

	static const int TOOLBAR_HEIGHT = 44;
	if(m_wndBrowser){
		RECT rcBrowser;
		GetClientRect(&rcBrowser);
		m_toolbar.MoveWindow(CRect(0, 0, rcBrowser.right, TOOLBAR_HEIGHT));
		m_wndBrowser.MoveWindow(0, TOOLBAR_HEIGHT, rcBrowser.right, rcBrowser.bottom - TOOLBAR_HEIGHT);
	}
}


void CNexBookDesigner35Dlg::OnFileNew()
{
	HANDLE			hsch;
	WIN32_FIND_DATA	wfd;
	CString			fileName = L"<li class='label'>FileName</li>";

	if (INVALID_HANDLE_VALUE == (hsch = FindFirstFile(L"c:\\ProgramData\\FBookStudio\\NexBook35\\skins\\*.jpg", &wfd))) { return; }

	do {
		fileName += L"<li onclick='updateNewPreviewImage(this)'>";
		fileName += wfd.cFileName;
		fileName += L"</li>";
	} while (FindNextFile(hsch, &wfd));
	FindClose(hsch);

	//fileName.Replace(L".jpg", L"");

	HRESULT hr = S_OK;
	IHTMLElement* e;
	BSTR str;
	hr = GetElement(L"new_filelist", &e);
	if (SUCCEEDED(hr)) {
		str = _bstr_t(fileName.GetBuffer());
		e->put_innerHTML(str);
		::SysFreeString(str);
	}

	hr = GetElement(L"wnd_new", &e);
	IHTMLStyle* s;
	e->get_style(&s);
	str = _bstr_t(L"block");
	s->put_display(str);
	::SysFreeString(str);
}


void CNexBookDesigner35Dlg::OnFileOpen()
{
	MessageBox(L"열기");

	/*CStringArray arg;
	arg.Add(L"테스트!");
	CallJScript(L"alert", arg);*/
}


void CNexBookDesigner35Dlg::OnFileSave()
{
	MessageBox(L"저장");
}


void CNexBookDesigner35Dlg::OnFileSaveas()
{
	MessageBox(L"다른이름저장");
}


void CNexBookDesigner35Dlg::OnAppExit()
{
	MessageBox(L"끝내기");
}


void CNexBookDesigner35Dlg::OnAppOption()
{
	MessageBox(L"설정");
}


void CNexBookDesigner35Dlg::OnAppHelp()
{
	MessageBox(L"도움말");
}


void CNexBookDesigner35Dlg::OnAppInfo()
{
	OnSysCommand(IDM_ABOUTBOX, NULL);
}

void CNexBookDesigner35Dlg::OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl)
{
	CDHtmlDialog::OnDocumentComplete(pDisp, szUrl);

	HRESULT hr = S_OK;
	hr = GetDHtmlDocument(&m_htmlDoc);
	
	
	//HRESULT hr = S_OK;
	/*IHTMLElement* e;
	BSTR str;
	hr = GetElement(L"skinview", &e);
	if (SUCCEEDED(hr)) {
		e->get_innerHTML(&str);
		::SysFreeString(str);
		str = _bstr_t(L"<iframe src='file:///c:\\ProgramData\\FBookStudio\\NexBook35\\Designer\\workspace\\index.html' style='width:100%;height:100%;' />");
		e->put_innerHTML(str);
		::SysFreeString(str);

		IHTMLStyle* s;
		e->get_style(&s);
		str = _bstr_t(L"block");
		s->put_display(str);
		::SysFreeString(str);
	}*/

	/*
	IHTMLElement* e;
	//hr = GetElement(L"myBody", &e);
	
	hr = m_htmlDoc->get_body(&e);
	if (SUCCEEDED(hr)) {
		BSTR str;
		e->put_innerHTML(L"<h1>someLoadingInputWillGoHereLater</h1>");
		e->get_innerHTML(&str);
		MessageBox(str);
		::SysFreeString(str);
	}
	*/
}

BOOL CNexBookDesigner35Dlg::FileCopy(CString strFrom, CString strTo)
{
	strFrom += L"\\*.*";

	SHFILEOPSTRUCT	shfo			= { 0 };
	TCHAR			pszTo	[1024]	= { 0 };
	TCHAR			pszFrom	[1024]	= { 0 };

	wcscpy_s(pszFrom,	strFrom	);
	wcscpy_s(pszTo,		strTo	);
	pszFrom	[strFrom.GetLength() + 1] = NULL;
	pszTo	[strTo.GetLength()	 + 1] = NULL;
	shfo.wFunc	= FO_COPY;
	shfo.pFrom	= pszFrom;
	shfo.pTo	= pszTo;
	shfo.fFlags = FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR;

	int ret = SHFileOperation(&shfo);
	return shfo.fAnyOperationsAborted;
}



CComVariant CNexBookDesigner35Dlg::CallJScript(const CString strFunc, const CStringArray& paramArray)
{
	auto GetJScript = [&](CComPtr<IDispatch>& spDisp) -> bool {
		HRESULT hr = m_htmlDoc->get_Script(&spDisp);
		ATLASSERT(SUCCEEDED(hr));
		return SUCCEEDED(hr);
	};
	CComPtr<IDispatch> spScript;
	if (!GetJScript(spScript)){
		return false;
	}
	CComBSTR bstrMember(strFunc);
	DISPID dispid = NULL;
	HRESULT hr = spScript->GetIDsOfNames(IID_NULL, &bstrMember, 1, LOCALE_SYSTEM_DEFAULT, &dispid);
	if (FAILED(hr)){
		return false;
	}

	const int arraySize = paramArray.GetSize();
	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof dispparams);
	dispparams.cArgs = arraySize;
	dispparams.rgvarg = new VARIANT[dispparams.cArgs];
	dispparams.cNamedArgs = 0;

	for (int i = 0; i < arraySize; ++i){
		CComBSTR bstr = paramArray.GetAt(arraySize - 1 - i);
		bstr.CopyTo(&dispparams.rgvarg[i].bstrVal);
		dispparams.rgvarg[i].vt = VT_BSTR;
	}
	EXCEPINFO excepInfo;
	memset(&excepInfo, 0, sizeof excepInfo);
	CComVariant vaResult;
	UINT nArgErr = (UINT)-1;
	hr = spScript->Invoke(dispid, IID_NULL, 0, DISPATCH_METHOD, &dispparams, &vaResult, &excepInfo, &nArgErr);
	delete[] dispparams.rgvarg;
	if (FAILED(hr)){
		return false;
	}
	return vaResult;
}