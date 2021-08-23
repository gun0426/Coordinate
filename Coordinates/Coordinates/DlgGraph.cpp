// DlgGraph.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Coordinates.h"
#include "DlgGraph.h"
#include "afxdialogex.h"


// CDlgGraph 대화 상자입니다.

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


// CDlgGraph 메시지 처리기입니다.


BOOL CDlgGraph::Create(CWnd* pParentWnd)
{
	return CDialog::Create(IDD_DLG_GRAPH, pParentWnd);
}


BOOL CDlgGraph::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
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
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgGraph::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_LineChartCtrl.m_hWnd)
	{
		m_LineChartCtrl.MoveWindow(0, 0, cx, cy, TRUE);	// --> m_LineChartCtrl.OnSize()
	}
}

