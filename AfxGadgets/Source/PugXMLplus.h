// AfxGadgets library.
// Copyright (c) 2005 by Elijah Zarezky,
// All rights reserved.

// PugXMLplus.h - PugXML parser extensions and wrappers

#if !defined(__PugXMLplus_h)
#define __PugXMLplus_h

#if !defined(_PugXML_)
#error PugXML.h must be included before this file
#endif	// _PugXML_

#if !defined(_AFX_ENABLE_INLINES)
inline
#else
__forceinline
#endif
LONG GetAttribute_LONG(CPugXmlBranch& branch, LPCTSTR pszName, LONG nDefault = 0, int nRadix = 0)
{
	LPTSTR pszStop;

	LPCTSTR pszValue = branch.GetAttribute(pszName);
	if (*pszValue != 0) {
		LONG nResult = _tcstol(pszValue, &pszStop, nRadix);
		if (*pszStop == 0) {
			return (nResult);
		}
	}
	return (nDefault);
}

#if !defined(_AFX_ENABLE_INLINES)
inline
#else
__forceinline
#endif
DWORD GetAttribute_DWORD(CPugXmlBranch& branch, LPCTSTR pszName, DWORD dwDefault = 0, int nRadix = 0)
{
	LPTSTR pszStop;

	LPCTSTR pszValue = branch.GetAttribute(pszName);
	if (*pszValue != 0) {
		LONG nResult = _tcstoul(pszValue, &pszStop, nRadix);
		if (*pszStop == 0) {
			return (nResult);
		}
	}
	return (dwDefault);
}

#if !defined(_AFX_ENABLE_INLINES)
inline
#else
__forceinline
#endif
BOOL GetAttribute_BOOL(CPugXmlBranch& branch, LPCTSTR pszName, BOOL fDefault = FALSE)
{
	LPCTSTR pszValue = branch.GetAttribute(pszName);
	return (*pszValue != 0 ? _tcschr(_T("1tTyY"), pszValue[0]) != NULL : fDefault);
}

#if !defined(_AFX_ENABLE_INLINES)
inline
#else
__forceinline
#endif
double GetAttribute_double(CPugXmlBranch& branch, LPCTSTR pszName, double fpDefault = 0.0)
{
	LPTSTR pszStop;

	LPCTSTR pszValue = branch.GetAttribute(pszName);
	if (*pszValue != 0) {
		double fpResult = _tcstod(pszValue, &pszStop);
		if (*pszStop == 0) {
			return (fpResult);
		}
	}
	return (fpDefault);
}

#if !defined(_AFX_ENABLE_INLINES)
inline
#else
__forceinline
#endif
short GetAttribute_short(CPugXmlBranch& branch, LPCTSTR pszName, short nDefault = 0, int nRadix = 0)
{
	return (static_cast<short>(GetAttribute_LONG(branch, pszName, nDefault, nRadix)));
}

#if !defined(_AFX_ENABLE_INLINES)
inline
#else
__forceinline
#endif
WORD GetAttribute_WORD(CPugXmlBranch& branch, LPCTSTR pszName, WORD wDefault = 0, int nRadix = 0)
{
	return (LOWORD(GetAttribute_DWORD(branch, pszName, wDefault, nRadix)));
}

#if !defined(_AFX_ENABLE_INLINES)
inline
#else
__forceinline
#endif
BYTE GetAttribute_BYTE(CPugXmlBranch& branch, LPCTSTR pszName, BYTE bDefault = 0, int nRadix = 0)
{
	return (LOBYTE(LOWORD(GetAttribute_DWORD(branch, pszName, bDefault, nRadix))));
}

#if !defined(_AFX_ENABLE_INLINES)
inline
#else
__forceinline
#endif
bool GetAttribute_bool(CPugXmlBranch& branch, LPCTSTR pszName, bool fDefault = false)
{
	return (GetAttribute_BOOL(branch, pszName, fDefault) != 0);
}

#endif	// __PugXMLplus_h

// end of file
