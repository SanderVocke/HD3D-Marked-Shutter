// stdafx.h 
#pragma once

#define WIN32_LEAN_AND_MEAN		
#include <windows.h>

#include "d3d9.h"
#include "myIDirect3D9.h"
#include "myIDirect3DDevice9.h"
#include "myIDirect3DSurface9.h"

#define SIZEOF_ARRAY( a ) (sizeof( a ) / sizeof( a[ 0 ] ))

enum{
	MARK_TOPLEFT = 0,
	MARK_TOPRIGHT,
	MARK_BOTTOMLEFT,
	MARK_BOTTOMRIGHT,
	MARK_TESTPATTERN
};

const LPTSTR MARKTYPES[] = {
	"TopLeft",
	"TopRight",
	"BottomLeft",
	"BottomRight",
	"TestPattern"
};

typedef struct PROXYDLL_SETTINGS_t{
	DWORD MarkType; //location of the shutterglass marker (see enum above)
	DWORD MarkSizeX; //in pixels
	DWORD MarkSizeY; //in pixels
}PROXYDLL_SETTINGS;
#define STD_MARKLOCATION (MARK_TOPLEFT)
#define STD_MARKSIZEX (25)
#define STD_MARKSIZEY (25)
#define CHECKERBOARD_RECTSIZE (25)
#define INI_FILE_SUBPATH (_T("\MarkInjector.ini"))

#define MAKED3DRECT(rect, X1, Y1, X2, Y2) {rect.x1 = X1; rect.x2 = X2; rect.y1 = Y1; rect.y2 = Y2;}

//settings, accessible everywhere
extern PROXYDLL_SETTINGS gl_Settings;
