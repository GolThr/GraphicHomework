// MyCGDoc.cpp : implementation of the CMyCGDoc class
//

#include "stdafx.h"
#include "MyCG.h"

#include "MyCGDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCGDoc

IMPLEMENT_DYNCREATE(CMyCGDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyCGDoc, CDocument)
	//{{AFX_MSG_MAP(CMyCGDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCGDoc construction/destruction

CMyCGDoc::CMyCGDoc()
{
	// TODO: add one-time construction code here

}

CMyCGDoc::~CMyCGDoc()
{
}

BOOL CMyCGDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyCGDoc serialization

void CMyCGDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyCGDoc diagnostics

#ifdef _DEBUG
void CMyCGDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyCGDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyCGDoc commands
void CLine ::Draw(CDC *pDC){
	pDC->MoveTo( m_X1,m_Y1);
	pDC->LineTo(m_X2,m_Y2);
}


void CMyCGDoc:: AddLine(int X1,int Y1,int X2, int Y2){
    CLine *PLine=new CLine( X1,Y1,X2, Y2);
	m_LineArray.Add(PLine);
}


CLine* CMyCGDoc::GetLine(int Index){
	if(Index<0||Index>m_LineArray.GetUpperBound())
		return 0;
    
   return m_LineArray.GetAt(Index);
}


int CMyCGDoc::GetNumLine(){
    return m_LineArray.GetSize();
  
}