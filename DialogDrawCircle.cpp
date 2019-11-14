// DialogDrawCircle.cpp: 实现文件
//

#include "stdafx.h"
#include "MyCG.h"
#include "DialogDrawCircle.h"
#include "afxdialogex.h"


// DialogDrawCircle 对话框

IMPLEMENT_DYNAMIC(DialogDrawCircle, CDialogEx)

DialogDrawCircle::DialogDrawCircle(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CIRCLE, pParent)
	, m_cr(0)
	, m_cy(0)
	, m_ccolor(0)
	, m_cx(0)
{

}

DialogDrawCircle::~DialogDrawCircle()
{
}

void DialogDrawCircle::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CIRCLER, m_cr);
	DDX_Text(pDX, IDC_EDIT_CIRCLEY, m_cy);
	DDX_Text(pDX, IDC_EDIT_COLOR, m_ccolor);
	DDX_Text(pDX, IDC_EDIT_CIRCLEX, m_cx);
}


BEGIN_MESSAGE_MAP(DialogDrawCircle, CDialogEx)
END_MESSAGE_MAP()


// DialogDrawCircle 消息处理程序
