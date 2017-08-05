#pragma once

#include "windef.h"

namespace AlliedUI {
	enum enBorderStyle
	{
		BORDER_STYLE_NORMAL = 0,
		BORDER_STYLE_DOT,
		BORDER_STYLE_DASH,
		BORDER_STYLE_DASH_DOT
	};
	typedef struct BorderColor
	{
		COLORREF top;
		COLORREF left;
		COLORREF right;
		COLORREF bottom;
	} BorderColor;

	typedef struct BorderRadius
	{
		int	topleft;
		int topright;
		int bottomleft;
		int bottomright;
	} BorderRadius;

	typedef struct BorderWidth
	{
		int	top;
		int left;
		int right;
		int bottom;
	} BorderWidth;

	typedef struct BorderStyle
	{
		enBorderStyle top;
		enBorderStyle left;
		enBorderStyle right;
		enBorderStyle bottom;
	} BorderStyle;
}