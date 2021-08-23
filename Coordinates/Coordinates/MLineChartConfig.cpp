#include "StdAfx.h"
#include "MLineChartConfig.h"

MLineChartConfig::MLineChartConfig(void)
{
	nInitWidth = 10;
	nWidthExtent = 1000;

	crDot = RGB(255, 0, 0);
	crDataLine[0] = RGB(255, 0, 0);
	crDataLine[1] = RGB(0, 0, 255);
	crDataLine[2] = RGB(0, 255, 0);
	crDataLine[3] = RGB(255, 255, 0);
	crDataLine[4] = RGB(255, 0, 255);
	crDataLine[5] = RGB(0, 255, 255);
	crDataLine[6] = RGB(200, 100, 100);
	crDataLine[7] = RGB(100, 100, 200);
	crDataLine[8] = RGB(50, 100, 150);
	crDataLine[9] = RGB(150, 100, 50);

#if (1)
	crBG = RGB(30, 30, 30);
	crGuideLine1 = RGB(200, 200, 200);
	crGuideLine2 = RGB(150, 150, 150);
	crAxis = RGB(255, 255, 255);
	crText = RGB(255, 255, 255);
	crTextBG = RGB(30, 30, 30);
#else
	crBG = RGB(140, 170, 230);
	crGuideLine1 = RGB(230, 230, 230);
	crGuideLine2 = RGB(200, 200, 200);
	crAxis = RGB(255, 255, 255);
	crText = RGB(255, 255, 255);
	crTextBG = RGB(140, 170, 230);
#endif

	bShowGuideLine = FALSE;
	bShowDataLine = TRUE;

	bAxisYSensitive = TRUE;
	dblAxisYMin = 0;
	dblAxisYMax = 0;

	iMargTop = 0;		
	iMargLeft = 0;		
	iMargBottom = 0;
	iMargRight = 0;	

	szAxisXNM = "";		//"Axis X";
	szAxisYNM = "";		//"Delta ¥Ä";		// "Axis Y";
	szFormat = "%.2f";	//"%.1f";
}

MLineChartConfig::~MLineChartConfig(void)
{
}
