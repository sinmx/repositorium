// Copyright (C) 2003-2005 AbstractSpoon Software.
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

#if !defined(AFX_RICHEDITBASECTRL_H__E7F84BEA_24A6_42D4_BE92_4B8891484048__INCLUDED_)
#define AFX_RICHEDITBASECTRL_H__E7F84BEA_24A6_42D4_BE92_4B8891484048__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RichEditBaseCtrl.h : header file
//

#include <richole.h>

/////////////////////////////////////////////////////////////////////////////
// CRichEditBaseCtrl window

class FIND_STATE;  // private to implementation

class CRichEditBaseCtrl : public CRichEditCtrl
{
// Construction
public:
	CRichEditBaseCtrl();
	virtual ~CRichEditBaseCtrl();

	void DoEditFind(UINT nIDTitle = 0);
	void DoEditReplace(UINT nIDTitle = 0);
	
	BOOL Undo();
	BOOL Redo();

	// Attributes
protected:
	long m_lInitialSearchPos;
	BOOL m_bFirstSearch;
	
	struct FIND_STATE
	{
		FIND_STATE() : pFindReplaceDlg(NULL), bFindOnly(FALSE), bCase(FALSE), bNext(TRUE), bWord(FALSE) { }

		CFindReplaceDialog* pFindReplaceDlg; // find or replace dialog
		BOOL bFindOnly; // Is pFindReplace the find or replace?
		CString strFind;    // last find string
		CString strReplace; // last replace string
		BOOL bCase; // TRUE==case sensitive, FALSE==not
		int bNext;  // TRUE==search down, FALSE== search up
		BOOL bWord; // TRUE==match whole word, FALSE==not
	};
	FIND_STATE m_findState;
	
	// Operations
public:
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRichEditBaseCtrl)
protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	class CRichEditOleCallback : public IRichEditOleCallback
	{
	public:
		CRichEditOleCallback();
		virtual ~CRichEditOleCallback();
		
		void SetOwner(CRichEditBaseCtrl* pOwner) { m_pOwner = pOwner; }
		
		// IRichEditOleCallback
		virtual HRESULT STDMETHODCALLTYPE GetNewStorage(LPSTORAGE* lplpstg);
		virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void ** ppvObject);
		virtual ULONG   STDMETHODCALLTYPE AddRef();
		virtual ULONG   STDMETHODCALLTYPE Release();
		virtual HRESULT STDMETHODCALLTYPE GetInPlaceContext(LPOLEINPLACEFRAME FAR *lplpFrame,
			LPOLEINPLACEUIWINDOW FAR *lplpDoc, LPOLEINPLACEFRAMEINFO lpFrameInfo);
		virtual HRESULT STDMETHODCALLTYPE ShowContainerUI(BOOL fShow);
		virtual HRESULT STDMETHODCALLTYPE QueryInsertObject(LPCLSID lpclsid, LPSTORAGE lpstg, LONG cp);
		virtual HRESULT STDMETHODCALLTYPE DeleteObject(LPOLEOBJECT lpoleobj);
		virtual HRESULT STDMETHODCALLTYPE QueryAcceptData(LPDATAOBJECT lpdataobj, CLIPFORMAT FAR *lpcfFormat,
			DWORD reco, BOOL fReally, HGLOBAL hMetaPict);
		virtual HRESULT STDMETHODCALLTYPE ContextSensitiveHelp(BOOL fEnterMode);
		virtual HRESULT STDMETHODCALLTYPE GetClipboardData(CHARRANGE FAR *lpchrg, DWORD reco, LPDATAOBJECT FAR *lplpdataobj);
		virtual HRESULT STDMETHODCALLTYPE GetDragDropEffect(BOOL fDrag, DWORD grfKeyState, LPDWORD pdwEffect);
		virtual HRESULT STDMETHODCALLTYPE GetContextMenu(WORD seltyp, LPOLEOBJECT lpoleobj, CHARRANGE FAR *lpchrg,
			HMENU FAR *lphmenu);
		
	protected:
		int m_iNumStorages;
		IStorage* m_pStorage;
		DWORD m_dwRef;
		CRichEditBaseCtrl* m_pOwner;
	};
	
	friend class CRichEditOleCallback;
	
protected:
	CRichEditOleCallback m_callback;
	
	// Generated message map functions
protected:
	virtual HRESULT GetNewStorage(LPSTORAGE* /*lplpstg*/) { return S_OK; }
	virtual HRESULT GetInPlaceContext(LPOLEINPLACEFRAME FAR* /*lplpFrame*/,
		LPOLEINPLACEUIWINDOW FAR* /*lplpDoc*/, LPOLEINPLACEFRAMEINFO /*lpFrameInfo*/) { return S_OK; }
	virtual HRESULT ShowContainerUI(BOOL /*fShow*/) { return S_OK; }
	virtual HRESULT QueryInsertObject(LPCLSID /*lpclsid*/, LPSTORAGE /*lpstg*/, LONG /*cp*/) { return S_OK; }
	virtual HRESULT DeleteObject(LPOLEOBJECT /*lpoleobj*/) { return S_OK; }
	virtual HRESULT QueryAcceptData(LPDATAOBJECT /*lpdataobj*/, CLIPFORMAT FAR* /*lpcfFormat*/,
		DWORD /*reco*/, BOOL /*fReally*/, HGLOBAL /*hMetaPict*/) { return S_OK; }
	virtual HRESULT ContextSensitiveHelp(BOOL /*fEnterMode*/) { return S_OK; }
	virtual HRESULT GetClipboardData(CHARRANGE FAR* /*lpchrg*/, DWORD /*reco*/, LPDATAOBJECT FAR* /*lplpdataobj*/) { return E_NOTIMPL; }
	virtual HRESULT GetDragDropEffect(BOOL /*fDrag*/, DWORD /*grfKeyState*/, LPDWORD /*pdwEffect*/) { return S_OK; }
	virtual HRESULT GetContextMenu(WORD /*seltyp*/, LPOLEOBJECT /*lpoleobj*/, CHARRANGE FAR* /*lpchrg*/,
		HMENU FAR* /*lphmenu*/) { return S_OK; }
	
	virtual void OnFindNext(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord);
	virtual void OnReplaceSel(LPCTSTR lpszFind, BOOL bNext, BOOL bCase,
		BOOL bWord, LPCTSTR lpszReplace);
	virtual void OnReplaceAll(LPCTSTR lpszFind, LPCTSTR lpszReplace,
		BOOL bCase, BOOL bWord);
	virtual void OnTextNotFound(LPCTSTR lpszFind);
	
	//{{AFX_MSG(CRichEditBaseCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	afx_msg LRESULT OnFindReplaceCmd(WPARAM, LPARAM lParam);
	
	DECLARE_MESSAGE_MAP()
		
		
	void AdjustDialogPosition(CDialog* pDlg);
	BOOL FindText(LPCTSTR lpszFind, BOOL bCase = TRUE, BOOL bWord = TRUE);
	BOOL FindTextSimple(LPCTSTR lpszFind, BOOL bCase = TRUE,
		BOOL bWord = TRUE);
	void TextNotFound(LPCTSTR lpszFind);
	BOOL FindText();
	BOOL FindTextSimple();
	long FindAndSelect(DWORD dwFlags, FINDTEXTEX& ft);
	void DoEditFindReplace(BOOL bFindOnly, UINT nIDTitle);
	BOOL SameAsSelected(LPCTSTR lpszCompare, BOOL bCase, BOOL bWord);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RICHEDITBASECTRL_H__E7F84BEA_24A6_42D4_BE92_4B8891484048__INCLUDED_)
