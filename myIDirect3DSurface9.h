#pragma once

#include "StdAfx.h"

class myIDirect3DSurface9 :
	public IDirect3DSurface9
{
public:
	myIDirect3DSurface9(IDirect3DSurface9* pOriginal);
	virtual ~myIDirect3DSurface9(void);

	// START: The original DX9 function definitions
	HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObj);
    ULONG __stdcall AddRef();
    ULONG __stdcall Release();
    HRESULT __stdcall GetDevice(IDirect3DDevice9** ppDevice);
    HRESULT __stdcall SetPrivateData(REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags);
    HRESULT __stdcall GetPrivateData(REFGUID refguid,void* pData,DWORD* pSizeOfData);
    HRESULT __stdcall FreePrivateData(REFGUID refguid);
    DWORD __stdcall SetPriority(DWORD PriorityNew);
    DWORD __stdcall GetPriority();
    void __stdcall PreLoad();
    D3DRESOURCETYPE __stdcall GetType();
    HRESULT __stdcall GetContainer(REFIID riid,void** ppContainer);
    HRESULT __stdcall GetDesc(D3DSURFACE_DESC *pDesc);
    HRESULT __stdcall LockRect(D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags);
    HRESULT __stdcall UnlockRect();
    HRESULT __stdcall GetDC(HDC *phdc);
    HRESULT __stdcall ReleaseDC(HDC hdc);
	// END: The original DX9 function definitions

private:
    IDirect3DSurface9 *m_pIDirect3DSurface9;
	D3DLOCKED_RECT *m_pLockedRect;
};
