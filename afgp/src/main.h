/**
 ******************************************************************************
 * $Id: main.h 37 2013-02-20 00:29:25Z mkwayisi $
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

#define IDR_ICO_MAIN		100
#define IDC_EDT_MARKS		101
#define IDC_UPD_MARKS		102
#define IDC_LBL_GRADE		103
#define IDC_BTN_CLOSE		104

// windres has problems with the TEXT macro
// so we have to define these macros explicitly.
#ifdef UNICODE
#define STR_APPNAME			L"African Grading Program"
#define STR_APPVERSION		L"0.4.0"
#define STR_APPTITLE		STR_APPNAME L" " STR_APPVERSION
#define STR_APPPUBLISHER	L"Michael Kwayisi"
#define STR_APPCOPYRIGHT	L"Copyright (c) 2013 " STR_APPPUBLISHER
#else
#define STR_APPNAME			"African Grading Program"
#define STR_APPVERSION		"0.4.0"
#define STR_APPTITLE		STR_APPNAME " " STR_APPVERSION
#define STR_APPPUBLISHER	"Michael Kwayisi"
#define STR_APPCOPYRIGHT	"Copyright (c) 2013 " STR_APPPUBLISHER
#endif

#define STR_WNDCLASS		TEXT("AfricanGPWndClass")
#define STR_WNDCLASSERROR	TEXT("Main window class registration failed!")
#define STR_HWNDERROR		TEXT("Main window creation failed!")
#define STR_OUTOFRANGE		TEXT("ERROR:  INPUTTED SCORE IS OUT OF RANGE!")
#define STR_GRADEFORMAT		TEXT("GRADE: %s   INTERPRETATION: %s")

#define IDC_LBL_GRADE_T		TEXT("PLEASE ENTER A SCORE ABOVE")
#define IDC_BTN_CLOSE_T		TEXT("&Close")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
