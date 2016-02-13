
// WireframeDlg.h : header file
//

#pragma once
#include "Geometry3D.h"

// CWireframeDlg dialog
class CWireframeDlg : public CDialogEx
{
// Construction
public:
	CWireframeDlg(CWnd* pParent = NULL);	// standard constructor
	~CWireframeDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WIREFRAME_DIALOG };
#endif

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

protected:
	Geometry3D* _3DGeometryHelper;
	vector<Point3D> _houseCoords;
public:
	BOOL CWireframeDlg::PreTranslateMessage(MSG* pMsg);
};
