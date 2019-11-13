// MyCGDoc.h : interface of the CMyCGDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCGDOC_H__C21C9D63_2592_4B17_9185_30A782C05DAB__INCLUDED_)
#define AFX_MYCGDOC_H__C21C9D63_2592_4B17_9185_30A782C05DAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLine : public CObject
{
protected: 
	int m_X1,m_Y1,m_X2,m_Y2;
public:
	CLine(	int X1,int Y1,int X2,int Y2){
		m_X1=X1;
		m_Y1=Y1;
		m_X2=X2;
		m_Y2=Y2;	
	}
	void Draw(CDC* pDC);



};

class CMyCGDoc : public CDocument
{
protected: // create from serialization only
	CMyCGDoc();
	DECLARE_DYNCREATE(CMyCGDoc)

// Attributes
public:

// Operations
public:
protected:
	CTypedPtrArray<CObArray, CLine*> m_LineArray;
public:
	void AddLine(int X1,int Y1,int X2, int Y2);
	CLine* GetLine(int Index);
	int GetNumLine();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCGDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyCGDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyCGDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCGDOC_H__C21C9D63_2592_4B17_9185_30A782C05DAB__INCLUDED_)
