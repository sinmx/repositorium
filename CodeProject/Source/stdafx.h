// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__25D88527_2F22_4EDF_AE89_D4EF9AB307EC__INCLUDED_)
#define AFX_STDAFX_H__25D88527_2F22_4EDF_AE89_D4EF9AB307EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// unreferenced inline/local function has been removed
#pragma warning(disable: 4514)
// function not inlined
#pragma warning(disable: 4710)
// identifier was truncated in the debug information
#pragma warning(disable: 4786)

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

// MFC headers
#include <afxwin.h>
#include <afxcmn.h>
#include <afxdlgs.h>
#include <afxext.h>
#include <afxadv.h>
#include <afxconv.h>

// PSDK headers
#include <shlobj.h>

// STL headers
#pragma warning(push, 3)
#if (_MSC_VER <= 1200)
#include <typeinfo.h>
namespace std { using ::bad_cast; }
#else
#include <typeinfo>
#endif	// _MSC_VER
#include <vector>
#include <map>
#include <algorithm>
#pragma warning(pop)

#if !defined(min)
using std::min;
#endif	// min

#if !defined(max)
using std::max;
#endif	// max

#pragma hdrstop

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__25D88527_2F22_4EDF_AE89_D4EF9AB307EC__INCLUDED_)
