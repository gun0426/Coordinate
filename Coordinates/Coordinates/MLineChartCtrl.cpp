// MLineChartCtrl.cpp : ���� �����Դϴ�.
//
#include "stdafx.h"
#include "resource.h"
#include "MLineChartCtrl.h"
#include "config.h"
#include "math.h"



extern HWND hCommWnd;



// MLineChartCtrl

IMPLEMENT_DYNAMIC(MLineChartCtrl, CWnd)

MLineChartCtrl::MLineChartCtrl()
: iGraph_i(0)
, iGraph_n(1)
, iItem_n(0)
//, m_iGrphH(0)
//, m_bLBtnDbClk(false)
//, m_bMBtnDbClk(false)
, m_iBKColor_i(0)
//, m_nViewSplit(0)
//, m_bF2Evnt(false)
, m_iViewMaxN(0)
//, m_bLClkDown(false)
//, m_nBuffer(0)
//, m_nViewPeriod(0)
//, nXDataTotal(0)
//, m_iXth(0)
, n2PiCycle(0)
, xGraph(0)
//, dblZMax(0)
, iZMulStep(0)
, iExpand(0)
{
	m_hMemBitmap = NULL;
	m_hMemDC = NULL;
}

MLineChartCtrl::~MLineChartCtrl()
{
}


BEGIN_MESSAGE_MAP(MLineChartCtrl, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MBUTTONDBLCLK()
	ON_WM_ERASEBKGND()
	ON_WM_MBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()



// MLineChartCtrl �޽��� ó�����Դϴ�.
void MLineChartCtrl::OnPaint()	// GUN_MARK
{
	CPaintDC dc(this);		// device context for painting
	HDC hDC = dc.m_hDC;

	//for (int i = 0; i< iGraph_n; i++)
	//{	
	//	for (int j = 0; j < iItem_n; j++)
	//	{
	//		int size = m_aData[i*iItem_n + j].lstData.GetSize();
	//		if (size > m_iViewMaxN)
	//		{
	//			for (int cnt = 0; cnt < size - m_iViewMaxN; cnt++)
	//			{
	//				m_aData[i * iItem_n + j].lstData.RemoveAt(0);
	//			}
	//		}
	//	}
	//}

	GetClientRect(rcGraph);
//	DrawBG(m_hMemDC);
	for (int i = 0; i < iGraph_n; i++)
	{
		iGraph_i = i;
		dblDataMax = m_aData[i*iItem_n].dblMax;
		dblDataMin = m_aData[i*iItem_n].dblMin;
		DrawChart(m_hMemDC);
	}
	/************************************************
	BOOL BitBlt(HDC hdcDest,int nXDest,int nYDest,int nWidth,int nHeight,HDC hdcSrc,int nXSrc,int nYSrc,DWORD dwRop);

	hdcDest	: �̹����� ����� ��ġ�� �ڵ�
	nXDest	: �̹����� ����� ��ġ x ��ǥ
	nYDest	: �̹����� ����� ��ġ y ��ǥ
	nWidth	: �� ũ�⸸ŭ ���� �̹������� �߶�� �׸�
	nHeight	: �� ũ�⸸ŭ ���� �̹������� �߶�� �׸�
	hdcSrc	: �̹����� �ڵ�
	nXSrc	: ������ �̹����� ��������(x)
	nYSrc	: ������ �̹����� ��������(y)
	dwRop	: �̹����� ��� ���(dwRop)


	BOOL StretchBlt(HDC hdcDest,int nXOriginDest,int nYOriginDest,int nWidthDest,int nHeightDest,HDC hdcSrc,int nXOriginSrc,int nYOriginSrc,int nWidthSrc,int nHeightSrc,DWORD dwRop);

	hdcDest			: �̹����� ����� ��ġ�� �ڵ��Դϴ�.
	nXOriginDest	: �̹����� ����� ��ġ�� x��ǥ�Դϴ�.
	nYOriginDest	: �̹����� ����� ��ġ�� y��ǥ�Դϴ�.
	nWidthDest		: ����� �̹����� �ʺ� - �� ũ�⸸ŭ hdcSrc�κ��� ���� �̹����� �� �ʺ�� ���̿� �°� �̹��� ũ�⸦ �����մϴ�.
	nHeightDest		: ����� �̹����� ���� - �� ũ�⸸ŭ hdcSrc�κ��� ���� �̹����� �� �ʺ�� ���̿� �°� �̹��� ũ�⸦ �����մϴ�
	hdcSrc			: �̹����� �ڵ��Դϴ�.
	nXOriginSrc		: ������ �̹����� ���������� x��ǥ�Դϴ�.- ������ ��ġ���� nWidthSrc, nHeightSrc��ŭ �̹����� �߶�ɴϴ�.
	nYOriginSrc		: ������ �̹����� ���������� y��ǥ�Դϴ�.- ������ ��ġ���� nWidthSrc, nHeightSrc��ŭ �̹����� �߶�ɴϴ�.
	nWidthSrc		: ���� �̹����κ��� �ش� ũ�⸸ŭ �߶� �̹����� �ʺ�
	nHeightSrc		: ���� �̹����κ��� �ش� ũ�⸸ŭ �߶� �̹����� ����
	dwRop			: �̹����� ��� ����Դϴ�.

		************************************************/
	////if (m_nViewSplit == 0)
	{
		BitBlt(hDC, rcGraph.left, rcGraph.top, rcGraph.Width(), rcGraph.Height(), m_hMemDC, rcGraph.left, rcGraph.top, SRCCOPY);
	}
	////else
	////{
	////	int x_start = (int)(rcData.left + (rcData.Width()*(double)m_nViewSplit*(1.0f / SPLIT_N)));
	////	BitBlt(hDC, x_start, 0, rcData.right - x_start, rcGraph.Height(), m_hMemDC, x_start, 0, SRCCOPY);
	////}
	//StretchBlt(hDC, 50, 0, rcGraph.Width()-(stt_n-100), rcGraph.Height(), m_hMemDC, 50, 0, rcGraph.Width()-50, rcGraph.Height(), SRCCOPY);
}

void MLineChartCtrl::DrawChart(HDC hDC)
{
	static int iCnt = 0;

	// CREATE FONT
	HFONT hFont, hOldFont;
	LOGFONT lf;
	memset(&lf, 0, sizeof(lf));
	//strcpy_s(lf.lfFaceName, "Verdana");
	strcpy_s(lf.lfFaceName, "Consolas");
	lf.lfHeight = 15;
	hFont = CreateFontIndirect(&lf);
	hOldFont = (HFONT)SelectObject(hDC, hFont);


	SetTextColor(hDC, m_ChartConfig.crText);
	SetBkColor(hDC, m_ChartConfig.crTextBG);

	CalcDataRect();
	CalcAxis();

	DrawBG(hDC);
	DrawAxisX(hDC);
	DrawAxisY(hDC);
	DrawAxisLine(hDC);
	DrawData(hDC);
//	DrawMouseData(hDC);

	SelectObject(hDC, hOldFont);
	DeleteObject(hFont);
}

void MLineChartCtrl::CalcDataRect()
{
	// CALC DATA RECT
	int height		= rcGraph.Height() / iGraph_n;
	rcData.left		= rcGraph.left			+ m_ChartConfig.iMargLeft;
	rcData.right	= rcGraph.right			- m_ChartConfig.iMargRight;
	rcData.top		= height*iGraph_i		+ m_ChartConfig.iMargTop;
	rcData.bottom	= height*(iGraph_i + 1) - m_ChartConfig.iMargBottom;
//	rcData.left		+= rcData.bottom		- rcData.top;	/////
}

void MLineChartCtrl::CalcAxis()
{
	// X�� ���	
	nXDataSize = m_aData[iGraph_i * iItem_n].lstData.GetSize();

	dblYIntv = rcData.Height() /(iExpand % 20 + 20);		// $GUN : 20 ~ 69
	dblXIntv = dblYIntv;


	int step = (iExpand / 20) - 50;

	dblAxisScale = 1.0;
	if (step == 0)
	{

	}
	else if (step < 0)
	{
		switch (abs(step) % 3)
		{
			case 0:
				dblAxisScale = 1.0;
				break;
			case 1:
				dblAxisScale = 0.5;
				break;
			case 2:
				dblAxisScale = 0.2;
				break;
		}
		dblAxisScale *= pow((double)10, step / 3);
	}
	else
	{
		switch (step%3)
		{
			case 0:
				dblAxisScale = 1;
				break;
			case 1:
				dblAxisScale = 2;
				break;
			case 2:
				dblAxisScale = 5;
				break;
		}	
		dblAxisScale *= pow((double)10, step/3);
	}


	// Y�� ���
	for (int i = 0; i<iItem_n; i++)
	{
		if (m_aData[iGraph_i*iItem_n + i].dblMax > dblDataMax)
		{
			dblDataMax = m_aData[iGraph_i*iItem_n + i].dblMax;
		}
		if (m_aData[iGraph_i*iItem_n + i].dblMin < dblDataMin)
		{
			dblDataMin = m_aData[iGraph_i*iItem_n + i].dblMin;
		}
	}
	dblYCenter		= (dblDataMax + dblDataMin) / 2;
	dblDataDiff		= (dblDataMax - dblDataMin);
	dblYMin			= (dblDataMin - dblDataDiff*.05);	// Min, Max ���� �� �� ���� ������ �� �� �ֵ��� �Ѵ�. 
	dblYMax			= (dblDataMax + dblDataDiff*.05);	
	dblDataDiff		= (dblYMax - dblYMin);	
	dblYPixelSize	= rcData.Height() / dblDataDiff;
}

void MLineChartCtrl::DrawBG(HDC hDC)
{
	HBRUSH hBrush = CreateSolidBrush(m_ChartConfig.crBG);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	FillRect(hDC, rcGraph, hBrush);

	SelectObject(hDC, hOldBrush);
	DeleteObject(hBrush);
}

void MLineChartCtrl::DrawAxisLine(HDC hDC)
{
	// DRAW AXIS LINE	
	HPEN hAxisLine = CreatePen(PS_SOLID, 1, m_ChartConfig.crAxis);
	HPEN hOldPen = (HPEN)SelectObject(hDC, hAxisLine);
//	HBRUSH hBrush = CreateSolidBrush(RGB(30, 30, 30));
//	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	MoveToEx(hDC, rcData.left, rcData.CenterPoint().y, NULL);
	LineTo(hDC, rcData.right, rcData.CenterPoint().y);
	MoveToEx(hDC, rcData.CenterPoint().x, rcData.bottom, NULL);
	LineTo(hDC, rcData.CenterPoint().x, rcData.top);
	
	SelectObject(hDC, hOldPen);
//	SelectObject(hDC, hOldBrush);
	DeleteObject(hAxisLine);
//	DeleteObject(hBrush);
}

void MLineChartCtrl::DrawAxisX(HDC hDC)
{
	HPEN hGuideLine1 = CreatePen(PS_SOLID, 1, m_ChartConfig.crGuideLine1);
	HPEN hGuideLine2 = CreatePen(PS_DOT, 1, m_ChartConfig.crGuideLine2);
	HPEN hOldPen = (HPEN)SelectObject(hDC, hGuideLine1);

	CString szText;
	SIZE size;

	int nIntv = rcData.Width()*iExpand / rcData.Height();
	for (int i = 0; i < nIntv/2; i++)
	{
		if (i % 5 == 0)
		{
			hOldPen = (HPEN)SelectObject(hDC, hGuideLine1);
		}
		else
		{
			hOldPen = (HPEN)SelectObject(hDC, hGuideLine2);
		}

		MoveToEx(hDC, (int)(rcData.CenterPoint().x + dblXIntv*i), rcData.top, NULL);
		LineTo(hDC, (int)(rcData.CenterPoint().x + dblXIntv*i), rcData.bottom);
		if (i % 5 == 0)
		{
			if ((dblAxisScale - (int)dblAxisScale == 0))
			{
				szText.Format("%d", i/5*(int)dblAxisScale);
			}
			else
			{
				szText.Format("%.2f", i/5*dblAxisScale);
			}
			TextOut(hDC, (int)(rcData.CenterPoint().x + dblXIntv*i + 3), (int)rcData.CenterPoint().y + 3, szText, szText.GetLength());
			GetTextExtentPoint32(hDC, szText, szText.GetLength(), &size);
		}

		MoveToEx(hDC, (int)(rcData.CenterPoint().x - dblXIntv*i), rcData.top, NULL);
		LineTo(hDC, (int)(rcData.CenterPoint().x - dblXIntv*i), rcData.bottom);
		if (i % 5 == 0)
		{
			if ((dblAxisScale - (int)dblAxisScale == 0))
			{
				szText.Format("%d", i/5*(int)dblAxisScale);
			}
			else
			{
				szText.Format("%.2f", i/5*dblAxisScale);
			}
			TextOut(hDC, (int)(rcData.CenterPoint().x - dblXIntv*i + 3), (int)rcData.CenterPoint().y + 3, szText, szText.GetLength());
			GetTextExtentPoint32(hDC, szText, szText.GetLength(), &size);
		}

		if (((int)(rcData.CenterPoint().x + dblXIntv*i) > rcData.right) && ((int)(rcData.CenterPoint().x - dblXIntv*i) < rcData.left))
		{
			break;
		}
	}
	SelectObject(hDC, hOldPen);
	DeleteObject(hGuideLine1);
	DeleteObject(hGuideLine2);

	return;
}

void MLineChartCtrl::DrawAxisY(HDC hDC)
{
	HPEN hGuideLine1 = CreatePen(PS_SOLID, 1, m_ChartConfig.crGuideLine1);
	HPEN hGuideLine2 = CreatePen(PS_DOT, 1, m_ChartConfig.crGuideLine2);
	HPEN hOldPen = (HPEN)SelectObject(hDC, hGuideLine1);
	CString szText;
	SIZE size;

	for (int i = 0; i < iExpand/2; i++)
	{
		if (i % 5 == 0)
		{
			hOldPen = (HPEN)SelectObject(hDC, hGuideLine1);
		}
		else
		{
			hOldPen = (HPEN)SelectObject(hDC, hGuideLine2);
		}
		MoveToEx(hDC, rcData.left, (int)(rcData.CenterPoint().y - dblYIntv*i), NULL);
		LineTo(hDC, rcData.right, (int)(rcData.CenterPoint().y - dblYIntv*i));
		if (i % 5 == 0)
		{
			if ((dblAxisScale - (int)dblAxisScale == 0))
			{
				szText.Format("%d", i / 5 * (int)dblAxisScale);
			}
			else
			{
				szText.Format("%.2f", i / 5 * dblAxisScale);
			}
			TextOut(hDC, (int)rcData.CenterPoint().x + 3, (int)(rcData.CenterPoint().y - dblYIntv*i+3), szText, szText.GetLength());
			GetTextExtentPoint32(hDC, szText, szText.GetLength(), &size);
		}

		MoveToEx(hDC, rcData.left, (int)(rcData.CenterPoint().y + dblYIntv*i), NULL);
		LineTo(hDC, rcData.right, (int)(rcData.CenterPoint().y + dblYIntv*i));
		if (i % 5 == 0)
		{
			if ((dblAxisScale - (int)dblAxisScale == 0))
			{
				szText.Format("%d", i / 5 * (int)dblAxisScale);
			}
			else
			{
				szText.Format("%.2f", i / 5 * dblAxisScale);
			}
			TextOut(hDC, (int)rcData.CenterPoint().x + 3, (int)(rcData.CenterPoint().y + dblYIntv*i+3), szText, szText.GetLength());
			GetTextExtentPoint32(hDC, szText, szText.GetLength(), &size);
		}

		if (((int)(rcData.CenterPoint().y - dblYIntv*i) < rcData.top) && ((int)(rcData.CenterPoint().y + dblYIntv*i) > rcData.bottom))
		{
			break;
		}
	}

	SelectObject(hDC, hOldPen);
	DeleteObject(hGuideLine1);
	DeleteObject(hGuideLine2);
}
void MLineChartCtrl::DrawData(HDC hDC)
{
	// DRAW DATA
	int x, y;
//	int cx;
	int tx[10], ty[10];
	CString szText;
	HPEN hLinePen;
	HPEN hOldPen;
//	HBRUSH hBrush;
//	HBRUSH hOldBrush;

	static int cnt = 0;
	 
	for (int item_i = 0; item_i < iItem_n; item_i++)
	{
		hLinePen = CreatePen(PS_SOLID, 1, m_ChartConfig.crDataLine[item_i]);
		hOldPen = (HPEN)SelectObject(hDC, hLinePen);

		for (int i = 0; i < nXDataSize; i++)
		{
			double dataY1 = m_aData[iGraph_i * iItem_n + item_i].lstData.GetAt(i)->dOrigin;
			double dataY2 = m_aData[iGraph_i * iItem_n + item_i].lstData.GetAt(i)->dDest;
			
			//MoveToEx(hDC, rcData.CenterPoint().x, rcData.CenterPoint().y, NULL);
			//LineTo(hDC, x, y);

			x = rcData.CenterPoint().x + (int)(dataY1 * dblXIntv * 5 * (int)dblAxisScale);
			y = rcData.CenterPoint().y - (int)(dataY2 * dblYIntv * 5 * (int)dblAxisScale);
			DrawDotRect(hDC, x, y, 3, 3);
			
			//if (i == 0)
			//{
			//	x = rcData.CenterPoint().x;
			//	y = rcData.CenterPoint().y;
			//} 
			//else 
			//{
			//	x = rcData.CenterPoint().x + (int)(dataY1 * dblXIntv);
			//	y = rcData.CenterPoint().y - (int)(dataY2 * dblYIntv);
			//}
			//
			////if (bSP == TRUE)
			////{				
			////}
			//
			//if (i == 0)		// ù ����Ÿ
			//{
			//	MoveToEx(hDC, x, y, NULL);
			//	x = rcData.CenterPoint().x + (int)(dataY1 * dblXIntv);
			//	y = rcData.CenterPoint().y - (int)(dataY2 * dblYIntv);
			//	LineTo(hDC, x, y);
			//}
			//else			// ������ ����Ÿ  
			//{		
			//	SetPixelV(hDC, x, y, m_ChartConfig.crDataLine[item_i]);
			//}
			//
			//if (i == nXDataSize - 1)	// ������ ����Ÿ 
			//{
			//	DrawDotRect(hDC, x, y, 3, 3);
			//
			//	double lastData = dataY1;
			//	//DrawDotRect(hDC, x, y, 3, 3);
			//	tx[item_i] = x;
			//	ty[item_i] = y;
			//	if (item_i == iItem_n - 1)
			//	{
			//		switch (iZMulStep)
			//		{
			//			case 1:
			//			case 5:
			//				break;
			//			case 2:
			//			case 3:
			//			case 4:
			//			case 6:
			//			case 7:
			//			case 8:
			//				/* �ﰢ�� */
			//				//HBRUSH hBrush = CreateSolidBrush(RGB(0x00, 0xff, 0xff));
			//				//HBRUSH hOldBrush;
			//				//hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
			//				//POINT arr[] = { rcData.CenterPoint().x, rcData.CenterPoint().y, tx[4], ty[4], tx[5], ty[5] };
			//				//Polygon(hDC, arr, 3);
			//				//SelectObject(hDC, hOldBrush);
			//				/* �ﰢ�� */
			//				BeginPath(hDC);
			//				MoveToEx(hDC, rcData.CenterPoint().x, rcData.CenterPoint().y, NULL);
			//				LineTo(hDC, tx[4], ty[4]);
			//				LineTo(hDC, tx[5], ty[5]);
			//				LineTo(hDC, rcData.CenterPoint().x, rcData.CenterPoint().y);
			//				EndPath(hDC);
			//				StrokeAndFillPath(hDC);
			//				break;
			//		}
			//	}
			//	MoveToEx(hDC, rcData.CenterPoint().x, rcData.CenterPoint().y, NULL);
			//	LineTo(hDC, x, y);
			//	szText.Format("(%.1f/%.1f)", dataY1, dataY2);
			//	TextOut(hDC, x + 10, y - 10, szText, szText.GetLength());
			//}
		}
		
		SelectObject(hDC, hOldPen);
		DeleteObject(hLinePen);
	}
}

void MLineChartCtrl::DrawMouseData(HDC hDC)
{
	if ((m_Mouse.x >= rcData.left + 5) && (m_Mouse.x <= rcData.right - 5) && \
		(m_Mouse.y >= rcData.top + 5) && (m_Mouse.y <= rcData.bottom - 5))		// ǥ�ÿ��� ����
	{
		if (m_iBKColor_i == 0)
		{
			SetTextColor(hDC, RGB(255, 255, 255));		// dc.SetTextColor(RGB(0, 0, 0)); �� ��
			SetBkColor(hDC, RGB(30, 30, 30));			// dc.SetBkColor(RGB(255, 255, 255)); �� ��
		}
		else if (m_iBKColor_i == 1)
		{
			SetTextColor(hDC, RGB(0, 0, 0));
			SetBkColor(hDC, RGB(255, 255, 255));
		}
		else if (m_iBKColor_i == 2)
		{
			SetTextColor(hDC, RGB(255, 255, 255));
			SetBkColor(hDC, RGB(140, 170, 230));
		}

		int height = rcData.bottom - rcData.top;
		int pos_y = rcData.bottom - m_Mouse.y;
		int width = rcData.right - rcData.left;
		int pos_x = m_Mouse.x - rcData.left;
		double MaxMin = dblYMax - dblYMin;
		double dYData = dblYMin + ((pos_y*MaxMin) / height);
		double dXData;
		CString str;

		
		//if (xGraph == 0)
		//{
		//	dXData = 2.0 * (double)(nXDataSize) / (double)n2PiCycle;
		//	dXData = dXData * pos_x / width;
		//	double offset;
		//	offset = 2.0 * (double)((nXDataTotal - nXDataSize) + 0) / (double)n2PiCycle;
		//	dXData += offset;
		//	str.Format("%.2f/%.2f", dXData, dYData);	// ��ǥ���
		//}
		//else if (xGraph == 1)
		//{
		//	dXData = nXDataSize * pos_x / width;
		//	str.Format("%d/%.4f", (int)dXData, dYData);	// ��ǥ���
		//}
		//else if (xGraph == 2)
		//{
		//	dXData = nXDataSize * 0.01 * pos_x / width;
		//	str.Format("%.2f/%.4f", dXData, dYData);	// ��ǥ���
		//}
		//else if (xGraph == 3)
		////{
		////	dXData = (dblZMax * 2) * (double)pos_x / (double)width - dblZMax;
		////	dYData = (dblZMax * 2) * (double)pos_y / (double)width - dblZMax;
		////	str.Format("%.2f/%.4f", dXData, dYData);	// ��ǥ���
		////}
		//else if (xGraph == 4)
		//{
		//	dXData = (dblZMax * 2) * (double)pos_x / (double)width - dblZMax;
		//	dYData = (dblZMax * 2) * (double)pos_y / (double)width - dblZMax;
		//	str.Format("%.2f/%.4f", dXData, dYData);	// ��ǥ���
		//}

		//if (m_bLClkDown == TRUE)
		//{
		//	m_dBaseLev[iGraph_i] = d_value;
		//	m_bLClkDown = FALSE;
		//}
		//dYData -= m_dBaseLev[iGraph_i];	

		TextOut(hDC, m_Mouse.x + 10, m_Mouse.y - 20, str, str.GetLength());	// dc.TextOut(m_Mouse.x, m_Mouse.y - 20, str); �� ��


		HPEN hDotPen;
		if (m_iBKColor_i == 0)		{ hDotPen = CreatePen(PS_DOT, 1, RGB(255, 255, 0)); }
		else if (m_iBKColor_i == 1)	{ hDotPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0)); }
		else if (m_iBKColor_i == 2)	{ hDotPen = CreatePen(PS_DOT, 1, RGB(255, 255, 255)); }
		else						{ hDotPen = CreatePen(PS_DOT, 1, RGB(255, 255, 255)); }
		HPEN hOldPen = (HPEN)SelectObject(hDC, hDotPen);
		MoveToEx(hDC, 50, m_Mouse.y, NULL);
		LineTo(hDC, rcData.right, m_Mouse.y);
		MoveToEx(hDC, m_Mouse.x, rcData.top, NULL);
		LineTo(hDC, m_Mouse.x, rcData.bottom);

		SelectObject(hDC, hOldPen);
		DeleteObject(hDotPen);
	}
}

void MLineChartCtrl::DrawDotRect(HDC hDC, int x, int y, int nW, int nH)
{
	Rectangle(hDC, x-nW, y-nH, x+nW, y+nH);
}

void MLineChartCtrl::OnSize(UINT nType, int cx, int cy)
{
	CreateMemResource();

	CWnd::OnSize(nType, cx, cy);
}

void MLineChartCtrl::CreateMemResource()
{
	CRect rect;
	CDC * pDC = GetDC();

	GetClientRect(rect);

	if(m_hMemDC == NULL)
		m_hMemDC = CreateCompatibleDC(pDC->m_hDC);

	if(m_hMemBitmap != NULL)
		DeleteObject(m_hMemBitmap);

	m_hMemBitmap = CreateCompatibleBitmap(pDC->m_hDC, rect.Width(), rect.Height());
	SelectObject(m_hMemDC, m_hMemBitmap);

	ReleaseDC(pDC);
}



void MLineChartCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_Mouse = point;

//	if (m_bLBtnDbClk == TRUE)
	{
		Invalidate();	// OnPaint ȣ��
	}

	CWnd::OnMouseMove(nFlags, point);
}
