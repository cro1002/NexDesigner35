
// NexBookDesigner3.5Dlg.h : ��� ����
//

#pragma once


// CNexBookDesigner35Dlg ��ȭ ����
class CNexBookDesigner35Dlg : public CDHtmlDialog
{
// �����Դϴ�.
public:
	CNexBookDesigner35Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEXBOOKDESIGNER35_DIALOG, IDH = IDR_HTML_NEXBOOKDESIGNER35_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

	HRESULT OnNewOk(IHTMLElement *pElement);

	BOOL FileCopy(CString strFrom, CString strTo);
	
	CComVariant CallJScript(const CString strFunc, const CStringArray& paramArray);

// �����Դϴ�.
protected:
	IHTMLDocument2* m_htmlDoc = nullptr;
	CMFCToolBar m_toolbar;
	CMenu m_menu;
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
