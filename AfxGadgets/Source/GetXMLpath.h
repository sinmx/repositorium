// AfxGadgets library.
// Copyright (c) 2005-2006 by Elijah Zarezky,
// All rights reserved.

// GetXMLpath.h - template "proxy"-classes for the XML-based interface

#if !defined(__GetXMLpath_h)
#define __GetXMLpath_h

#if defined(_MSC_VER) && (_MSC_VER > 1000)
#pragma once
#endif	// _MSC_VER

typedef void(__cdecl* PFN_GetXMLpath)(CString& strDest);

#if defined(__DialogXML_h)

template <PFN_GetXMLpath pfnGetXMLpath>
class CDialogXML_t: public CDialogXML
{
// construction/destruction
public:
	CDialogXML_t(LPCTSTR pszDialogName, CWnd* pParentWnd = NULL);
	virtual ~CDialogXML_t(void);

// overridables
protected:
	virtual void GetXMLpath(CString& strDest);
};

template <PFN_GetXMLpath pfnGetXMLpath>
inline CDialogXML_t<pfnGetXMLpath>::CDialogXML_t(LPCTSTR pszDialogName, CWnd* pParentWnd):
CDialogXML(pszDialogName, pParentWnd)
{
}

template <PFN_GetXMLpath pfnGetXMLpath>
CDialogXML_t<pfnGetXMLpath>::~CDialogXML_t(void)
{
}

template <PFN_GetXMLpath pfnGetXMLpath>
void CDialogXML_t<pfnGetXMLpath>::GetXMLpath(CString& strDest)
{
	ASSERT(pfnGetXMLpath != NULL);
	(*pfnGetXMLpath)(strDest);
}

#endif	// __DialogXML_h

#if defined(__MenuXML_h)

template <PFN_GetXMLpath pfnGetXMLpath>
class CMenuXML_t: public CMenuXML
{
// construction/destruction
public:
	CMenuXML_t(void);
	virtual ~CMenuXML_t(void);

// overridables
protected:
	virtual void GetXMLpath(CString& strDest);
};

template <PFN_GetXMLpath pfnGetXMLpath>
inline CMenuXML_t<pfnGetXMLpath>::CMenuXML_t(void)
{
}

template <PFN_GetXMLpath pfnGetXMLpath>
CMenuXML_t<pfnGetXMLpath>::~CMenuXML_t(void)
{
}

template <PFN_GetXMLpath pfnGetXMLpath>
void CMenuXML_t<pfnGetXMLpath>::GetXMLpath(CString& strDest)
{
	ASSERT(pfnGetXMLpath != NULL);
	(*pfnGetXMLpath)(strDest);
}

#endif	// __MenuXML_h

#if defined(__HotKeysXML_h)

template <PFN_GetXMLpath pfnGetXMLpath>
class CHotKeysXML_t: public CHotKeysXML
{
// construction/destruction
public:
	CHotKeysXML_t(void);
	virtual ~CHotKeysXML_t(void);

// overridables
protected:
	virtual void GetXMLpath(CString& strDest);
};

template <PFN_GetXMLpath pfnGetXMLpath>
inline CHotKeysXML_t<pfnGetXMLpath>::CHotKeysXML_t(void)
{
}

template <PFN_GetXMLpath pfnGetXMLpath>
CHotKeysXML_t<pfnGetXMLpath>::~CHotKeysXML_t(void)
{
}

template <PFN_GetXMLpath pfnGetXMLpath>
void CHotKeysXML_t<pfnGetXMLpath>::GetXMLpath(CString& strDest)
{
	ASSERT(pfnGetXMLpath != NULL);
	(*pfnGetXMLpath)(strDest);
}

#endif	// __HotKeysXML_h

#if defined(__StringsXML_h)

template <PFN_GetXMLpath pfnGetXMLpath>
class CStringsXML_t: public CStringsXML
{
// construction/destruction
public:
	CStringsXML_t(LPCTSTR pszStringsName);
	virtual ~CStringsXML_t(void);

// overridables
protected:
	virtual void GetXMLpath(CString& strDest);
};

template <PFN_GetXMLpath pfnGetXMLpath>
inline CStringsXML_t<pfnGetXMLpath>::CStringsXML_t(LPCTSTR pszStringsName):
CStringsXML(pszStringsName)
{
}

template <PFN_GetXMLpath pfnGetXMLpath>
CStringsXML_t<pfnGetXMLpath>::~CStringsXML_t(void)
{
}

template <PFN_GetXMLpath pfnGetXMLpath>
void CStringsXML_t<pfnGetXMLpath>::GetXMLpath(CString& strDest)
{
	ASSERT(pfnGetXMLpath != NULL);
	(*pfnGetXMLpath)(strDest);
}

#endif	// __StringsXML_h

#endif	// __GetXMLpath_h

// end of file
