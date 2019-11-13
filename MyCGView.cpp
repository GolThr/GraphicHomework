// MyCGView.cpp : implementation of the CMyCGView class
//

#include "stdafx.h"
#include "MyCG.h"

#include "MyCGDoc.h"
#include "MyCGView.h"
#include "DialogDrawLine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCGView

IMPLEMENT_DYNCREATE(CMyCGView, CView)

BEGIN_MESSAGE_MAP(CMyCGView, CView)
	//{{AFX_MSG_MAP(CMyCGView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_LINE_COM1, OnLineCom1)
	ON_COMMAND(ID_LINE_DDA, OnLineDda)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCGView construction/destruction

CMyCGView::CMyCGView()
{
	// TODO: add construction code here
	m_Dragging=0;
	m_HCross=AfxGetApp()->LoadStandardCursor(IDC_CROSS);



}

CMyCGView::~CMyCGView()
{
}

BOOL CMyCGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyCGView drawing

void CMyCGView::OnDraw(CDC* pDC)
{
	CMyCGDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int Index=pDoc->GetNumLine();
	while(Index--)
		pDoc->GetLine(Index)->Draw(pDC);

}

/////////////////////////////////////////////////////////////////////////////
// CMyCGView diagnostics

#ifdef _DEBUG
void CMyCGView::AssertValid() const
{
	CView::AssertValid();

}

void CMyCGView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyCGDoc* CMyCGView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCGDoc)));
	return (CMyCGDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyCGView message handlers

void CMyCGView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_PointOld=point;
	m_PointOrigin=point;
	::SetCursor(m_HCross);
	SetCapture();
	m_Dragging=1;
	RECT Rect;
	GetClientRect(&Rect);
	ClientToScreen(&Rect);
	::ClipCursor(&Rect);


	
	CView::OnLButtonDown(nFlags, point);
}

void CMyCGView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	::SetCursor(m_HCross);
	if(m_Dragging){
	  CClientDC dc(this);
	  dc.SetROP2(R2_NOT);

	  dc.MoveTo(m_PointOrigin);
	  dc.LineTo(m_PointOld);
	  dc.MoveTo(m_PointOrigin);
	  dc.LineTo(point);
	  m_PointOld=point;

	}

	
	CView::OnMouseMove(nFlags, point);
}

void CMyCGView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	  if(m_Dragging){
		m_Dragging=0;
		::ReleaseCapture();
		::ClipCursor(NULL);

		 CClientDC dc(this);
	  dc.SetROP2(R2_NOT);

	  dc.MoveTo(m_PointOrigin);
	  dc.LineTo(m_PointOld);
	  dc.MoveTo(m_PointOrigin);
	  dc.LineTo(point);
	  m_PointOld=point;
	   dc.SetROP2(R2_COPYPEN);
	   dc.MoveTo(m_PointOrigin);
	  dc.LineTo(point);

	  ////////////////////////////
	  CMyCGDoc* pDoc = GetDocument();
	  pDoc->AddLine(m_PointOrigin.x,m_PointOrigin.y,point.x,point.y);



	  
	 

	}
	m_HCross=AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	
	CView::OnLButtonUp(nFlags, point);
}

void CMyCGView::OnLineCom1() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	dc.MoveTo(30,50);
	dc.LineTo(300,500);
	
}

void LineDDA(int x1, int y1, int x2, int y2, int color){
	int dm = 0;
	if(abs(x2 - x1) >= abs(y2 - y1)){
		dm = abs(x2 - x1);
	}else{
		dm = abs(y2 - y1);
	}
	float dx = (float)(x2 - x1) / dm;
	float dy = (float)(y2 - y1) / dm;
	float x = x1 + 0.5;
	float y = y1 + 0.5;
	for(int i = 0; i < dm; i++){
		//dc.SetPixel((int)x, (int)y, color);
		x += dx;
		y += dy;
	}
}

void CMyCGView::OnLineDda() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	int x1 = 30;
	int y1 = 50;
	int x2 = 300;
	int y2 = 500;
	int color = 0;

	DialogDrawLine dlg;
	if (dlg.DoModal() == IDOK) {
		x1 = dlg.m_startx;
		y1 = dlg.m_starty;
		x2 = dlg.m_endx;
		y2 = dlg.m_endy;
		color = dlg.m_color;
	}

	int dm = 0;
	if(abs(x2 - x1) >= abs(y2 - y1)){
		dm = abs(x2 - x1);
	}else{
		dm = abs(y2 - y1);
	}
	float dx = (float)(x2 - x1) / dm;
	float dy = (float)(y2 - y1) / dm;
	float x = x1 + 0.5;
	float y = y1 + 0.5;
	for(int i = 0; i < dm; i++){
		dc.SetPixel((int)x, (int)y, color);
		x += dx;
		y += dy;
	}
}
