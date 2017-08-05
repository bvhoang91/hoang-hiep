#pragma once

#include "stdafx.h"
#include "AlliedUIDefine.h"
#include "AlliedUIUtil.h"
#include <vector>

namespace AlliedUI {

	typedef std::vector<CPoint> block_points;
	typedef std::vector<block_points> block_array;

	class CBorderCustomWnd : public CWnd
	{
	public:
		CBorderCustomWnd();
		virtual ~CBorderCustomWnd();

	public:

		void SetBorderColor(COLORREF color) 
		{
			AlliedUIUtil::CopyBorderColor(m_borderColor, color);
		}

		void SetBorderColor(COLORREF leftBorder, COLORREF topBorder,
							COLORREF rightBorder, COLORREF bottomBorder)
		{
			m_borderColor.left = leftBorder;
			m_borderColor.top = topBorder;
			m_borderColor.right = rightBorder;
			m_borderColor.bottom = bottomBorder;
		}

		void SetBorderColor(BorderColor colorSrc)
		{
			AlliedUIUtil::CopyBorderColor(m_borderColor, colorSrc);
		}

		BorderColor& GetBorderColor()
		{
			return m_borderColor;
		}

		void SetBorderRadius(int iRadius)
		{
			AlliedUIUtil::CopyBorderRadius(m_borderRadius, iRadius);
		}

		void SetBorderRadius(int topleftBorder, int toprightBorder,
							 int bottomleftBorder, int bottomrightBorder)
		{
			m_borderRadius.topleft = topleftBorder;
			m_borderRadius.topright = toprightBorder;
			m_borderRadius.bottomleft = bottomleftBorder;
			m_borderRadius.bottomright = bottomrightBorder;
		}

		void SetBorderRadius(BorderRadius radiusSrc)
		{
			AlliedUIUtil::CopyBorderRadius(m_borderRadius, radiusSrc);
		}

		BorderRadius& GetBorderRadius()
		{
			return m_borderRadius;
		}

		void SetBorderWidth(int iWidth)
		{
			AlliedUIUtil::CopyBorderWidth(m_borderWidth, iWidth);
		}

		void SetBorderWidth(int leftBorder, int topBorder,
							int rightBorder, int bottomBorder)
		{
			m_borderWidth.left = leftBorder;
			m_borderWidth.top = topBorder;
			m_borderWidth.right = rightBorder;
			m_borderWidth.bottom = bottomBorder;
		}

		void SetBorderWidth(BorderWidth borderWidth)
		{
			AlliedUIUtil::CopyBorderWidth(m_borderWidth, borderWidth);
		}

		BorderWidth& GetBorderWidth()
		{
			return m_borderWidth;
		}

		void SetBorderStyle(enBorderStyle style)
		{
			AlliedUIUtil::CopyBorderStyle(m_borderStyle, style);
		}

		void SetBorderStyle(enBorderStyle leftBorder, enBorderStyle topBorder,
						    enBorderStyle rightBorder, enBorderStyle bottomBorder) 
		{
			m_borderStyle.top = topBorder;
			m_borderStyle.left = leftBorder;
			m_borderStyle.bottom = bottomBorder;
			m_borderStyle.right = rightBorder;
		}

		void SetBorderStyle(BorderStyle borderStyle)
		{
			AlliedUIUtil::CopyBorderStyle(m_borderStyle, borderStyle);
		}

		BorderStyle& GetBorderStyle()
		{
			return m_borderStyle;
		}

		void SetBkgColor(COLORREF color) {
			m_bkgColor = color;
		}

		COLORREF GetBkgColor() {
			return m_bkgColor;
		}

	protected:
		DECLARE_DYNAMIC(CBorderCustomWnd)
		afx_msg void OnSize(UINT nType, int cx, int cy);
		afx_msg void OnPaint();
		DECLARE_MESSAGE_MAP()

	public:
		virtual BOOL Create(LPCTSTR lpszWindowName, 
							DWORD dwStyle, CRect rect,
							CWnd* pParentWnd, UINT nID);

	protected:
		void	DrawBorder(CDC* pDC, CRect& rc);

		void	DrawLine(CDC*pDC, COLORREF clrBorder, 
						 CPoint fromPoint1, CPoint fromPoint2,
						 CPoint toPoint1, CPoint toPoint2, 
						 enBorderStyle style, bool isVerical);

		void	DrawCorner(CDC* pDC, CRect& rc);

		void	GetBlockPointArrayNormal(block_array& blocks,
										 CPoint fromPoint1, CPoint fromPoint2,
										 CPoint toPoint1, CPoint toPoint2);

		void	GetBlockPointDot(block_array& blocks,
								 int x0, int y0,
								 int x1, int y1,
								 int x2, int y2,
								 int x3, int y3,
								 enBorderStyle style);

		void	DrawBlockPointArray(CDC* pDC, COLORREF clrBorder,
									block_array& blocks, bool isVerical);

	protected:
		BorderColor		m_borderColor;
		BorderRadius	m_borderRadius;
		BorderWidth		m_borderWidth;
		BorderStyle		m_borderStyle;

		COLORREF		m_bkgColor;

		BOOL			m_bIsInit;
	};
}


