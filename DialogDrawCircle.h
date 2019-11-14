#pragma once


// DialogDrawCircle 对话框

class DialogDrawCircle : public CDialogEx
{
	DECLARE_DYNAMIC(DialogDrawCircle)

public:
	DialogDrawCircle(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DialogDrawCircle();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CIRCLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_cr;
	int m_cy;
	int m_ccolor;
	int m_cx;
};
