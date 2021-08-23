
// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "Coordinates.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SIZE()
	ON_WM_MOUSEWHEEL()
	ON_WM_TIMER()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	//툴바지우기if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//툴바지우기	!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	//툴바지우기{
	//툴바지우기	TRACE0("도구 모음을 만들지 못했습니다.\n");
	//툴바지우기	return -1;      // 만들지 못했습니다.
	//툴바지우기}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	//툴바지우기// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	//툴바지우기m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//툴바지우기EnableDocking(CBRS_ALIGN_ANY);
	//툴바지우기DockControlBar(&m_wndToolBar);

	// GUN
	CRect rect;
	GetClientRect(rect);
	pDlgMainCtrl = new CDlgMainCtrl;
	pDlgMainCtrl->Create(this);
	pDlgMainCtrl->ShowWindow(SW_SHOW);
	pDlgMainCtrl->MoveWindow(0, 0, 300, rect.Height() - 22);
	
	pDlgGraph = new CDlgGraph;
	pDlgGraph->Create(this);
	pDlgGraph->ShowWindow(SW_SHOW);
	pDlgGraph->MoveWindow(300, 0, rect.Width() - 300, rect.Height()-22);	// x,y,width,height

	SetTimer(1, 500, NULL);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기



void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(rect);
	if (pDlgMainCtrl != NULL)
	{
		pDlgMainCtrl->MoveWindow(0, 0, 300, rect.Height() - 22);
	}
	if (pDlgGraph != NULL)
	{
		pDlgGraph->MoveWindow(300, 0, rect.Width() - 300, rect.Height() - 22);	// x,y,width,height
	}
}


BOOL CMainFrame::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nRet = GetKeyState(VK_CONTROL);

	if (nRet & 0x80000000)
	{
		if (zDelta < 0)
		{
			if (pDlgGraph->m_LineChartCtrl.iExpand < 2005)
			{
				pDlgGraph->m_LineChartCtrl.iExpand++;
			}
		}
		else
		{
			if (pDlgGraph->m_LineChartCtrl.iExpand > 5)
			{
				pDlgGraph->m_LineChartCtrl.iExpand--;
			}
		}
		pDlgGraph->m_LineChartCtrl.RedrawWindow();
	}

	return CFrameWnd::OnMouseWheel(nFlags, zDelta, pt);
}


void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	pDlgGraph->m_LineChartCtrl.m_aData[0].Add(1, 2, 0);
	pDlgGraph->m_LineChartCtrl.m_aData[0].Add(1, 2, 0);
	pDlgGraph->m_LineChartCtrl.m_aData[0].Add(1, 2, 0);
	pDlgGraph->m_LineChartCtrl.RedrawWindow();

	CFrameWnd::OnTimer(nIDEvent);
}
