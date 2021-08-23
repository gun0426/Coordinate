// DlgGraph.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Coordinates.h"
#include "DlgGraph.h"
#include "afxdialogex.h"


// CDlgGraph ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgGraph, CDialog)

CDlgGraph::CDlgGraph(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgGraph::IDD, pParent)
{

}

CDlgGraph::~CDlgGraph()
{
}

void CDlgGraph::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgGraph, CDialog)
	ON_WM_SIZE()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()


// CDlgGraph �޽��� ó�����Դϴ�.


BOOL CDlgGraph::Create(CWnd* pParentWnd)
{
	return CDialog::Create(IDD_DLG_GRAPH, pParentWnd);
}


BOOL CDlgGraph::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CRect rect;
	GetClientRect(rect);
	if (!m_LineChartCtrl.m_hWnd)
	{
		m_LineChartCtrl.Create(NULL, NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, rect.Width(), rect.Height()), this, 1234);
	}
	//CFont font;
	//font.CreateFont(15, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, _T("Consolas"));
	//
	//
	//chFormat.dwMask = CFM_COLOR;		// | CFM_UNDERLINE | CFM_BOLD;
	//chFormat.dwEffects = CFE_ALLCAPS;	// CFE_BOLD | CFE_UNDERLINE;
	//chFormat.yHeight = 200;
	//chFormat.crTextColor = RGB(255, 0, 0);
	//SetFont(CFont, 1);

	m_LineChartCtrl.iExpand = 1000;
	m_LineChartCtrl.dblAxisScale = 1.0;
	m_LineChartCtrl.iItem_n = 1;
	m_LineChartCtrl.iGraph_n = 1;

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlgGraph::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_LineChartCtrl.m_hWnd)
	{
		m_LineChartCtrl.MoveWindow(0, 0, cx, cy, TRUE);	// --> m_LineChartCtrl.OnSize()
	}
}

