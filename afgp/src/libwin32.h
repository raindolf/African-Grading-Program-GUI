/**
 ******************************************************************************
 * $Id: libwin32.h 36 2013-02-20 00:15:00Z mkwayisi $
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

#ifndef _LIBWIN32_H
#define _LIBWIN32_H

VOID CenterWindowToScreen(HWND);
VOID CenterWindowToParent(HWND);
BOOL GetWindowSize(HWND, LPSIZE);
BOOL SetWindowSize(HWND, INT, INT);
BOOL GetWindowClientSize(HWND, LPSIZE);
BOOL SetWindowClientSize(HWND, INT, INT);
HFONT CreateSimpleFont(int, LPCTSTR);
BOOL CALLBACK SetChildWindowFont(HWND, LPARAM);

#endif
