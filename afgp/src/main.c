/**
 ******************************************************************************
 * $Id: main.c 38 2013-02-20 00:32:35Z mkwayisi $
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

// Define _WIN32_IE to at least 0x0501
// so that we can use the common controls.
#ifndef _WIN32_IE
#define _WIN32_IE	0x0501
#endif

#include <windows.h>
#include <commctrl.h>
#include <tchar.h>

#include "libwin32.h"
#include "main.h"
#include "design.h"

//==[ CODE ]===================================================================
// WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	INITCOMMONCONTROLSEX iccex;
	WNDCLASSEX wcex;
	HFONT hFont;
	HWND hwnd;
	MSG msg;
	
	// Initialize common controls so as to ensure that we get XP+ theme
	iccex.dwSize = sizeof(INITCOMMONCONTROLSEX);
	iccex.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&iccex);
	
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.lpfnWndProc = WndProc;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDR_ICO_MAIN));
	wcex.hIconSm = (HICON) LoadImage(hInstance, MAKEINTRESOURCE(IDR_ICO_MAIN),
							IMAGE_ICON, 16, 16, 0);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = STR_WNDCLASS;
	wcex.hbrBackground = (HBRUSH) COLOR_BTNSHADOW;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, STR_WNDCLASSERROR, STR_APPTITLE, MB_OK | MB_ICONERROR);
		return 1;
	}
	
	hwnd = CreateWindowEx(0, STR_WNDCLASS, STR_APPTITLE,
		WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		0, 0, 400, 300, NULL, NULL, hInstance, NULL);
	
	if (hwnd == NULL) {
		MessageBox(NULL, STR_HWNDERROR, STR_APPTITLE, MB_OK | MB_ICONERROR);
		return 1;
	}
	
	hFont = CreateSimpleFont(9, TEXT("Segoe UI"));
	EnumChildWindows(hwnd, SetChildWindowFont, (LPARAM) hFont);
	
	ShowWindow(hwnd, SW_SHOWDEFAULT);
	UpdateWindow(hwnd);
	
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		if (!IsDialogMessage(hwnd, &msg)) {
			DispatchMessage(&msg);
		}
	}
	
	DeleteObject(hFont);
	
	return 0;
}

//==[ CODE ]===================================================================
// WndProc
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
		case WM_CREATE: {
			// Create various window controls.
			CreateWindowEx(WS_EX_CLIENTEDGE, WC_EDIT, NULL, WS_CHILD | WS_VISIBLE
				| WS_TABSTOP | ES_NUMBER,
				IDC_EDT_MARKS_X, IDC_EDT_MARKS_Y, IDC_EDT_MARKS_W, IDC_EDT_MARKS_H,
				hwnd, (HMENU) IDC_EDT_MARKS, GetModuleHandle(NULL), NULL);
			CreateWindowEx(0, UPDOWN_CLASS, NULL, WS_CHILD | WS_VISIBLE
				| UDS_AUTOBUDDY | UDS_SETBUDDYINT | UDS_ALIGNRIGHT | UDS_ARROWKEYS,
				0, 0, 0, 0,
				hwnd, (HMENU) IDC_UPD_MARKS, GetModuleHandle(NULL), NULL);
			CreateWindowEx(WS_EX_STATICEDGE, WC_STATIC, IDC_LBL_GRADE_T,
				WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,
				IDC_LBL_GRADE_X, IDC_LBL_GRADE_Y, IDC_LBL_GRADE_W, IDC_LBL_GRADE_H,
				hwnd, (HMENU) IDC_LBL_GRADE, GetModuleHandle(NULL), NULL);
			CreateWindowEx(0, WC_BUTTON, IDC_BTN_CLOSE_T, WS_CHILD | WS_VISIBLE
				| WS_TABSTOP,
				IDC_BTN_CLOSE_X, IDC_BTN_CLOSE_Y, IDC_BTN_CLOSE_W, IDC_BTN_CLOSE_H,
				hwnd, (HMENU) IDC_BTN_CLOSE, GetModuleHandle(NULL), NULL);
			
			// Let's put some constraint on our controls.
			SendDlgItemMessage(hwnd, IDC_EDT_MARKS, EM_SETLIMITTEXT, 3, 0);
			SendDlgItemMessage(hwnd, IDC_UPD_MARKS, UDM_SETRANGE, 0, MAKELONG(100, 0));
			
			// Some handy functions that come with libwin32!
			SetWindowClientSize(hwnd, IDC_WND_MAIN_W, IDC_WND_MAIN_H);
			CenterWindowToScreen(hwnd);
		}	break;
		
		case WM_COMMAND:
			switch (LOWORD(wParam)) {
				case IDC_EDT_MARKS:
					switch (HIWORD(wParam)) {
						case EN_CHANGE: {
							static TCHAR szBuffer[64];
							static PTCHAR pazGrades[] = {
								TEXT("A"),  TEXT("EXCELLENT"),
								TEXT("A-"), TEXT("VERY GOOD"),
								TEXT("B+"), TEXT("GOOD"),
								TEXT("B"),  TEXT("ABOVE AVERAGE"),
								TEXT("B-"), TEXT("AVERAGE"),
								TEXT("C+"), TEXT("PASS"),
								TEXT("C"),  TEXT("PASS"),
								TEXT("D"),  TEXT("FAIL"),
								TEXT("F"),  TEXT("FAIL"),
							};
							int i, marks;
							
							// Don't process if the edit box is empty.
							if (!GetDlgItemText(hwnd, IDC_EDT_MARKS,
								szBuffer, sizeof(szBuffer)/sizeof(*szBuffer)))
							{ break; }
							
							marks = _ttoi(szBuffer);
							if (marks > 100)
								i = -1;
							else if (marks >= 70)
								i = 0;
							else if (marks >= 65)
								i = 2;
							else if (marks >= 60)
								i = 4;
							else if (marks >= 55)
								i = 6;
							else if (marks >= 50)
								i = 8;
							else if (marks >= 45)
								i = 10;
							else if (marks >= 40)
								i = 12;
							else if (marks >= 30)
								i = 14;
							else i = 16;
							
							if (i < 0) {
								_tcscpy(szBuffer, STR_OUTOFRANGE);
							} else {
								_sntprintf(szBuffer,
									sizeof(szBuffer)/sizeof(*szBuffer),
										STR_GRADEFORMAT,
											pazGrades[i], pazGrades[i+1]);
							}
							
							SetDlgItemText(hwnd, IDC_LBL_GRADE, szBuffer);
						}	break;
					}
					break;
				
				case IDC_BTN_CLOSE:
					switch (HIWORD(wParam)) {
						case BN_CLICKED:
							SendMessage(hwnd, WM_CLOSE, 0, 0);
							break;
					}
					break;
			}
			break;
		
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	
	return 0;
}
