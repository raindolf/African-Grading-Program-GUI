/**
 ******************************************************************************
 * $Id: libwin32.c 36 2013-02-20 00:15:00Z mkwayisi $
 * ----------------------------------------------------------------------------
 * Authored by Michael Kwayisi. Copyright (c) 2009-2013. All rights reserved.
 * Please send your comments to mkwayisi@gmail.com | Web: michaelkwayisi.com
 * ----------------------------------------------------------------------------
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * stringently met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions, and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions, and the following disclaimer in the
 *      documentation and/or other materials provided with the package.
 *   3. The end-user documentation included with the redistribution, if any,
 *      must include the following acknowledgment:
 *         "This product includes software developed by Michael Kwayisi"
 *      Alternately, this acknowledgment may appear in the software itself,
 *      if and wherever such third-party acknowledgments normally appear.
 *   4. Neither the name of the software nor the name of its author and/or
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 ******************************************************************************
 */

#include <windows.h>
#include "libwin32.h"

//==[ CODE ]===================================================================
// CenterWindowToScreen
VOID CenterWindowToScreen(HWND hwnd)
{
	RECT rcScreen;
	RECT rcWindow;
	
	GetWindowRect(hwnd, &rcWindow);
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rcScreen, 0);
	
	SetWindowPos(hwnd, NULL,
		(rcScreen.right - (rcWindow.right - rcWindow.left)) / 2,
		(rcScreen.bottom - (rcWindow.bottom - rcWindow.top)) / 2,
		0, 0, SWP_NOZORDER | SWP_NOSIZE);
}

//==[ CODE ]===================================================================
// CenterWindowToParent
VOID CenterWindowToParent(HWND hwnd)
{
	RECT rc, rcp;
	GetWindowRect(hwnd, &rc);
	GetWindowRect(GetParent(hwnd), &rcp);
	SetWindowPos(hwnd, NULL,
		rcp.left + ((rcp.right - rcp.left) - (rc.right - rc.left)) / 2,
		rcp.top + ((rcp.bottom - rcp.top) - (rc.bottom - rc.top)) / 2,
		0, 0, SWP_NOZORDER | SWP_NOSIZE);
}

//==[ CODE ]===================================================================
// GetWindowSize
BOOL GetWindowSize(HWND hwnd, LPSIZE size)
{
	RECT rc;
	if (GetWindowRect(hwnd, &rc)) {
		size->cx = rc.right - rc.left;
		size->cy = rc.bottom - rc.top;
		return TRUE;
	}
	return FALSE;
}

//==[ CODE ]===================================================================
// SetWindowSize
BOOL SetWindowSize(HWND hwnd, INT nWidth, INT nHeight)
{
	return SetWindowPos(hwnd, NULL,
		0, 0, nWidth, nHeight, SWP_NOZORDER | SWP_NOMOVE);
}

//==[ CODE ]===================================================================
// GetWindowClientSize
BOOL GetWindowClientSize(HWND hwnd, LPSIZE size)
{
	RECT rc;
	if (GetClientRect(hwnd, &rc)) {
		size->cx = rc.right;
		size->cy = rc.bottom;
		return TRUE;
	}
	return FALSE;
}

//==[ CODE ]===================================================================
// SetWindowClientSize
BOOL SetWindowClientSize(HWND hwnd, INT nWidth, INT nHeight)
{
	RECT rcWnd;
	RECT rcClient;
	
	GetWindowRect(hwnd, &rcWnd);
	GetClientRect(hwnd, &rcClient);
	
	nWidth = (rcWnd.right - rcWnd.left) + (nWidth - rcClient.right);
	nHeight = (rcWnd.bottom - rcWnd.top) + (nHeight - rcClient.bottom);
	return SetWindowPos(hwnd, NULL,
		0, 0, nWidth, nHeight, SWP_NOZORDER | SWP_NOMOVE);
}

//==[ CODE ]===================================================================
// CreateSimpleFont
HFONT CreateSimpleFont(int nPointSize, LPCTSTR lpszFace)
{
	return CreateFont(
		-MulDiv(nPointSize, GetDeviceCaps(GetDC(NULL), LOGPIXELSY), 72),
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, lpszFace);
}

//==[ CODE ]===================================================================
// SetChildWindowFont
BOOL CALLBACK SetChildWindowFont(HWND hwnd, LPARAM lParam)
{
	SendMessage(hwnd, WM_SETFONT, (WPARAM) lParam, TRUE);
	return TRUE;
}
