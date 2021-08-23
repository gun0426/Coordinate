// DlgMainCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Coordinates.h"
#include "DlgMainCtrl.h"
#include "afxdialogex.h"


// CDlgMainCtrl ��ȭ �����Դϴ�.

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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


HBRUSH CDlgMainCtrl::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.
	pDC->SetBkMode(TRANSPARENT);		// ���ڻ��� ������ ��ġ�ϰ� ����

	pDC->SetTextColor(RGB(0, 0, 0));	// ���ڻ�
	
	if (nCtlColor == CTLCOLOR_STATIC)	// ���� ����ƽ
	{
		return CreateSolidBrush(RGB(140, 170, 230));
	}

	if (nCtlColor == CTLCOLOR_BTN)		// ��ư(üũ��ư/������ư)
	{
		return CreateSolidBrush(RGB(140, 170, 230));
	}

	if (nCtlColor == CTLCOLOR_EDIT)		// ��ư(üũ��ư/������ư)
	{
		return CreateSolidBrush(RGB(140, 170, 230));
	}

	if (nCtlColor == CTLCOLOR_LISTBOX)		// ��ư(üũ��ư/������ư)
	{
		return CreateSolidBrush(RGB(140, 170, 230));
	}

	if (nCtlColor == CTLCOLOR_DLG)		// ���̾�α� �ڽ� ������
	{
		//return CreateSolidBrush(RGB(140, 170, 230));
		return CreateSolidBrush(RGB(30, 30, 30));
	}

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}
