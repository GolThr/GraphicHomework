// MyCGView.cpp : implementation of the CMyCGView class
//

#include "stdafx.h"
#include "MyCG.h"

#include "MyCGDoc.h"
#include "MyCGView.h"
#include "DialogDrawLine.h"
#include "DialogDrawCircle.h"
#include "DialogDrawEllipse.h"

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
	ON_COMMAND(ID_CIRCLE_BRESENHAM, &CMyCGView::OnCircleBresenham)
	ON_COMMAND(ID_CIRCLE_MIDCIRCLE, &CMyCGView::OnCircleMidcircle)
	ON_COMMAND(ID_ELLIPSE_MIDELL, &CMyCGView::OnEllipseMidell)
	ON_COMMAND(ID_ELLIPSE_BRESENHAM, &CMyCGView::OnEllipseBresenham)
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

void CMyCGView::Cirpot(int x0, int y0, int x, int y, int color) {
	CClientDC dc(this);
	dc.SetPixel((x0 + x), (y0 + y), color);
	dc.SetPixel((x0 + y), (y0 + x), color);
	dc.SetPixel((x0 + y), (y0 - x), color);
	dc.SetPixel((x0 + x), (y0 - y), color);
	dc.SetPixel((x0 - x), (y0 - y), color);
	dc.SetPixel((x0 - y), (y0 - x), color);
	dc.SetPixel((x0 - y), (y0 + x), color);
	dc.SetPixel((x0 - x), (y0 + y), color);
}

void CMyCGView::Bres_Circle(int x0, int y0, double r, int color) {
	int x, y, d;
	x = 0;
	y = (int)r;
	d = int(3 - 2 * r);
	while (x < y) {
		Cirpot(x0, y0, x, y, color);
		if (d < 0) {
			d += 4 * x + 6;
		} else {
			d += 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
	if (x == y) {
		Cirpot(x0, y0, x, y, color);
	}
}

void CMyCGView::OnCircleBresenham()
{
	// TODO: Bresenham画圆算法
	int x0 = 30;
	int y0 = 50;
	double r = 30;
	int color = 0;

	DialogDrawCircle dlg;
	if (dlg.DoModal() == IDOK) {
		x0 = dlg.m_cx;
		y0 = dlg.m_cy;
		r = dlg.m_cr;
		color = dlg.m_ccolor;

		Bres_Circle(x0, y0, r, color);
	}
}


void CMyCGView::OnCircleMidcircle()
{
	// TODO: 中点画圆算法
	int x0 = 30;
	int y0 = 50;
	int r = 30;
	int color = 0;

	DialogDrawCircle dlg;
	if (dlg.DoModal() == IDOK) {
		x0 = dlg.m_cx;
		y0 = dlg.m_cy;
		r = dlg.m_cr;
		color = dlg.m_ccolor;

		int x = 0;
		int y = r;
		int d = 1 - r;
		Cirpot(x0, y0, x, y, color);
		while (x < y) {
			if (d < 0) {
				d += 2 * x + 3;
			} else {
				d += 2 * (x - y) + 5;
				y--;
			}
			x++;
			Cirpot(x0, y0, x, y, color);
		}
	}
}

inline int Round(const float a) { return static_cast<int>(a + 0.5); }

void CMyCGView::ellipsePlotPoints(int xCenter, int yCenter, int x, int y, int color) {
	CClientDC dc(this);
	dc.SetPixel(xCenter + x, yCenter + y, color);
	dc.SetPixel(xCenter - x, yCenter + y, color);
	dc.SetPixel(xCenter + x, yCenter - y, color);
	dc.SetPixel(xCenter - x, yCenter - y, color);
}

void CMyCGView::OnEllipseMidell()
{
	// TODO: 中点椭圆算法
	int xCenter = 100;
	int yCenter = 100;
	int Rx = 50;
	int Ry = 30;
	int color = 0;

	DialogDrawEllipse dlg;
	if (dlg.DoModal() == IDOK) {
		xCenter = dlg.m_cenx;
		yCenter = dlg.m_ceny;
		Rx = dlg.m_rx;
		Ry = dlg.m_ry;
		color = dlg.m_color;

		int Rx2 = Rx * Rx;
		int Ry2 = Ry * Ry;
		int twoRx2 = 2 * Rx2;
		int twoRy2 = 2 * Ry2;
		int p;
		int x = 0;
		int y = Ry;
		int px = 0;
		int py = twoRx2 * y;
		// Plot the initial point in each quadrant
		ellipsePlotPoints(xCenter, yCenter, x, y, color);
		/* Region 1 */
		p = Round(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
		while (px < py) {
			x++;
			px += twoRy2;
			if (p < 0) {
				p += Ry2 + px;
			}
			else {
				y--;
				py -= twoRx2;
				p += Ry2 + px - py;
			}
			ellipsePlotPoints(xCenter, yCenter, x, y, color);
		}
		/* Region 2 */
		p = Round(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
		while (y > 0) {
			y--;
			py -= twoRx2;
			if (p > 0) {
				p += Rx2 - py;
			}
			else {
				x++;
				px += twoRx2;
				p += Rx2 - py + px;
			}
			ellipsePlotPoints(xCenter, yCenter, x, y, color);
		}
	}
}


void CMyCGView::OnEllipseBresenham()
{
	// TODO: Bresenham画椭圆算法
	int xc = 100;
	int yc = 100;
	int a = 50;
	int b = 30;
	int color = 0;

	DialogDrawEllipse dlg;
	if (dlg.DoModal() == IDOK) {
		xc = dlg.m_cenx;
		yc = dlg.m_ceny;
		a = dlg.m_rx;
		b = dlg.m_ry;
		color = dlg.m_color;

		int sqa = a * a;
		int sqb = b * b;
		int x = 0;
		int y = b;
		int d = 2 * sqb - 2 * b * sqa + sqa;
		ellipsePlotPoints(xc, yc, x, y, color);
		int P_x = Round((double)sqa / sqrt((double)(sqa + sqb)));
		while (x <= P_x) {
			if (d < 0) {
				d += 2 * sqb * (2 * x + 3);
			}
			else {
				d += 2 * sqb * (2 * x + 3) - 4 * sqa * (y - 1);
				y--;
			}
			x++;
			ellipsePlotPoints(xc, yc, x, y, color);
		}
		d = sqb * (x * x + x) + sqa * (y * y - y) - sqa * sqb;
		while (y >= 0) {
			ellipsePlotPoints(xc, yc, x, y, color);
			y--;
			if (d < 0) {
				x++;
				d = d - 2 * sqa * y - sqa + 2 * sqb * x + 2 * sqb;
			}
			else {
				d = d - 2 * sqa * y - sqa;
			}
		}
	}
}
