
// Coordinates.h : Coordinates ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CCoordinatesApp:
// �� Ŭ������ ������ ���ؼ��� Coordinates.cpp�� �����Ͻʽÿ�.
//

class CCoordinatesApp : public CWinApp
{
public:
	CCoordinatesApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCoordinatesApp theApp;
