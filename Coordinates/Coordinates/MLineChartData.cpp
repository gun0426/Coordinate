#include "StdAfx.h"
#include "MLineChartData.h"
#include <math.h>

MLineChartData::MLineChartData(void)
{

}

MLineChartData::~MLineChartData(void)
{
	Clear();
}

int MLineChartData::Add(double dOrigin, double dDest, bool bPrint)
{
	__ITEM* item = new __ITEM;
	item->dOrigin = dOrigin;
	item->dDest = dDest;
	item->dIntv = dOrigin - dDest;
	item->bPrint = bPrint;

	lstData.Add(item);

#if (0)
	if(lstData.GetSize() == 1)
	{
		dblMin = dblMax = item->dIntv;
	}
	else if(item->dIntv < dblMin)
	{
		dblMin = item->dIntv;
	}
	else if(item->dIntv > dblMax)
	{
		dblMax = item->dIntv;
	}
	return (int)lstData.GetSize();
#else
	if (lstData.GetSize() == 1)
	{
		dblMin = dblMax = item->dOrigin;
	}
	else if (item->dOrigin < dblMin)
	{
		dblMin = item->dOrigin;
	}
	else if (item->dOrigin > dblMax)
	{
		dblMax = item->dOrigin;
	}
	return (int)lstData.GetSize();
#endif
}

void MLineChartData::Clear()
{
	for(int i=lstData.GetSize()-1; i>=0; i--)
	{
		delete lstData.GetAt(i);
	}

	lstData.RemoveAll();
}