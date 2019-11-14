// DialogDrawEllipse.cpp: 实现文件
//

#include "stdafx.h"
#include "MyCG.h"
#include "DialogDrawEllipse.h"
#include "afxdialogex.h"


// DialogDrawEllipse 对话框

IMPLEMENT_DYNAMIC(DialogDrawEllipse, CDialogEx)

DialogDrawEllipse::DialogDrawEllipse(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ELLIPSE, pParent)
	, m_cenx(0)
	, m_ceny(0)
	, m_color(0)
	, m_rx(0)
	, m_ry(0)
{

}

DialogDrawEllipse::~DialogDrawEllipse()
{
}

void DialogDrawEllipse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CENTERX, m_cenx);
	DDX_Text(pDX, IDC_EDIT_CENTERY, m_ceny);
	DDX_Text(pDX, IDC_EDIT_COLOR, m_color);
	DDX_Text(pDX, IDC_EDIT_RX, m_rx);
	DDX_Text(pDX, IDC_EDIT_RY, m_ry);
}


BEGIN_MESSAGE_MAP(DialogDrawEllipse, CDialogEx)
END_MESSAGE_MAP()


// DialogDrawEllipse 消息处理程序
