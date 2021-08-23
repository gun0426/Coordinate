// DlgMainCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Coordinates.h"
#include "DlgMainCtrl.h"
#include "afxdialogex.h"


// CDlgMainCtrl 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMainCtrl, CDialog)

CDlgMainCtrl::CDlgMainCtrl(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMainCtrl::IDD, pParent)
{

}

CDlgMainCtrl::~CDlgMainCtrl()
{
}

void CDlgMainCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMainCtrl, CDialog)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgMainCtrl::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()



BOOL CDlgMainCtrl::Create(CWnd* pParentWnd)
{
	return CDialog::Create(IDD_DLG_MAINCTRL, pParentWnd);
}


void CDlgMainCtrl::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


HBRUSH CDlgMainCtrl::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	pDC->SetBkMode(TRANSPARENT);		// 글자색과 배경색이 일치하게 만듬

	pDC->SetTextColor(RGB(0, 0, 0));	// 글자색
	
	if (nCtlColor == CTLCOLOR_STATIC)	// 정적 스테틱
	{
		return CreateSolidBrush(RGB(140, 170, 230));
	}

	if (nCtlColor == CTLCOLOR_BTN)		// 버튼(체크버튼/라디오버튼)
	{
		return CreateSolidBrush(RGB(140, 170, 230));
	}

	if (nCtlColor == CTLCOLOR_EDIT)		// 버튼(체크버튼/라디오버튼)
	{
		return CreateSolidBrush(RGB(140, 170, 230));
	}

	if (nCtlColor == CTLCOLOR_LISTBOX)		// 버튼(체크버튼/라디오버튼)
	{
		return CreateSolidBrush(RGB(140, 170, 230));
	}

	if (nCtlColor == CTLCOLOR_DLG)		// 다이얼로그 박스 바탕색
	{
		//return CreateSolidBrush(RGB(140, 170, 230));
		return CreateSolidBrush(RGB(30, 30, 30));
	}

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}
