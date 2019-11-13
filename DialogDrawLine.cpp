// DialogDrawLine.cpp: 实现文件
//

#include "stdafx.h"
#include "MyCG.h"
#include "DialogDrawLine.h"
#include "afxdialogex.h"


// DialogDrawLine 对话框

IMPLEMENT_DYNAMIC(DialogDrawLine, CDialogEx)

DialogDrawLine::DialogDrawLine(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LINE, pParent)
	, m_endx(0)
	, m_endy(0)
	, m_startx(0)
	, m_starty(0)
	, m_color(0)
{

}

DialogDrawLine::~DialogDrawLine()
{
}

void DialogDrawLine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT_ENDX, m_endx);
	//  DDX_Control(pDX, IDC_EDIT_ENDX, m_endx);
	//  DDX_Control(pDX, IDC_EDIT_ENDY, m_endy);
	//  DDX_Text(pDX, IDC_EDIT_LINECOLOR, color);
	DDX_Text(pDX, IDC_EDIT_ENDX, m_endx);
	DDX_Text(pDX, IDC_EDIT_ENDY, m_endy);
	DDX_Text(pDX, IDC_EDIT_STARTX, m_startx);
	DDX_Text(pDX, IDC_EDIT_STARTY, m_starty);
	DDX_Text(pDX, IDC_EDIT_LINECOLOR, m_color);
}


BEGIN_MESSAGE_MAP(DialogDrawLine, CDialogEx)
END_MESSAGE_MAP()


// DialogDrawLine 消息处理程序
