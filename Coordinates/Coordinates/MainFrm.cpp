
// MainFrm.cpp : CMainFrame Ŭ������ ����
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
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	//���������if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
	//���������	!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	//���������{
	//���������	TRACE0("���� ������ ������ ���߽��ϴ�.\n");
	//���������	return -1;      // ������ ���߽��ϴ�.
	//���������}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	//���������// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	//���������m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//���������EnableDocking(CBRS_ALIGN_ANY);
	//���������DockControlBar(&m_wndToolBar);

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

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


// CMainFrame �޽��� ó����



void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	pDlgGraph->m_LineChartCtrl.m_aData[0].Add(1, 2, 0);
	pDlgGraph->m_LineChartCtrl.m_aData[0].Add(1, 2, 0);
	pDlgGraph->m_LineChartCtrl.m_aData[0].Add(1, 2, 0);
	pDlgGraph->m_LineChartCtrl.RedrawWindow();

	CFrameWnd::OnTimer(nIDEvent);
}
