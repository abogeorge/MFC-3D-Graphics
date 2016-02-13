
// 3DGraficaDlg.h : header file
//

#pragma once
#include "afxtempl.h"
struct Punct3D
{
	double x,y,z;
};

struct Unire
{
	int i1,i2;
};

// CMy3DGraficaDlg dialog
class CMy3DGraficaDlg : public CDialogEx
{
// Construction
public:
	CMy3DGraficaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MY3DGRAFICA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CArray<Punct3D> vp3d;
	CArray<Unire> vu;
	CArray<CPoint> vp2d;
	Punct3D Punct3(double x, double y, double z);
	Unire Unirii(int i1, int i2);
	CPoint Pp(Punct3D p, double dx, double dy);
	double zp;
	void Translatie(double x, double y, double z, double dx, double dy, double dz, double &xp, double &yp, double &zp);
	void Scalare(double x, double y, double z, double xg, double yg, double zg, double sx, double sy, double sz, double & xs, double & ys, double & zs);
	void RotatieOX(double u);
	void RotatieOY(double u);
	void RotatieOZ(double u);

	BOOL PreTranslateMessage(MSG *p);
};
