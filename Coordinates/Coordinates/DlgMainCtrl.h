#pragma once


// CDlgMainCtrl ��ȭ �����Դϴ�.

class CDlgMainCtrl : public CDialog
{
	DECLARE_DYNAMIC(CDlgMainCtrl)

public:
	CDlgMainCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMainCtrl();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_MAINCTRL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	BOOL Create(CWnd* pParentWnd);
	afx_msg void OnBnClickedButton1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
