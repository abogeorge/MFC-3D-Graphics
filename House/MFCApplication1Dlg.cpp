
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers
Grafica3D casa = Grafica3D(350, 20, 1000);

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	
	casa.AdaugaPunct3D(Punct3D(100, 350, -10)); //FDJ 0
	casa.AdaugaPunct3D(Punct3D(300, 350, -10)); //FSJ 1
	casa.AdaugaPunct3D(Punct3D(300, 350, -210)); //SSJ 2
	casa.AdaugaPunct3D(Punct3D(100, 350, -210)); //SDJ 3
	casa.AdaugaPunct3D(Punct3D(100, 200, -10)); //FDS 4
	casa.AdaugaPunct3D(Punct3D(300, 200, -10)); //FSS 5
	casa.AdaugaPunct3D(Punct3D(300, 200, -210)); //SSS 6 
	casa.AdaugaPunct3D(Punct3D(100, 200, -210)); //SDS 7

	casa.AdaugaPunct3D(Punct3D(100, 200, -10)); //FDS 8
	casa.AdaugaPunct3D(Punct3D(300, 200, -10)); //FSS 9
	casa.AdaugaPunct3D(Punct3D(200, 80, -10));  // 10
	casa.AdaugaPunct3D(Punct3D(100, 200, -210)); //SDS  11
	casa.AdaugaPunct3D(Punct3D(300, 200, -210)); //SSS 12
	casa.AdaugaPunct3D(Punct3D(200, 80,  -210)); // 13

	casa.AdaugaPunct3D(Punct3D(270, 230, -10)); // 14
	casa.AdaugaPunct3D(Punct3D(240, 230, -10)); // 15
	casa.AdaugaPunct3D(Punct3D(240, 260, -10)); // 16
	casa.AdaugaPunct3D(Punct3D(270, 260, -10)); // 17

	casa.AdaugaPunct3D(Punct3D(130, 230, -10)); // 18
	casa.AdaugaPunct3D(Punct3D(160, 230, -10)); // 19
	casa.AdaugaPunct3D(Punct3D(160, 260, -10)); // 20
	casa.AdaugaPunct3D(Punct3D(130, 260, -10)); // 21

	casa.AdaugaPunct3D(Punct3D(230, 350, -10)); // 22
	casa.AdaugaPunct3D(Punct3D(230, 285, -10)); // 23
	casa.AdaugaPunct3D(Punct3D(180, 285, -10)); // 24
	casa.AdaugaPunct3D(Punct3D(180, 350, -10)); // 25

	casa.AdaugaUnire(Unire(0, 1));
	casa.AdaugaUnire(Unire(1, 2));
	casa.AdaugaUnire(Unire(2,3));
	casa.AdaugaUnire(Unire(3,0));
	casa.AdaugaUnire(Unire(0, 4));
	casa.AdaugaUnire(Unire(1,5));
	casa.AdaugaUnire(Unire(2,6));
	casa.AdaugaUnire(Unire(3,7));
	casa.AdaugaUnire(Unire(4,5));
	casa.AdaugaUnire(Unire(5,6));
	casa.AdaugaUnire(Unire(6,7));
	casa.AdaugaUnire(Unire(4,10));
	casa.AdaugaUnire(Unire(5,10));
	casa.AdaugaUnire(Unire(7,13));
	casa.AdaugaUnire(Unire(6,13));
	casa.AdaugaUnire(Unire(4,11));
	casa.AdaugaUnire(Unire(10,13));

	casa.AdaugaUnire(Unire(14, 15));
	casa.AdaugaUnire(Unire(15, 16));
	casa.AdaugaUnire(Unire(16, 17));
	casa.AdaugaUnire(Unire(17, 14));

	casa.AdaugaUnire(Unire(18, 19));
	casa.AdaugaUnire(Unire(19, 20));
	casa.AdaugaUnire(Unire(20, 21));
	casa.AdaugaUnire(Unire(21, 18));

	casa.AdaugaUnire(Unire(22, 23));
	casa.AdaugaUnire(Unire(23, 24));
	casa.AdaugaUnire(Unire(24, 25));
	//CPaintDC dc(this);
	
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CPen *pen, *oldPen;
	CBrush *br, *oldBr;
	COLORREF black = RGB(0, 0, 0);
	pen = new CPen(PS_SOLID, 2, black);
	oldPen = (CPen*)dc.SelectObject(pen);
	br = new CBrush(RGB(155, 0, 0));
	oldBr = (CBrush*)dc.SelectObject(br);
	casa.Desenare(&dc);
	
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG *p)
{
	if (p->message == WM_KEYDOWN)
	{
		if (p->wParam == VK_LEFT)
		{
			casa.translatiePeX(5);
			Invalidate();
		}
		if (p->wParam == VK_UP)
		{
			casa.translatiePeY(-5);
			Invalidate();
		}
		if (p->wParam == VK_RIGHT)
		{
			casa.translatiePeX(-5);
			Invalidate();
		}
		if (p->wParam == VK_DOWN)
		{
			casa.translatiePeY(5);
			Invalidate();
		}
		if (p->wParam == 0x51)
		{
			casa.RotatieOX(-5);
			Invalidate();
		}
		if (p->wParam == 0x41)
		{
			casa.RotatieOX(5);
			Invalidate();
		}
		if (p->wParam == 0x57)
		{
			casa.RotatieOY(-5);
			Invalidate();
		}
		if (p->wParam == 0x53)
		{
			casa.RotatieOY(5);
			Invalidate();
		}
		if (p->wParam == 0x45)
		{
			casa.RotatieOZ(-5);
			Invalidate();
		}
		if (p->wParam == 0x44)
		{
			casa.RotatieOZ(5);
			Invalidate();
		}



	}
	return CDialog::PreTranslateMessage(p);
}