
// WireframeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Wireframe.h"
#include "WireframeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWireframeDlg dialog


CWireframeDlg::CWireframeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WIREFRAME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWireframeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWireframeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CWireframeDlg message handlers

BOOL CWireframeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	CRect *rect = new CRect();
	GetWindowRect(rect);

	_3DGeometryHelper = new Geometry3D(rect->Height()/2, rect->Width()/2);
	_3DGeometryHelper->CalculateUVector(100, 0, 20);
	_3DGeometryHelper->ApplyAllFuncs(20, 50, -500);

	delete rect;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWireframeDlg::OnPaint()
{
	CPaintDC dc(this); 
	
	CPen *pen, *oldPen;
	CBrush *br, *oldBr;
	COLORREF black = RGB(0, 0, 0);
	pen = new CPen(PS_SOLID, 2, black);
	oldPen = (CPen*)dc.SelectObject(pen);
	br = new CBrush(RGB(155, 0, 0));
	oldBr = (CBrush*)dc.SelectObject(br);

	_3DGeometryHelper->Draw(&dc);
	
	dc.SelectObject(oldPen);
	dc.SelectObject(oldBr);
	delete pen;
	delete br;
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWireframeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


CWireframeDlg::~CWireframeDlg()
{
	delete _3DGeometryHelper;
}


BOOL CWireframeDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_LEFT)
		{
			_3DGeometryHelper->TranslateOnOx(5);
			Invalidate();
		}
		if (pMsg->wParam == VK_RIGHT)
		{
			_3DGeometryHelper->TranslateOnOx(-5);
			Invalidate();
		}
		if (pMsg->wParam == VK_ADD)
		{
			_3DGeometryHelper->TranslateOnOz(-5);
			Invalidate();
		}
		if (pMsg->wParam == VK_SUBTRACT)
		{
			_3DGeometryHelper->TranslateOnOz(5);
			Invalidate();
		}
		if (pMsg->wParam == 0x51)
		{
			_3DGeometryHelper->RotateOnOX(-5);
			Invalidate();
		}
		if (pMsg->wParam == 0x41)
		{
			_3DGeometryHelper->RotateOnOX(5);
			Invalidate();
		}
		if (pMsg->wParam == 0x57)
		{
			_3DGeometryHelper->RotateOnOY(-5);
			Invalidate();
		}
		if (pMsg->wParam == 0x53)
		{
			_3DGeometryHelper->RotateOnOY(5);
			Invalidate();
		}
		if (pMsg->wParam == 0x45)
		{
			_3DGeometryHelper->RotateOnOZ(-5);
			Invalidate();
		}
		if (pMsg->wParam == 0x44)
		{
			_3DGeometryHelper->RotateOnOZ(5);
			Invalidate();
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}