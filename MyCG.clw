; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=DialogDrawLine
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyCG.h"
LastPage=0

ClassCount=6
Class1=CMyCGApp
Class2=CMyCGDoc
Class3=CMyCGView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=DialogDrawLine
Resource3=IDD_DIALOG_LINE

[CLS:CMyCGApp]
Type=0
HeaderFile=MyCG.h
ImplementationFile=MyCG.cpp
Filter=N

[CLS:CMyCGDoc]
Type=0
HeaderFile=MyCGDoc.h
ImplementationFile=MyCGDoc.cpp
Filter=N

[CLS:CMyCGView]
Type=0
HeaderFile=MyCGView.h
ImplementationFile=MyCGView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CMyCGView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=MyCG.cpp
ImplementationFile=MyCG.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_STATUS_BAR
Command12=ID_LINE_COM1
Command13=ID_LINE_DDA
Command14=ID_APP_ABOUT
CommandCount=14

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_DIALOG_LINE]
Type=1
Class=DialogDrawLine
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_EDIT_STARTX,edit,1350639744
Control7=IDC_EDIT_STARTY,edit,1350639744
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342177287
Control11=IDC_EDIT_ENDX,edit,1350639744
Control12=IDC_EDIT_ENDY,edit,1350639744
Control13=IDC_STATIC,button,1342177287
Control14=IDC_EDIT_LINECOLOR,edit,1350631552

[CLS:DialogDrawLine]
Type=0
HeaderFile=DialogDrawLine.h
ImplementationFile=DialogDrawLine.cpp
BaseClass=CDialog
Filter=D
LastObject=DialogDrawLine
VirtualFilter=dWC

