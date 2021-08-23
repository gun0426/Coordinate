#pragma once


// CDlgMainCtrl 대화 상자입니다.

class CDlgMainCtrl : public CDialog
{
	DECLARE_DYNAMIC(CDlgMainCtrl)

public:
	CDlgMainCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMainCtrl();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLG_MAINCTRL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	BOOL Create(CWnd* pParentWnd);
	afx_msg void OnBnClickedButton1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
