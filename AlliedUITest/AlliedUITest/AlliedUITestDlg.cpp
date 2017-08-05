
// AlliedUITestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AlliedUITest.h"
#include "AlliedUITestDlg.h"
#include "afxdialogex.h"
#include "windef.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	
END_MESSAGE_MAP()


// CAlliedUITestDlg dialog


CAlliedUITestDlg::CAlliedUITestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ALLIEDUITEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_isInit = FALSE;
}

void CAlliedUITestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OK, m_okBtn);
	DDX_Control(pDX, IDC_EDIT1, m_editTopColor);
	DDX_Control(pDX, IDC_EDIT2, m_editLeftColor);
	DDX_Control(pDX, IDC_EDIT3, m_editRightColor);
	DDX_Control(pDX, IDC_EDIT4, m_editBottomColor);

	DDX_Control(pDX, IDC_EDIT5, m_editTopWidth);
	DDX_Control(pDX, IDC_EDIT6, m_editLeftWidth);
	DDX_Control(pDX, IDC_EDIT7, m_editRightWidth);
	DDX_Control(pDX, IDC_EDIT8, m_editBottomWidth);

	DDX_Control(pDX, IDC_EDIT9, m_editTLRadius);
	DDX_Control(pDX, IDC_EDIT10, m_editTRRadius);
	DDX_Control(pDX, IDC_EDIT11, m_editBLRadius);
	DDX_Control(pDX, IDC_EDIT12, m_editBRRadius);

	DDX_Control(pDX, IDC_EDIT13, m_editTopStyle);
	DDX_Control(pDX, IDC_EDIT14, m_editLeftStyle);
	DDX_Control(pDX, IDC_EDIT15, m_editRightStyle);
	DDX_Control(pDX, IDC_EDIT16, m_editBottomStyle);

	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_STATIC2, m_static2);
	DDX_Control(pDX, IDC_STATIC3, m_static3);
	DDX_Control(pDX, IDC_STATIC4, m_static4);
	DDX_Control(pDX, IDC_STATIC5, m_static5);
	DDX_Control(pDX, IDC_STATIC6, m_static6);
	DDX_Control(pDX, IDC_STATIC7, m_static7);
	DDX_Control(pDX, IDC_STATIC8, m_static8);
	DDX_Control(pDX, IDC_STATIC9, m_static9);
	DDX_Control(pDX, IDC_STATIC10, m_static10);
	DDX_Control(pDX, IDC_STATIC11, m_static11);
	DDX_Control(pDX, IDC_STATIC12, m_static12);
	DDX_Control(pDX, IDC_STATIC13, m_static13);
	DDX_Control(pDX, IDC_STATIC14, m_static14);
	DDX_Control(pDX, IDC_STATIC15, m_static15);
	DDX_Control(pDX, IDC_STATIC16, m_static16);
	DDX_Control(pDX, IDC_STATIC17, m_static17);
	DDX_Control(pDX, IDC_STATIC18, m_static18);
	DDX_Control(pDX, IDC_STATIC19, m_static19);
	DDX_Control(pDX, IDC_STATIC20, m_static20);
}

BEGIN_MESSAGE_MAP(CAlliedUITestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OK, OnCreateChild)
END_MESSAGE_MAP()


// CAlliedUITestDlg message handlers

BOOL CAlliedUITestDlg::OnInitDialog()
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
	ShowChildWindow(SW_HIDE);
	int iHeight = 40, iWidth = 70;
	CRect rc = { 10, 10, iWidth + 10, iHeight  + 10};

	m_child1.SetBorderWidth(5);
	m_child1.SetBorderRadius(5);
	m_child1.SetBorderColor(RGB(255, 0, 0), RGB(255, 100, 10), RGB(255, 255, 0), RGB(255, 0, 255));
	m_child1.Create(_T("1"), WS_CHILD | WS_VISIBLE, rc, this, 1234);
	m_child1.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), 0);

	rc.left = rc.right + 10;
	rc.right += 10 + iWidth;

	m_child2.SetBorderWidth(8);
	m_child2.SetBorderRadius(5);
	m_child2.SetBorderColor(RGB(255, 10, 0), RGB(255, 41, 100), RGB(23, 255, 0), RGB(10, 100, 255));
	m_child2.Create(_T("2"), WS_CHILD | WS_VISIBLE, rc, this, 1235);
	m_child2.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), 0);
	
	
	rc.left = rc.right + 10;
	rc.right += 10 + iWidth;
	m_child3.SetBorderWidth(10);
	m_child3.SetBorderRadius(5, 5, 10, 0);
	m_child3.SetBorderColor(RGB(22, 0, 10), RGB(55, 200, 110), RGB(25, 65, 100), RGB(95, 10, 255));
	m_child3.Create(_T("3"), WS_CHILD | WS_VISIBLE, rc, this, 1236);
	m_child3.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), 0);

	rc.left = rc.right + 10;
	rc.right += 10 + iWidth;

	m_child4.SetBorderWidth(0, 0, 0, 0);
	m_child4.SetBorderRadius(5);
	m_child4.SetBorderColor(RGB(255, 53, 0), RGB(25, 40, 150), RGB(25, 23, 50), RGB(255, 30, 255));
	m_child4.Create(_T("4"), WS_CHILD | WS_VISIBLE, rc, this, 1237);
	m_child4.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), 0);

	rc.top += rc.bottom + 20;
	rc.bottom = rc.top + iHeight;
	rc.left = 10;
	rc.right = rc.left + iWidth;
	m_child5.SetBorderWidth(0, 10, 0, 0);
	m_child5.SetBorderRadius(10);
	m_child5.SetBorderColor(RGB(255, 60, 50), RGB(25, 100, 10), RGB(255, 25, 10), RGB(255, 40, 55));
	m_child5.Create(_T("5"), WS_CHILD | WS_VISIBLE, rc, this, 1238);
	m_child5.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), 0);
	

	rc.left = rc.right + 10;
	rc.right += 10 + iWidth;
	m_child6.SetBorderColor(RGB(255, 80, 60), RGB(25, 10, 104), RGB(255, 5, 60), RGB(25, 20, 55));
	m_child6.SetBorderWidth(5);
	m_child6.SetBorderRadius(0);
	m_child6.Create(_T("6"), WS_CHILD | WS_VISIBLE, rc, this, 1239);
	m_child6.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), 0);

	rc.left = rc.right + 10;
	rc.right += 10 + iWidth;
	m_child7.SetBorderColor(RGB(255, 0, 30), RGB(65, 40, 10), RGB(255, 55, 40), RGB(255, 0, 0));
	m_child7.SetBorderWidth(1, 1, 1, 1);
	m_child7.SetBorderRadius(5);
	m_child7.Create(_T("7"), WS_CHILD | WS_VISIBLE, rc, this, 1240);
	m_child7.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), 0);
	
	rc.left = rc.right + 10;
	rc.right += 10 + iWidth;

	m_child8.SetBorderColor(RGB(255, 190, 0), RGB(25, 190, 10), RGB(255, 25, 0), RGB(65, 20, 25));
	m_child8.SetBorderWidth(1, 1, 1, 1);
	m_child8.SetBorderRadius(0);
	m_child8.Create(_T("8"), WS_CHILD | WS_VISIBLE, rc, this, 1241);
	m_child8.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), 0);

	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAlliedUITestDlg::ResizeLayout()
{
}

void CAlliedUITestDlg::ShowChildWindow(int iCmd)
{
	m_static1.ShowWindow(iCmd);
	m_static2.ShowWindow(iCmd);
	m_static3.ShowWindow(iCmd);
	m_static4.ShowWindow(iCmd);
	m_static5.ShowWindow(iCmd);
	m_static6.ShowWindow(iCmd);
	m_static7.ShowWindow(iCmd);
	m_static8.ShowWindow(iCmd);
	m_static9.ShowWindow(iCmd);
	m_static10.ShowWindow(iCmd);
	m_static11.ShowWindow(iCmd);
	m_static12.ShowWindow(iCmd);
	m_static13.ShowWindow(iCmd);
	m_static14.ShowWindow(iCmd);
	m_static15.ShowWindow(iCmd);
	m_static16.ShowWindow(iCmd);
	m_static17.ShowWindow(iCmd);
	m_static18.ShowWindow(iCmd);
	m_static19.ShowWindow(iCmd);
	m_static20.ShowWindow(iCmd);


	m_editTopColor.ShowWindow(iCmd);
	m_editLeftColor.ShowWindow(iCmd);
	m_editRightColor.ShowWindow(iCmd);
	m_editBottomColor.ShowWindow(iCmd);

	m_editTopWidth.ShowWindow(iCmd);
	m_editLeftWidth.ShowWindow(iCmd);
	m_editRightWidth.ShowWindow(iCmd);
	m_editBottomWidth.ShowWindow(iCmd);

	m_editTLRadius.ShowWindow(iCmd);
	m_editTRRadius.ShowWindow(iCmd);
	m_editBLRadius.ShowWindow(iCmd);
	m_editBRRadius.ShowWindow(iCmd);
	
	m_editTopStyle.ShowWindow(iCmd);
	m_editLeftStyle.ShowWindow(iCmd);
	m_editRightStyle.ShowWindow(iCmd);
	m_editBottomStyle.ShowWindow(iCmd);

	m_okBtn.ShowWindow(iCmd);
}

void CAlliedUITestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAlliedUITestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void CAlliedUITestDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	if (m_isInit) {
		ResizeLayout();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAlliedUITestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAlliedUITestDlg::OnCreateChild()
{
	CString szText;

	BorderRadius radius;
	m_editBLRadius.GetWindowText(szText);
	radius.bottomleft = 10;//_ttoi(szText);
	m_editTRRadius.GetWindowText(szText);
	radius.topright =  10;//_ttoi(szText);
	m_editBRRadius.GetWindowText(szText);
	radius.bottomright = 10;// _ttoi(szText);
	m_editTLRadius.GetWindowText(szText);
	radius.topleft = 10;// _ttoi(szText);

	BorderStyle style;
	m_editRightStyle.GetWindowText(szText);
	style.right = (enBorderStyle)_ttoi(szText);
	m_editLeftStyle.GetWindowText(szText);
	style.left = (enBorderStyle)_ttoi(szText);
	m_editBottomStyle.GetWindowText(szText);
	style.bottom = (enBorderStyle)_ttoi(szText);
	m_editTopStyle.GetWindowText(szText);
	style.top = (enBorderStyle)_ttoi(szText);

	BorderWidth width;
	m_editTopWidth.GetWindowText(szText);
	width.top = 5;// _ttoi(szText);
	m_editLeftWidth.GetWindowText(szText);
	width.left = 5;//_ttoi(szText);
	m_editRightWidth.GetWindowText(szText);
	width.right = 5;// _ttoi(szText);
	m_editBottomWidth.GetWindowText(szText);
	width.bottom = 12;// _ttoi(szText);

	BorderColor color;
	//m_editTopColor.GetWindowText(szText);
	color.top = RGB(255, 0, 255); //RGB(255, 0, 0);
	//m_editLeftColor.GetWindowText(szText);
	color.left = RGB(255, 0, 255); // RGB(0, 255, 102);
	//m_editRightColor.GetWindowText(szText);
	color.right = RGB(255, 0, 255);
	//m_editBottomColor.GetWindowText(szText);
	color.bottom = RGB(255, 0, 255);// ;; RGB(255, 255, 0);

	CAlliedUITestChild * newChild;

	newChild = new CAlliedUITestChild(this);
	newChild->SetValue(color, radius, style, width);
	newChild->Create(CAlliedUITestChild::IDD);
	newChild->ShowWindow(TRUE);
}
