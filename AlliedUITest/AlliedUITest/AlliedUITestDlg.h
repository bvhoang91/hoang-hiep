
// AlliedUITestDlg.h : header file
//

#pragma once

#include "BorderCustomWnd.h"
#include "AlliedUITestChild.h"

using namespace AlliedUI;

// CAlliedUITestDlg dialog
class CAlliedUITestDlg : public CDialogEx
{
// Construction
public:
	CAlliedUITestDlg(CWnd* pParent = NULL);	// standard constructor
	
	CButton m_okBtn;

	CEdit	m_editTopColor;
	CEdit	m_editLeftColor;
	CEdit	m_editRightColor;
	CEdit	m_editBottomColor;

	CEdit	m_editTopWidth;
	CEdit	m_editLeftWidth;
	CEdit	m_editRightWidth;
	CEdit	m_editBottomWidth;

	CEdit	m_editTLRadius;
	CEdit	m_editTRRadius;
	CEdit	m_editBLRadius;
	CEdit	m_editBRRadius;


	CEdit	m_editTopStyle;
	CEdit	m_editLeftStyle;
	CEdit	m_editRightStyle;
	CEdit	m_editBottomStyle;

	CStatic m_static1;
	CStatic m_static2;
	CStatic m_static3;
	CStatic m_static4;
	CStatic m_static5;
	CStatic m_static6;
	CStatic m_static7;
	CStatic m_static8;
	CStatic m_static9;
	CStatic m_static10;
	CStatic m_static11;
	CStatic m_static12;
	CStatic m_static13;
	CStatic m_static14;
	CStatic m_static15;
	CStatic m_static16;
	CStatic m_static17;
	CStatic m_static18;
	CStatic m_static19;
	CStatic m_static20;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALLIEDUITEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	void	ResizeLayout();

	void	ShowChildWindow(int iCmd);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreateChild();
	DECLARE_MESSAGE_MAP()

	CBorderCustomWnd m_child1, m_child2, m_child3, m_child4, m_child5, m_child6, m_child7, m_child8;
	BOOL	  m_isInit;
};
