
// CoordinatesView.h : CCoordinatesView Ŭ������ �������̽�
//

#pragma once

#include "DlgGraph.h"
#include "DlgMainCtrl.h"

class CCoordinatesView : public CView
{
protected: // serialization������ ��������ϴ�.
	CCoordinatesView();
	DECLARE_DYNCREATE(CCoordinatesView)

// Ư���Դϴ�.
public:
	CCoordinatesDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CCoordinatesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // CoordinatesView.cpp�� ����� ����
inline CCoordinatesDoc* CCoordinatesView::GetDocument() const
   { return reinterpret_cast<CCoordinatesDoc*>(m_pDocument); }
#endif

