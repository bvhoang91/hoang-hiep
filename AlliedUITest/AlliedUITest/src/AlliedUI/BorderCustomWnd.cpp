#include "stdafx.h"
#include "BorderCustomWnd.h"
#include "Define.h"
#include "gdiplusgraphics.h"

using namespace std;
namespace AlliedUI {
	
	IMPLEMENT_DYNAMIC(CBorderCustomWnd, CWnd)

	CBorderCustomWnd::CBorderCustomWnd()
	{
		SetBorderColor(ALLIEDUI_COLOR_RED);
		SetBorderRadius(0);
		SetBorderWidth(10);
		SetBorderStyle(BORDER_STYLE_NORMAL);

		m_bkgColor = ALLIEDUI_COLOR_BLUE;
		m_bIsInit = FALSE;
	}

	CBorderCustomWnd::~CBorderCustomWnd()
	{

	}

	BEGIN_MESSAGE_MAP(CBorderCustomWnd, CWnd)
		ON_WM_PAINT()
		ON_WM_SIZE()
	END_MESSAGE_MAP()
	
	BOOL CBorderCustomWnd::Create(LPCTSTR lpszWindowName, DWORD dwStyle,
						   CRect rect, CWnd* pParentWnd, UINT nID)
	{
		BOOL bRes;

		bRes = CWnd::Create(NULL, _T("Hi"), WS_CHILD | WS_VISIBLE, rect, pParentWnd, nID);

		if (bRes) {
			m_bIsInit = TRUE;
		}

		SendMessage(WM_SIZE);
		Invalidate();
		return (bRes);
	}
	
	void CBorderCustomWnd::OnSize(UINT nType, int cx, int cy)
	{
		CWnd::OnSize(nType, cx, cy);

		if (m_bIsInit) {
			CPoint ptVertex[12];
			CRect rcWnd;
			CRgn rgn, rgnTopLeft, rgnTopRight, rgnBotLeft, rgnBotRight;

			GetWindowRect(&rcWnd);

			ptVertex[0] = CPoint(m_borderRadius.topleft, 0);
			ptVertex[1] = CPoint(m_borderRadius.topleft, m_borderRadius.topleft);
			ptVertex[2] = CPoint(0, m_borderRadius.topleft);
			if (m_borderRadius.topleft > 0) {
				rgnTopLeft.CreateRoundRectRgn(0, 0, m_borderRadius.topleft * 2, m_borderRadius.topleft * 2,
											  m_borderRadius.topleft * 2 , m_borderRadius.topleft * 2);
			} else {
				rgnTopLeft.CreateRectRgn(0, 0, m_borderRadius.topleft * 2, m_borderRadius.topleft * 2);
			}

			ptVertex[3] = CPoint(0, rcWnd.Height() - m_borderRadius.bottomleft);
			ptVertex[4] = CPoint(m_borderRadius.bottomleft, rcWnd.Height() - m_borderRadius.bottomleft);
			ptVertex[5] = CPoint(m_borderRadius.bottomleft, rcWnd.Height());
			if (m_borderRadius.bottomleft > 0) {
				rgnBotLeft.CreateRoundRectRgn(0, rcWnd.Height() - m_borderRadius.bottomleft * 2,
											  m_borderRadius.bottomleft * 2, rcWnd.Height(),
											  m_borderRadius.bottomleft * 2, m_borderRadius.bottomleft * 2);
			} else {
				rgnBotLeft.CreateRectRgn(0, rcWnd.Height() - m_borderRadius.bottomleft * 2,
										 m_borderRadius.bottomleft * 2, rcWnd.Height());
			}

			ptVertex[6] = CPoint(rcWnd.Width() - m_borderRadius.bottomright, rcWnd.Height());
			ptVertex[7] = CPoint(rcWnd.Width() - m_borderRadius.bottomright, rcWnd.Height() - m_borderRadius.bottomright);
			ptVertex[8] = CPoint(rcWnd.Width(), rcWnd.Height() - m_borderRadius.bottomright);
			if (m_borderRadius.bottomright > 0) {
				rgnBotRight.CreateRoundRectRgn(rcWnd.Width() - m_borderRadius.bottomright * 2, 
											   rcWnd.Height() - m_borderRadius.bottomright * 2,
											   rcWnd.Width(), rcWnd.Height(),
											   m_borderRadius.bottomright * 2 + 2, m_borderRadius.bottomright * 2 + 2);
			} else {
				rgnBotRight.CreateRectRgn(rcWnd.Width() - m_borderRadius.bottomright * 2,
										  rcWnd.Height() - m_borderRadius.bottomright * 2,
										  rcWnd.Width(), rcWnd.Height());
			}

			ptVertex[9] = CPoint(rcWnd.Width(), m_borderRadius.topright);
			ptVertex[10] = CPoint(rcWnd.Width() - m_borderRadius.topright, m_borderRadius.topright);
			ptVertex[11] = CPoint(rcWnd.Width() - m_borderRadius.topright, 0);
			if (m_borderRadius.topright > 0) {
				rgnTopRight.CreateRoundRectRgn(rcWnd.Width() - m_borderRadius.topright * 2, 0,
											   rcWnd.Width(), m_borderRadius.topright * 2,
											   m_borderRadius.topright * 2, m_borderRadius.topright * 2);
			} else {
				rgnTopRight.CreateRectRgn(rcWnd.Width() - m_borderRadius.topright * 2, 0,
										  rcWnd.Width(), m_borderRadius.topright * 2);
			}

			rgn.CreatePolygonRgn(ptVertex, 12, ALTERNATE);

			CombineRgn(rgn, rgn, rgnTopLeft, RGN_OR);
			CombineRgn(rgn, rgn, rgnTopRight, RGN_OR);
			CombineRgn(rgn, rgn, rgnBotLeft, RGN_OR);
			CombineRgn(rgn, rgn, rgnBotRight, RGN_OR);

			SetWindowRgn(static_cast<HRGN>(rgn.GetSafeHandle()), TRUE);
			rgn.DeleteObject();
			rgnTopLeft.DeleteObject();
			rgnTopRight.DeleteObject();
			rgnBotRight.DeleteObject();
			rgnBotLeft.DeleteObject();
		}
	}

	void CBorderCustomWnd::OnPaint()
	{
		CPaintDC dc(this);
		CDC* pDC;
		CRect rc;
		CBrush brush;
		
		GetClientRect(rc);

		brush.CreateSolidBrush(m_bkgColor);
		pDC = CDC::FromHandle(dc.m_hDC);
		
		pDC->FillRect(rc, &brush);

		DrawBorder(pDC, rc);

		if (rc.Height() > m_borderWidth.top + m_borderWidth.bottom &&
			rc.Width() > m_borderWidth.left + m_borderWidth.right) {
			DrawCorner(pDC, rc);
		}

		brush.DeleteObject();
	}

	//************************************************************************
	// Method:    DrawBorder
	// Returns:   void
	// Qualifier: Draw all border
	// Parameter: CDC * pDC
	// Parameter: CRect & rc
	//************************************************************************
	void CBorderCustomWnd::DrawBorder(CDC* pDC, CRect& rc)
	{
		CBrush brush;

		brush.CreateSolidBrush(m_bkgColor);

		// Draw Left
		if (m_borderWidth.left > 0) {
			int y1, y2, x, iMax, iMaxRadius;
			CRect rcEx(0, 0, 0, 0);

			iMaxRadius = max(m_borderRadius.topleft, m_borderRadius.bottomleft);
			iMax = max(iMaxRadius, m_borderWidth.left);
			if (iMax == m_borderWidth.left) {
				x = rc.left + m_borderWidth.left;
				y1 = rc.top + m_borderWidth.top;
				y2 = rc.bottom - m_borderWidth.bottom;
			} else {
				x = min(rc.left + iMaxRadius, rc.right - m_borderWidth.right);
				y1 = rc.top + m_borderWidth.top * (x - rc.left) / m_borderWidth.left;
				y2 = rc.bottom - m_borderWidth.bottom * (x - rc.left) / m_borderWidth.left;

				rcEx.top = rc.top + max(m_borderRadius.topleft, m_borderWidth.top);
				rcEx.left = rc.left + m_borderWidth.left;
				rcEx.right = x;
				rcEx.bottom = rc.bottom - max(m_borderRadius.bottomleft, m_borderWidth.bottom);
			}

			DrawLine(pDC, m_borderColor.left,
					 CPoint(rc.left, rc.top),
					 CPoint(x, y1),
					 CPoint(rc.left, rc.bottom),
					 CPoint(x, y2),
					 m_borderStyle.left, true);

			if (rcEx.Width() > 0 && rcEx.Height() > 0) {
				pDC->FillRect(rcEx, &brush);
			}
		}

		// Draw Top
		if (m_borderWidth.top > 0) {
			int x1, x2, y, iMax , iMaxRadius;
			CRect rcEx(0, 0, 0, 0);

			iMaxRadius = max(m_borderRadius.topleft, m_borderRadius.topright);
			iMax = max(iMaxRadius, m_borderWidth.top);
			if (iMax == m_borderWidth.top) {
				x1 = rc.left + m_borderWidth.left;
				x2 = rc.right - m_borderWidth.right;
				y = rc.top + m_borderWidth.top;
			} else {
				y = min(rc.top + iMaxRadius, rc.bottom - m_borderWidth.bottom);
				x1 = rc.left + m_borderWidth.left * (y - rc.top) / m_borderWidth.top;
				x2 = rc.right - m_borderWidth.right * (y - rc.top) / m_borderWidth.top;

				rcEx.top = rc.top + m_borderWidth.top;
				rcEx.left = rc.left + max(m_borderWidth.left, m_borderRadius.topleft);
				rcEx.right = rc.right - max(m_borderWidth.right, m_borderRadius.topright);
				rcEx.bottom = y;
			}
			DrawLine(pDC, m_borderColor.top,
					 CPoint(rc.top, rc.left),
					 CPoint(y, x1),
					 CPoint(rc.top, rc.right),
					 CPoint(y, x2),
					 m_borderStyle.top, false);
			if (rcEx.Width() > 0 && rcEx.Height() > 0) {
				pDC->FillRect(rcEx, &brush);
			}
		}

		// Draw Right
		if (m_borderWidth.right > 0) {
			int y1, y2, x, iMax, iMaxRadius;
			CRect rcEx(0, 0, 0, 0);

			iMaxRadius = max(m_borderRadius.topright, m_borderRadius.bottomright);
			iMax = max(iMaxRadius, m_borderWidth.right);
			if (iMax == m_borderWidth.right) {
				x = rc.right - m_borderWidth.right;
				y1 = rc.top + m_borderWidth.top;
				y2 = rc.bottom - m_borderWidth.bottom;
			} else {
				x = rc.right - iMaxRadius;
				y1 = rc.top + m_borderWidth.top * (rc.right - x) / m_borderWidth.right;
				y2 = rc.bottom - m_borderWidth.bottom * (rc.right - x) / m_borderWidth.right;

				rcEx.top = rc.top + max(m_borderRadius.topright, m_borderWidth.top);
				rcEx.left = x;
				rcEx.right = rc.right - m_borderWidth.right;
				rcEx.bottom = rc.bottom - max(m_borderRadius.bottomright, m_borderWidth.bottom);
			}

			DrawLine(pDC, m_borderColor.right,
					 CPoint(rc.right, rc.top),
					 CPoint(x, y1),
					 CPoint(rc.right, rc.bottom),
					 CPoint(x, y2),
					 m_borderStyle.right, true);
			if (rcEx.Width() > 0 && rcEx.Height() > 0) {
				pDC->FillRect(rcEx, &brush);
			}
		}
			
		// Draw Bottom
		if (m_borderWidth.bottom > 0) {
			int x1, x2, y, iMax, iMaxRadius;
			CRect rcEx(0, 0, 0, 0);
			
			iMaxRadius = max(m_borderRadius.bottomleft, m_borderRadius.bottomright);
			iMax = max(iMaxRadius, m_borderWidth.bottom);
			if (iMax == m_borderWidth.bottom) {
				x1 = rc.left + m_borderWidth.left;
				x2 = rc.right - m_borderWidth.right;
				y = rc.bottom - m_borderWidth.bottom;
			} else {
				y = max(rc.bottom - iMaxRadius, rc.top + m_borderWidth.top);
				x1 = rc.left + m_borderWidth.left * (rc.bottom - y) / m_borderWidth.bottom;
				x2 = rc.right - m_borderWidth.right * (rc.bottom - y) / m_borderWidth.bottom;

				rcEx.top = y;
				rcEx.left = rc.left + max(m_borderWidth.left, m_borderRadius.bottomleft);
				rcEx.right = rc.right - max(m_borderWidth.right, m_borderRadius.bottomright);
				rcEx.bottom = rc.bottom - m_borderWidth.bottom;
			}
			
			DrawLine(pDC, m_borderColor.bottom,
					 CPoint(rc.bottom, rc.left),
					 CPoint(y, x1),
					 CPoint(rc.bottom, rc.right),
					 CPoint(y, x2),
					 m_borderStyle.bottom, false);
			if (rcEx.Width() > 0 && rcEx.Height() > 0) {
				pDC->FillRect(rcEx, &brush);
			}
		}

		brush.DeleteObject();
	}

	//************************************************************************
	// Method:    DrawLine
	// Returns:   void
	// Qualifier: Draw line.
	// Parameter: CDC * pDC
	// Parameter: COLORREF clrBorder
	// Parameter: CPoint fromPoint1, CPoint fromPoint2, CPoint toPoint1, CPoint toPoint2
	// Parameter: enBorderStyle style
	// Parameter: bool isVerical
	// Idea:  x0,y0
	//         |\x1, y1
	//         | |
	//         | |x2, y2
	//         |/
	//         x3, y3
	// draw path x0,y0-x1,y1-x2,y2-x3,y3
	//************************************************************************
	void CBorderCustomWnd::DrawLine(CDC*pDC, COLORREF clrBorder, 
									CPoint fromPoint1, CPoint fromPoint2,
									CPoint toPoint1, CPoint toPoint2,
									enBorderStyle style, bool isVerical)
	{
		block_array blocks;
		switch (style)
		{
		case AlliedUI::BORDER_STYLE_NORMAL:
			GetBlockPointArrayNormal(blocks, fromPoint1, fromPoint2, toPoint1, toPoint2);
			break;
		case AlliedUI::BORDER_STYLE_DOT:
		case AlliedUI::BORDER_STYLE_DASH:
		case AlliedUI::BORDER_STYLE_DASH_DOT:
			GetBlockPointDot(blocks,
							 fromPoint1.x, fromPoint1.y,
							 fromPoint2.x, fromPoint2.y, 
							 toPoint2.x, toPoint2.y, 
							 toPoint1.x, toPoint1.y,
							 style);
			break;
		default:
			break;
		}
		
		DrawBlockPointArray(pDC, clrBorder, blocks, isVerical);
		blocks.clear();
	}

	//************************************************************************
	// Method:    DrawCorner
	// Returns:   void
	// Qualifier: Make corner smoothly
	// Parameter: CDC * pDC
	// Parameter: CRect & rc
	//************************************************************************
	void CBorderCustomWnd::DrawCorner(CDC* pDC, CRect& rc)

	{
		CBrush* oldBrush, brush;
		CPen* oldPen, pen;
		
		brush.CreateSolidBrush(m_bkgColor);
		pen.CreatePen(0, 1, m_bkgColor);

		oldBrush = pDC->SelectObject(&brush);
		oldPen = pDC->SelectObject(&pen);

		// Draw Top-Left corner
		if (m_borderRadius.topleft > m_borderWidth.left &&
			m_borderRadius.topleft > m_borderWidth.top) {
			pDC->Ellipse(rc.left + m_borderWidth.left, rc.top + m_borderWidth.top,
						 min(rc.left - m_borderWidth.left + 2 * m_borderRadius.topleft, rc.right - m_borderWidth.right),
						 min(rc.top - m_borderWidth.top + 2 * m_borderRadius.topleft, rc.bottom - m_borderWidth.bottom));
		}

		// Draw Top-Right corner
		if (m_borderRadius.topright > m_borderWidth.right &&
			m_borderRadius.topright > m_borderWidth.top ) {
			CRect r1c(max(rc.right - 2 * m_borderRadius.topright + m_borderWidth.right, rc.left + m_borderWidth.left),
				rc.top + m_borderWidth.top,
				rc.right - m_borderWidth.right,
				min(rc.top - m_borderWidth.top + 2 * m_borderRadius.topright, rc.bottom - m_borderWidth.bottom));
			pDC->Ellipse(max(rc.right - 2 * m_borderRadius.topright + m_borderWidth.right, rc.left + m_borderWidth.left), 
						 rc.top + m_borderWidth.top,
						 rc.right - m_borderWidth.right,
						 min(rc.top - m_borderWidth.top + 2 * m_borderRadius.topright, rc.bottom - m_borderWidth.bottom));
		}

		// Draw Bottom-Left corner
		if (m_borderRadius.bottomleft > m_borderWidth.bottom &&
			m_borderRadius.bottomleft > m_borderWidth.left) {
			pDC->Ellipse(rc.left + m_borderWidth.left,
						 max(rc.bottom - 2 * m_borderRadius.bottomleft + m_borderWidth.bottom, rc.top + m_borderWidth.top),
						 min(rc.left + 2 * m_borderRadius.bottomleft - m_borderWidth.left, rc.right - m_borderWidth.right),
						 rc.bottom - m_borderWidth.bottom);
		}

		// Draw Bottom-Right corner
		if (m_borderRadius.bottomright > m_borderWidth.bottom &&
			m_borderRadius.bottomright > m_borderWidth.right) {
			pDC->Ellipse(max(rc.right - 2 * m_borderRadius.bottomright + m_borderWidth.right, rc.left + m_borderWidth.left),
						 max(rc.bottom - 2 * m_borderRadius.bottomright + m_borderWidth.bottom, rc.top + m_borderWidth.top),
						 rc.right - m_borderWidth.right,
						 rc.bottom - m_borderWidth.bottom);
		}

		pDC->SelectObject(oldBrush);
		pDC->SelectObject(oldPen);

		pen.DeleteObject();
		brush.DeleteObject();
	}

	//************************************************************************
	// Method:    GetBlockPointArrayNormal
	// Returns:   void
	// Qualifier: Create block in case style is normal
	// Parameter: block_array & blocks
	// Parameter: CPoint fromPoint1, fromPoint2, toPoint1, toPoint2
	//************************************************************************
	void CBorderCustomWnd::GetBlockPointArrayNormal(block_array& blocks,
													CPoint fromPoint1, CPoint fromPoint2,
													CPoint toPoint1, CPoint toPoint2)
	{
		block_points points;
		points.push_back(CPoint(fromPoint1.x, fromPoint1.y));
		points.push_back(CPoint(toPoint1.x, toPoint1.y));
		points.push_back(CPoint(toPoint2.x, toPoint2.y));
		points.push_back(CPoint(fromPoint2.x, fromPoint2.y));
		points.push_back(CPoint(fromPoint1.x, fromPoint1.y));

		blocks.push_back(points);
	}

	//************************************************************************
	// Method:    GetBlockPointDot
	// Returns:   void
	// Qualifier: Create block array, block is a collection of point of path.
	// using in style dot, dash, dot_dash.
	// Ex: __    __    __
	//    |__|  |__|  |__| 3 blocks
	// Parameter: block_array & blocks
	// Parameter: int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3,
	// Parameter: enBorderStyle style
	//************************************************************************
	void CBorderCustomWnd::GetBlockPointDot(block_array& blocks,
									   int x0, int y0,
									   int x1, int y1, 
									   int x2, int y2,
									   int x3, int y3, 
									   enBorderStyle style)
	{
		CPoint startPoint(x0, y0);
		
		int iDotLength;
		int iDotWidth = abs(x0 - x1);
 		int iFlag = (x0 > x1) ? 1 : -1;
		
		for (int i = 0; startPoint.y < y3; i++) {
			CPoint lastPoint;
			block_points points;

			if (style == BORDER_STYLE_DASH) {
				iDotLength = iDotWidth * 3;
			} else if (style == BORDER_STYLE_DASH_DOT) {
				iDotLength = (i % 2 == 0) ? iDotWidth * 3 : iDotWidth;
			} else {
				iDotLength = iDotWidth;
			}

			points.push_back(CPoint(startPoint.x, startPoint.y));
			lastPoint = startPoint;

			if (startPoint.y < y1) {
				lastPoint.y = startPoint.y;
				lastPoint.x = x0 - iFlag * (lastPoint.y - y0) * iDotWidth / (y1 - y0);
				points.push_back(CPoint(lastPoint.x, lastPoint.y));
				if (startPoint.y + iDotLength < y1) {
					lastPoint.y = startPoint.y + iDotLength;
					lastPoint.x = x0 + iFlag - (lastPoint.y - y0) * iDotWidth / (y1 - y0);
					goto _AddLastPoint_;
				}

				lastPoint = CPoint(x1, y1);
				points.push_back(CPoint(lastPoint.x, lastPoint.y));
			} else if (startPoint.y > y2) {
				lastPoint.x = x0 - iFlag * (y3 - lastPoint.y) * iDotWidth / (y3 - y2);
				points.push_back(CPoint(lastPoint.x, lastPoint.y));
			} else if (lastPoint.y <= y2){
				lastPoint.x -= iFlag * iDotWidth;
				points.push_back(CPoint(lastPoint.x, lastPoint.y));
			}
			
			int iYNextPoint = lastPoint.y + iDotLength - (lastPoint.y - startPoint.y);

			if (iYNextPoint <= y2) {
				lastPoint.y = iYNextPoint;
				goto _AddLastPoint_;
			}

			lastPoint = CPoint(x2, y2);
			points.push_back(CPoint(lastPoint.x, lastPoint.y));

			lastPoint.y = lastPoint.y + iDotLength - (lastPoint.y - startPoint.y);
			if (y3 == y2) {
				lastPoint.x = x1;
			} else {
				lastPoint.x = x0 - iFlag * (y3 - lastPoint.y) * iDotWidth / (y3 - y2);
			}

			if (lastPoint.y >= y3) {
				lastPoint = CPoint(x3, y3);
			}

		_AddLastPoint_:
			points.push_back(CPoint(lastPoint.x, lastPoint.y));
			points.push_back(CPoint(startPoint.x, lastPoint.y));
			points.push_back(CPoint(startPoint.x, startPoint.y));
			
			startPoint.y += iDotLength + iDotWidth;
			blocks.push_back(points);
		}
	}
	
	//************************************************************************
	// Method:    DrawBlockPointArray
	// Returns:   void
	// Qualifier: Draw blocks
	// Parameter: CDC * pDC
	// Parameter: COLORREF clrBorder
	// Parameter: block_array & blocks
	// Parameter: bool isVerical
	//************************************************************************
	void CBorderCustomWnd::DrawBlockPointArray(CDC* pDC, COLORREF clrBorder,
											   block_array& blocks, bool isVerical)
	{
		std::vector<block_points>::const_iterator i;
		CBrush brush, *oldBrush;

		brush.CreateSolidBrush(clrBorder);
		oldBrush = (CBrush*)pDC->SelectObject(&brush);

		Gdiplus::Graphics graphic(pDC->GetSafeHdc());
		Gdiplus::SolidBrush br(clrBorder);
		graphic.FillRectangle(&br, Gdiplus::Rect(0, 0, 20, 30));
		for (i = blocks.begin(); i != blocks.end(); i++) {
			block_points points = (*i);
			std::vector<CPoint>::const_iterator j = points.begin();
			CPoint point = *j;
			pDC->BeginPath();
			pDC->MoveTo(isVerical ? point.x : point.y,
						isVerical ? point.y : point.x);
			for (j++; j != points.end(); j++) {
				point = (*j);
				pDC->LineTo(isVerical ? point.x : point.y,
							isVerical ? point.y : point.x);
			}

			pDC->EndPath();
			pDC->FillPath();
			points.clear();
		}

		pDC->SelectObject(oldBrush);
		brush.DeleteObject();
	}
}
