// Copyright (C) 2003-2011 AbstractSpoon Software.
//
// This license applies to everything in the ToDoList package, except where
// otherwise noted.
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software in a
// product, an acknowledgment in the product documentation would be appreciated
// but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.

//*****************************************************************************
// Modified by Elijah Zarezky aka SchweinDeBurg (elijah.zarezky@gmail.com):
// - improved compatibility with the Unicode-based builds
// - added AbstractSpoon Software copyright notice and license information
// - adjusted #include's paths
// - reformatted using Artistic Style 2.02 with the following options:
//      --indent=tab=3
//      --indent=force-tab=3
//      --indent-cases
//      --max-instatement-indent=2
//      --style=allman
//      --add-brackets
//      --pad-oper
//      --unpad-paren
//      --pad-header
//      --align-pointer=type
//      --lineend=windows
//      --suffix=none
// - merged with ToDoList version 6.1.2-6.2.2 sources
//*****************************************************************************

#if !defined(AFX_RTFCONTENTCONTROL_H__4F1A93A0_7829_4DBB_AA0B_A2F62E4E7F50__INCLUDED_)
#define AFX_RTFCONTENTCONTROL_H__4F1A93A0_7829_4DBB_AA0B_A2F62E4E7F50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RTFContentControl.h : header file
//

#include "RulerRichEditCtrl.h"

#include "../../Common/IContentControl.h"
#include "../../../CodeProject/Source/ToolbarHelper.h"
#include "../../Common/RichEditSpellCheck.h"

/////////////////////////////////////////////////////////////////////////////
// CRTFContentControl window

static LPCSTR RTFTAG = "{\\rtf";
static int LENTAG = strlen(RTFTAG);

class CRTFContentControl : public CRulerRichEditCtrl, public IContentControl
{
// Construction
public:
	CRTFContentControl();

	// ICustomControl implementation
	int GetContent(unsigned char* pContent) const;
	bool SetContent(unsigned char* pContent, int nLength, BOOL bResetSelection);
	int GetTextContent(TCHAR* szContent, int nLength = -1) const;
	bool SetTextContent(const TCHAR* szContent, BOOL bResetSelection);
	void SetReadOnly(bool bReadOnly);
	HWND GetHwnd() const;
	const char* GetTypeID() const;
	void Release();
	bool ProcessMessage(MSG* pMsg);
	ISpellCheck* GetSpellCheckInterface()
	{
		return &m_reSpellCheck;
	}
	bool Undo()
	{
		return GetRichEditCtrl().Undo() != 0;
	}
	bool Redo()
	{
		return GetRichEditCtrl().Redo() != 0;
	}
	void SetUITheme(const UITHEME* pTheme);
	void SavePreferences(IPreferences* pPrefs, LPCTSTR szKey) const;
	void LoadPreferences(const IPreferences* pPrefs, LPCTSTR szKey);

// Attributes
protected:
	BOOL m_bAllowNotify;
	CToolbarHelper m_tbHelper;
	CRichEditSpellCheck m_reSpellCheck;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRTFContentControl)
public:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRTFContentControl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRTFContentControl)
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	afx_msg void OnChangeText();
	afx_msg void OnKillFocus();
	afx_msg LRESULT OnSetFont(WPARAM wp, LPARAM lp);
	afx_msg void OnStyleChanging(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg LRESULT OnCustomUrl(WPARAM wp, LPARAM lp);

	DECLARE_MESSAGE_MAP()

	BOOL CanPaste();
	BOOL Paste(BOOL bSimple = FALSE);
	BOOL IsTDLClipboardEmpty() const;
	static int GetContent(const CRTFContentControl* pCtrl, unsigned char* pContent);
	static void EnableMenuItem(CMenu* pMenu, UINT nCmdID, BOOL bEnable);
	static void CheckMenuItem(CMenu* pMenu, UINT nCmdID, BOOL bCheck);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RTFCONTENTCONTROL_H__4F1A93A0_7829_4DBB_AA0B_A2F62E4E7F50__INCLUDED_)
