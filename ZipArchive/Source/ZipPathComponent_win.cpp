////////////////////////////////////////////////////////////////////////////////
// This source file is part of the ZipArchive library source distribution and
// is Copyrighted 2000 - 2012 by Artpol Software - Tadeusz Dracz
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// For the licensing details refer to the License.txt file.
//
// Web Site: http://www.artpol-software.com
////////////////////////////////////////////////////////////////////////////////
// Modified by Elijah Zarezky aka SchweinDeBurg (elijah.zarezky@gmail.com):
// - reformatted using Artistic Style 2.02 with the following options:
//      --indent=tab=3
//      --indent=force-tab=3
//      --indent-cases
//      --min-conditional-indent=0
//      --max-instatement-indent=2
//      --style=allman
//      --add-brackets
//      --pad-oper
//      --unpad-paren
//      --pad-header
//      --align-pointer=type
//      --lineend=windows
//      --suffix=none
// - implemented support for the Windows Mobile/CE tragets
// - added possibility to seamless usage in the ATL-based projects
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#ifdef _ZIP_SYSTEM_WIN

#include "_platform.h"
#include "ZipPathComponent.h"

const CZipString CZipPathComponent::PathPrefix =  _T("\\\\?\\unc\\");

CZipPathComponent::~CZipPathComponent()
{

}

int CZipPathComponent::IsPrefixed(const CZipString& path)
{
	int i = -1, iLen = PathPrefix.GetLength();
	int pathLen = path.GetLength();
	if (iLen > pathLen)
	{
		iLen = pathLen;
	}
	CZipString szPossiblePrefix = path.Left(iLen);
	szPossiblePrefix.MakeLower(); // must perform case insensitive comparison
	while (++i < iLen && szPossiblePrefix[i] == PathPrefix[i]);
	return i;
}

#if defined _UNICODE && _MSC_VER >= 1400

CZipString CZipPathComponent::AddPrefix(LPCTSTR path, bool isFolder)
{

	CZipString ret = path;
	AddPrefix(ret, isFolder);
	return ret;
}

void CZipPathComponent::AddPrefix(CZipString& path, bool isFolder)
{

	if (path.GetLength() >= (isFolder ? 248 : MAX_PATH))
	{
		int prefixLength = IsPrefixed(path);
		if (prefixLength < ptUnicode)
		{
			if (prefixLength == ptUnc)
			{
				path = path.Mid(prefixLength);
				// long UNC
				path.Insert(0, PathPrefix.Left(CZipPathComponent::ptUncWin));
			}
			else
			{
				path.Insert(0, PathPrefix.Left(CZipPathComponent::ptUnicode));
			}
		}
	}
}


#else

CZipString CZipPathComponent::AddPrefix(LPCTSTR path, bool)
{
	return path;
}

void CZipPathComponent::AddPrefix(CZipString&, bool)
{

}

#endif

void CZipPathComponent::SetFullPath(LPCTSTR lpszFullPath)
{
	TCHAR szDrive[_MAX_DRIVE];
#if defined _UNICODE && _MSC_VER >= 1400 && !defined(UNDER_CE)
	TCHAR szDir[32767];
#else
	TCHAR szDir[_MAX_DIR];
#endif
	TCHAR szFname[_MAX_FNAME];
	TCHAR szExt[_MAX_EXT];


	CZipString szTempPath(lpszFullPath);
	int i = IsPrefixed(szTempPath);
	if (i == ptUnc || i == ptUnicode || i == ptUncWin) // unc path, Unicode path or unc path meeting windows file name conventions
	{
		m_szPrefix = szTempPath.Left(i);
		szTempPath = szTempPath.Mid(i);
	}
	else
	{
		m_szPrefix.Empty();
	}
#if (_MSC_VER >= 1400)
#if !defined(UNDER_CE)
	_tsplitpath_s(szTempPath, szDrive, szDir, szFname, szExt);
#else
	_tsplitpath_s(szTempPath, szDrive, _MAX_DRIVE, szDir, _MAX_DIR, szFname, _MAX_FNAME, szExt, _MAX_EXT);
#endif   // UNDER_CE
#else
	_tsplitpath(szTempPath, szDrive, szDir, szFname, szExt);
#endif

	m_szDrive = szDrive;
	m_szDirectory = szDir;

	m_szDirectory.TrimLeft(m_cSeparator);
	m_szDirectory.TrimRight(m_cSeparator);
	SetExtension(szExt);
	m_szFileTitle = szFname;
}


CZipString CZipPathComponent::GetNoDrive() const
{
	CZipString szPath = m_szDirectory;
	CZipString szFileName = GetFileName();
	if (!szFileName.IsEmpty() && !szPath.IsEmpty())
	{
		szPath += m_cSeparator;
	}

	szPath += szFileName;
	return szPath;
}

#endif // _ZIP_SYSTEM_WIN
