
// NexBookDesigner3.5Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "NexBookDesigner3.5.h"
#include "NexBookDesigner3.5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CNexBookDesigner35Dlg ��ȭ ����

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


// CNexBookDesigner35Dlg �޽��� ó����

BOOL CNexBookDesigner35Dlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	ShowWindow(SW_MAXIMIZE);

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CNexBookDesigner35Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CNexBookDesigner35Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CNexBookDesigner35Dlg::OnButtonOK(IHTMLElement* pElement)
{
	// CSS ��� �׽�Ʈ
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
	
	// ���õ� �̹��� ��θ� �޾Ƽ� �������� ����
	WCHAR* workpath = L"c:\\ProgramData\\FBookStudio\\NexBook35\\Designer\\workspace\\assets\\theme";
	int pathLen = wcslen(workpath);
	WCHAR* pszPath = new WCHAR[pathLen + 2];
	wcscpy_s(pszPath, pathLen+2, workpath);
	pszPath[pathLen]	 = NULL;
	pszPath[pathLen + 1] = NULL;
	
	// ���� �ʱ�ȭ
	SHFILEOPSTRUCT shfo = { NULL, FO_DELETE, pszPath, NULL, FOF_SILENT | FOF_NOERRORUI | FOF_NOCONFIRMATION, FALSE, NULL, NULL };
	SHFileOperation(&shfo);

	delete[] pszPath;

	// ���� ����
	CreateDirectory(workpath, NULL);

	// ���� ����
	FileCopy(skinPath, workpath);

	// �ΰ��̹��� ����

	
	// ����� ���Ϸ� ȭ�鿡 ���
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

	// â�ݱ�
	arg.RemoveAll();
	arg.Add(L"#wnd_new");
	CallJScript(L"closeDiv", arg);

	return S_OK;
}

int CNexBookDesigner35Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDHtmlDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// �޴��� ����
	m_menu.LoadMenuW(IDR_MENU);
	SetMenu(&m_menu);

	// ���� ����
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
	CDialog::OnSize(nType, cx, cy);// CDialog ȣ��� �����ӹ��� CDHtmlDialog::OnSize(nType, cx, cy);

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
	MessageBox(L"����");

	/*CStringArray arg;
	arg.Add(L"�׽�Ʈ!");
	CallJScript(L"alert", arg);*/
}


void CNexBookDesigner35Dlg::OnFileSave()
{
	MessageBox(L"����");
}


void CNexBookDesigner35Dlg::OnFileSaveas()
{
	MessageBox(L"�ٸ��̸�����");
}


void CNexBookDesigner35Dlg::OnAppExit()
{
	MessageBox(L"������");
}


void CNexBookDesigner35Dlg::OnAppOption()
{
	MessageBox(L"����");
}


void CNexBookDesigner35Dlg::OnAppHelp()
{
	MessageBox(L"����");
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