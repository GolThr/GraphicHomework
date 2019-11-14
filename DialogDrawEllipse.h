#pragma once


// DialogDrawEllipse 对话框

class DialogDrawEllipse : public CDialogEx
{
	DECLARE_DYNAMIC(DialogDrawEllipse)

public:
	DialogDrawEllipse(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DialogDrawEllipse();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ELLIPSE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_cenx;
	int m_ceny;
	int m_color;
	int m_rx;
	int m_ry;
};
