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
	ON_COMMAND(ID_LINE_PERP, &CMyCGView::OnLinePerp)
	ON_COMMAND(ID_LINE_BRESENHAM, &CMyCGView::OnLineBresenham)
	ON_COMMAND(ID_LINE_MIDP, &CMyCGView::OnLineMidp)
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
	// 数值微分法
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
}


void CMyCGView::OnLinePerp()
{
	// TODO: 逐点比较法
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

		int x, y, xA, yA;
		if (y1 > y2) {
			yA = y1 - y2;
			xA = x1 - x2;
		} else {
			yA = y2 - y1;
			xA = x2 - x1;
		}
		int F = x = y = 0;
		int n = abs(xA) + abs(yA);
		for (int i = 0; i < n; i++) {
			if (xA > 0) {
				if (F >= 0) {
					x++;
					F -= yA;
				} else {
					y++;
					F += xA;
				}
			} else {
				if (F >= 0) {
					y++;
					F += xA;
				} else {
					x--;
					F += yA;
				}
			}
			if (y1 > y2) {
				dc.SetPixel(x + x2, y + y2, color);
			} else {
				dc.SetPixel(x + x1, y + y1, color);
			}
		}
	}
}

void swap_value(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void CMyCGView::OnLineBresenham()
{
	// TODO: Bresenham画线法
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

		dc.SetPixel(x1, y1, color);
		int dx = abs(x2 - x1);
		int dy = abs(y2 - y1);
		if (dx == 0 && dy == 0) {
			return;
		}
		int flag = 0;
		if (dx < dy) {
			flag = 1;
			swap_value(&x1, &y1);
			swap_value(&x2, &y2);
			swap_value(&dx, &dy);
		}
		int tx = (x2 - x1) > 0 ? 1 : -1;
		int ty = (y2 - y1) > 0 ? 1 : -1;
		int curx = x1 + 1;
		int cury = y1;
		int dS = 2 * dy;
		int dT = 2 * (dy - dx);
		int d = dS - dx;
		while (curx != x2) {
			if (d < 0) {
				d += dS;
			} else {
				cury += ty;
				d += dT;
			}
			if (flag) {
				dc.SetPixel(cury, curx, color);
			} else {
				dc.SetPixel(curx, cury, color);
			}
			curx += tx;
		}
	}
}


void CMyCGView::OnLineMidp()
{
	// TODO: 中点画线法
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

		int a, b, d, x, y, tag = 0;
		if (abs(x2 - x1) < abs(y2 - y1)) {
			swap_value(&x1, &y1);
			swap_value(&x2, &y2);
			tag = 1;
		}
		if (x1 > x2) {
			swap_value(&x1, &x2);
			swap_value(&y1, &y2);
		}
		a = y1 - y2;
		b = x2 - x1;
		d = a + b / 2;
		if (y1 < y2) {
			x = x1;
			y = y1;
			dc.SetPixel(x, y, 255);
			while (x < x2) {
				if (d < 0) {
					x++;
					y++;
					d = d + a + b;
				} else {
					x++;
					d += a;
				}
				if (tag) {
					dc.SetPixel(y, x, color);
				} else {
					dc.SetPixel(x, y, color);
				}
			}
		} else {
			x = x2;
			y = y2;
			dc.SetPixel(x, y, 255);
			while (x > x1) {
				if (d < 0) {
					x--;
					y++;
					d = d - a + b;
				} else {
					x--;
					d -= a;
				}
				if (tag) {
					dc.SetPixel(y, x, color);
				}
				else {
					dc.SetPixel(x, y, color);
				}
			}
		}
	}
}
