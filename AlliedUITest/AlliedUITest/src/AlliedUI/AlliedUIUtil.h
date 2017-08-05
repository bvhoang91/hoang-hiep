#pragma once

#include "AlliedUIDefine.h"

namespace AlliedUI
{
	namespace AlliedUIUtil
	{

		void	CopyBorderColor(BorderColor& colorDes, COLORREF color);
		void	CopyBorderColor(BorderColor& colorDes, BorderColor colorSrc);

		void	CopyBorderRadius(BorderRadius& radiusDes, int iRadius);
		void	CopyBorderRadius(BorderRadius& radiusDes, BorderRadius radiusSrc);

		void	CopyBorderWidth(BorderWidth& widthDes, int iWidth);
		void	CopyBorderWidth(BorderWidth& widthDes, BorderWidth widthSrc);

		void	CopyBorderStyle(BorderStyle& styleDes, enBorderStyle style);
		void	CopyBorderStyle(BorderStyle& styleDes, BorderStyle styleSrc);
	}
}
