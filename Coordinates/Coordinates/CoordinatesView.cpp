
// CoordinatesView.cpp : CCoordinatesView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Coordinates.h"
#endif

#include "CoordinatesDoc.h"
#include "CoordinatesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCoordinatesView

IMPLEMENT_DYNCREATE(CCoordinatesView, CView)

BEGIN_MESSAGE_MAP(CCoordinatesView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_MOUSEWHEEL()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CCoordinatesView ����/�Ҹ�

CCoordinatesView::CCoordinatesView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CCoordinatesView::~CCoordinatesView()
{
}

BOOL CCoordinatesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CCoordinatesView �׸���

void CCoordinatesView::OnDraw(CDC* /*pDC*/)
{
	CCoordinatesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CCoordinatesView �μ�

BOOL CCoordinatesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CCoordinatesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CCoordinatesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CCoordinatesView ����

#ifdef _DEBUG
void CCoordinatesView::AssertValid() const
{
	CView::AssertValid();
}

void CCoordinatesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCoordinatesDoc* CCoordinatesView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCoordinatesDoc)));
	return (CCoordinatesDoc*)m_pDocument;
}
#endif //_DEBUG


// CCoordinatesView �޽��� ó����


void CCoordinatesView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CView::OnPaint()��(��) ȣ������ ���ʽÿ�.
}



//BOOL CCoordinatesView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	if (zDelta < 0)
//	{
//		m_DlgGrpah.m_LineChartCtrl.iExpand++;
//	}
//	else
//	{
//		m_DlgGrpah.m_LineChartCtrl.iExpand--;
//	}
//	//m_LineChartCtrl.m_aData[0].Add(0, 0, 0);
//	//m_LineChartCtrl.nXDataTotal++;
//	//m_DlgGrpah.m_LineChartCtrl.RedrawWindow();
//
//	return CView::OnMouseWheel(nFlags, zDelta, pt);
//}

