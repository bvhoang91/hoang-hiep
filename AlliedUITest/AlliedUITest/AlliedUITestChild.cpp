// AlliedUITestChild.cpp : implementation file
//

#include "stdafx.h"
#include "AlliedUITest.h"
#include "AlliedUITestChild.h"
#include "afxdialogex.h"


// CAlliedUITestChild dialog

IMPLEMENT_DYNAMIC(CAlliedUITestChild, CDialog)

CAlliedUITestChild::CAlliedUITestChild(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ALLIEDUITESTCHILD, pParent)
{
	m_isInit = FALSE;
}

CAlliedUITestChild::~CAlliedUITestChild()
{
}

void CAlliedUITestChild::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}

BOOL CAlliedUITestChild::DestroyWindow()
{
	return CDialog::DestroyWindow();
}

void CAlliedUITestChild::OnClose()
{
	DestroyWindow();
}

void CAlliedUITestChild::SetValue(BorderColor color, BorderRadius radius, BorderStyle style, BorderWidth width)
{
	m_child.SetBorderRadius(radius);
	m_child.SetBorderStyle(style);
	m_child.SetBorderWidth(width);
	m_child.SetBorderColor(color);
}

BOOL CAlliedUITestChild::OnInitDialog()
{
	CRect rc = { 10, 10, 400, 400 };

	CDialog::OnInitDialog();

	m_child.Create(_T("mmm"), WS_CHILD | WS_VISIBLE, rc, this, 1234);
	m_isInit = TRUE;
	ResizeLayout();

	return TRUE;
}

void CAlliedUITestChild::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAlliedUITestChild, CDialog)
	ON_WM_SIZE()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

void CAlliedUITestChild::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if (m_isInit) {
		ResizeLayout();
	}
}

void CAlliedUITestChild::ResizeLayout()
{
	CRect rc;

	GetClientRect(rc);

	m_child.SetWindowPos(NULL, rc.left + 40, rc.top + 40, rc.Width() - 80, rc.Height() - 80, 0);
}

// CAlliedUITestChild message handlers
