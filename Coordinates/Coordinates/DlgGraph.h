#pragma once

#include "MLineChartCtrl.h"


// CDlgGraph ��ȭ �����Դϴ�.

class CDlgGraph : public CDialog
{
	DECLARE_DYNAMIC(CDlgGraph)

public:
	CDlgGraph(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgGraph();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLG_GRAPH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	BOOL Create(CWnd* pParentWnd);
	virtual BOOL OnInitDialog();

	MLineChartCtrl m_LineChartCtrl;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
