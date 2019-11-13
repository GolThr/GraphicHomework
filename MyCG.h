// MyCG.h : main header file for the MYCG application
//

#if !defined(AFX_MYCG_H__0A94DFFC_FF55_4985_84DE_2969C9D09314__INCLUDED_)
#define AFX_MYCG_H__0A94DFFC_FF55_4985_84DE_2969C9D09314__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyCGApp:
// See MyCG.cpp for the implementation of this class
//

class CMyCGApp : public CWinApp
{
public:
	CMyCGApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyCGApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCG_H__0A94DFFC_FF55_4985_84DE_2969C9D09314__INCLUDED_)
