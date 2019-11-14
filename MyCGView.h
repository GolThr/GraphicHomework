// MyCGView.h : interface of the CMyCGView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCGVIEW_H__7F2345B6_5105_4653_9EBE_34272874AC06__INCLUDED_)
#define AFX_MYCGVIEW_H__7F2345B6_5105_4653_9EBE_34272874AC06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyCGView : public CView
{
protected: // create from serialization only
	CMyCGView();
	DECLARE_DYNCREATE(CMyCGView)

// Attributes
public:
	CMyCGDoc* GetDocument();

// Operations
public:
	void Cirpot(int x0, int y0, int x, int y, int color);
	void Bres_Circle(int x0, int y0, double r, int color);

protected:
	CString m_ClassName;
	int m_Dragging;
	HCURSOR m_HCross;
	CPoint m_PointOld;
	CPoint m_PointOrigin;



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCGView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyCGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyCGView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLineCom1();
	afx_msg void OnLineDda();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLinePerp();
	afx_msg void OnLineBresenham();
	afx_msg void OnLineMidp();
	afx_msg void OnCircleBresenham();
	afx_msg void OnCircleMidcircle();
};

#ifndef _DEBUG  // debug version in MyCGView.cpp
inline CMyCGDoc* CMyCGView::GetDocument()
   { return (CMyCGDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCGVIEW_H__7F2345B6_5105_4653_9EBE_34272874AC06__INCLUDED_)
