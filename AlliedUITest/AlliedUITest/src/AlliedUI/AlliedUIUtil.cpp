#include "stdafx.h"
#include "AlliedUIUtil.h"

namespace AlliedUI
{
	namespace AlliedUIUtil
	{

		void	CopyBorderColor(BorderColor& colorDes, COLORREF color)
		{
			colorDes.top = color;
			colorDes.left = color;
			colorDes.right = color;
			colorDes.bottom = color;
		}

		void	CopyBorderColor(BorderColor& colorDes, BorderColor colorSrc)
		{
			colorDes.top = colorSrc.top;
			colorDes.left = colorSrc.left;
			colorDes.right = colorSrc.right;
			colorDes.bottom = colorSrc.bottom;
		}

		void	CopyBorderRadius(BorderRadius& radiusDes, int iRadius)
		{
			radiusDes.topleft = iRadius;
			radiusDes.topright = iRadius;
			radiusDes.bottomleft = iRadius;
			radiusDes.bottomright = iRadius;
		}

		void	CopyBorderRadius(BorderRadius& radiusDes, BorderRadius radiusSrc)
		{
			radiusDes.topleft = radiusSrc.topleft;
			radiusDes.topright = radiusSrc.topright;
			radiusDes.bottomleft = radiusSrc.bottomleft;
			radiusDes.bottomright  = radiusSrc.bottomright;
		}

		void	CopyBorderWidth(BorderWidth& widthDes, int iWidth)
		{
			widthDes.top = iWidth;
			widthDes.left = iWidth;
			widthDes.right = iWidth;
			widthDes.bottom = iWidth;
		}

		void	CopyBorderWidth(BorderWidth& widthDes, BorderWidth widthSrc)
		{
			widthDes.top = widthSrc.top;
			widthDes.left = widthSrc.left;
			widthDes.right = widthSrc.right;
			widthDes.bottom = widthSrc.bottom;
		}

		void	CopyBorderStyle(BorderStyle& styleDes, enBorderStyle style)
		{
			styleDes.top = style;
			styleDes.left = style;
			styleDes.right = style;
			styleDes.bottom = style;
		}

		void	CopyBorderStyle(BorderStyle& styleDes, BorderStyle styleSrc)
		{
			styleDes.top = styleSrc.top;
			styleDes.left = styleSrc.left;
			styleDes.right = styleSrc.right;
			styleDes.bottom = styleSrc.bottom;
		}
	}
}