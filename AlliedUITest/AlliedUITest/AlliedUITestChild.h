#pragma once


#include "BorderCustomWnd.h"

using namespace AlliedUI;

// CAlliedUITestChild dialog

class CAlliedUITestChild : public CDialog
{
	DECLARE_DYNAMIC(CAlliedUITestChild)

public:
	CAlliedUITestChild(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAlliedUITestChild();

// Dialog Data
	enum { IDD = IDD_ALLIEDUITESTCHILD };

	virtual	void PostNcDestroy();
	virtual BOOL DestroyWindow();

	void	OnClose();

	void	SetValue(BorderColor color, BorderRadius radius, BorderStyle style, BorderWidth width);

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

	void	ResizeLayout();

	CBorderCustomWnd m_child;
	BOOL	  m_isInit;
};
