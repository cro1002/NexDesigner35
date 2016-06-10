
// NexBookDesigner3.5Dlg.h : 헤더 파일
//

#pragma once


// CNexBookDesigner35Dlg 대화 상자
class CNexBookDesigner35Dlg : public CDHtmlDialog
{
// 생성입니다.
public:
	CNexBookDesigner35Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEXBOOKDESIGNER35_DIALOG, IDH = IDR_HTML_NEXBOOKDESIGNER35_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

	HRESULT OnNewOk(IHTMLElement *pElement);

	BOOL FileCopy(CString strFrom, CString strTo);
	
	CComVariant CallJScript(const CString strFunc, const CStringArray& paramArray);

// 구현입니다.
protected:
	IHTMLDocument2* m_htmlDoc = nullptr;
	CMFCToolBar m_toolbar;
	CMenu m_menu;
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveas();
	afx_msg void OnAppExit();
	afx_msg void OnAppOption();
	afx_msg void OnAppHelp();
	afx_msg void OnAppInfo();
	virtual void OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl);
};
