#ifndef TIF_CONFIG_H
#define TIF_CONFIG_H

#if defined(LIBTIFF_LIB_BUILD)

/*
 * prevent automatic CRT/STL/MFC/ATL manifest dependencies generation
 *
 * see http://www.codeproject.com/KB/cpp/PrivateAssemblyProjects.aspx and
 * http://blog.m-ri.de/index.php/2008/05/06/hotfix-fuer-usemsprivateassembliesh-und-vc-2008/
 * by by Martin Richter for more information
 */

#if defined(_MSC_VER) && (_MSC_VER >= 1400) && !defined(UNDER_CE)
/* VC++ 2005 (8.0) or greater */

#define _CRT_NOFORCE_MANIFEST
#define _STL_NOFORCE_MANIFEST
#define _AFX_NOFORCE_MANIFEST
#define _ATL_NOFORCE_MANIFEST

#ifdef __cplusplus
extern "C"
{
#endif

__declspec(selectany) int _forceCRTManifest;
__declspec(selectany) int _forceMFCManifest;
__declspec(selectany) int _forceAtlDllManifest;

/* the next symbols are used by the several versions of VC++ 2008 (9.0) */
__declspec(selectany) int _forceCRTManifestRTM;
__declspec(selectany) int _forceMFCManifestRTM;
__declspec(selectany) int _forceMFCManifestCUR;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _MSC_VER && !UNDER_CE */

#endif /* LIBTIFF_LIB_BUILD */

/* Define to 1 if you have the <assert.h> header file. */
#define HAVE_ASSERT_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define as 0 or 1 according to the floating point format suported by the
   machine */
#define HAVE_IEEEFP 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <io.h> header file. */
#define HAVE_IO_H 1

/* Define to 1 if you have the <search.h> header file. */
#define HAVE_SEARCH_H 1

/* Define to 1 if you have the `setmode' function. */
#define HAVE_SETMODE 1

/* Define to 1 if you have the `memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

/* Signed 32-bit type formatter */
#define TIFF_INT32_FORMAT "%d"

/* Unsigned 32-bit type formatter */
#define TIFF_UINT32_FORMAT "%u"

/* Signed 64-bit type formatter */
#define TIFF_INT64_FORMAT "%ld"

/* Unsigned 64-bit type formatter */
#define TIFF_UINT64_FORMAT "%lu"

/* Pointer difference type formatter */
#define TIFF_PTRDIFF_FORMAT "%ld"

/* Signed size type formatter */
#define TIFF_SSIZE_FORMAT "%ld"

/*
-----------------------------------------------------------------------
Byte order
-----------------------------------------------------------------------
*/

/*
Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
significant byte first (like Motorola and SPARC, unlike Intel).
Some versions of gcc may have BYTE_ORDER or __BYTE_ORDER defined
If your big endian system isn't being detected, add an OS specific check
*/
#if (defined(BYTE_ORDER) && BYTE_ORDER==BIG_ENDIAN) || \
	(defined(__BYTE_ORDER) && __BYTE_ORDER==__BIG_ENDIAN) || \
	defined(__BIG_ENDIAN__)
/* Set the native cpu bit order (FILLORDER_LSB2MSB or FILLORDER_MSB2LSB) */
#define HOST_FILLORDER FILLORDER_MSB2LSB
/* Native cpu byte order: 1 if big-endian (Motorola) or 0 if little-endian (Intel) */
#define WORDS_BIGENDIAN 1
/* Native cpu byte order: 1 if big-endian (Motorola) or 0 if little-endian (Intel) */
#define HOST_BIGENDIAN 1
#else
/* Set the native cpu bit order (FILLORDER_LSB2MSB or FILLORDER_MSB2LSB) */
#define HOST_FILLORDER FILLORDER_LSB2MSB
/* Native cpu byte order: 1 if big-endian (Motorola) or 0 if little-endian (Intel) */
#undef WORDS_BIGENDIAN
/* Native cpu byte order: 1 if big-endian (Motorola) or 0 if little-endian (Intel) */
#undef HOST_BIGENDIAN
#endif // BYTE_ORDER

#ifdef _WIN32
#define snprintf _snprintf
#define lfind _lfind
#endif // _WIN32

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
# ifndef inline
#  define inline __inline
# endif
#endif


#endif // TIF_CONFIG_H
