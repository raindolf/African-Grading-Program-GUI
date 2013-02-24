/**
 ******************************************************************************
 * $Id: design.h 34 2013-02-20 00:09:57Z mkwayisi $
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

#define IDC_WND_MAIN_W		310
#define IDC_WND_MAIN_H		130

#define IDC_EDT_MARKS_X		15
#define IDC_EDT_MARKS_Y		15
#define IDC_EDT_MARKS_W		(IDC_WND_MAIN_W - 30)
#define IDC_EDT_MARKS_H		22

#define IDC_LBL_GRADE_X		IDC_EDT_MARKS_X
#define IDC_LBL_GRADE_Y		(IDC_EDT_MARKS_Y + IDC_EDT_MARKS_H + 15)
#define IDC_LBL_GRADE_W		IDC_EDT_MARKS_W
#define IDC_LBL_GRADE_H		IDC_EDT_MARKS_H

#define IDC_BTN_CLOSE_W		100
#define IDC_BTN_CLOSE_H		26
#define IDC_BTN_CLOSE_X		(IDC_WND_MAIN_W - IDC_BTN_CLOSE_W - 15)
#define IDC_BTN_CLOSE_Y		(IDC_WND_MAIN_H - IDC_BTN_CLOSE_H - 12)
