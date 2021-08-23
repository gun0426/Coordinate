#pragma once

#include "MLineChartConfig.h"
#include "MLineChartData.h"
#include "config.h"


#define GRPH_CLEAR	(WM_USER +2)
#define SPLIT_N		4
#define GRID_N_0	6
#define GRID_N_1	15


// MLineChartCtrl

class MLineChartCtrl : public CWnd
{
	DECLARE_DYNAMIC(MLineChartCtrl)

public:
	MLineChartCtrl();
	virtual ~MLineChartCtrl();

public:
	MLineChartConfig m_ChartConfig;
	MLineChartData m_aData[CHART_DATA_N];
	HBITMAP m_hMemBitmap;
	HDC m_hMemDC;
	HDC m_hMemDC_cp;

	CRect rcGraph;
	CRect rcData;
	double dblXIntv, dblYIntv;
	double dblXRoom, dblYRoom;	// coin, dice
	
	double dblDataDiff, dblYCenter, dblYMin, dblYMax, dblYPixelSize;
	int nXDataSize;

public:
	void DrawChart(HDC hDC);
	void CalcDataRect();
	void CalcAxis();
	void DrawBG(HDC hDC);
	void DrawAxisLine(HDC hDC);
	void DrawAxisX(HDC hDC);
	void DrawAxisY(HDC hDC);
	void DrawData(HDC hDC);
	void DrawDotRect(HDC hDC, int x, int y, int nW, int nH);
	void CreateMemResource();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);

	CPoint m_Mouse;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	
	int iGraph_i;	// index
	int iGraph_n;	// count
	int iItem_n;	
	double dblDataMax;
	double dblDataMin;
	int m_iBKColor_i;
	int m_iViewMaxN;
	double m_dBaseLev[10];
	int n2PiCycle;
	int xGraph;
	void DrawMouseData(HDC hDC);
	int iZMulStep;
	int iExpand;
	double dblAxisScale;
};
