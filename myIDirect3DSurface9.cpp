#include "StdAfx.h"
#include "AtiDx9Stereo.h"
#include "myIDirect3DSurface9.h"
#include <stdio.h>


myIDirect3DSurface9::myIDirect3DSurface9(IDirect3DSurface9* pOriginal)
{
	m_pIDirect3DSurface9 = pOriginal; // store the pointer to original object
}


myIDirect3DSurface9::~myIDirect3DSurface9(void)
{
}

HRESULT __stdcall myIDirect3DSurface9::QueryInterface(REFIID riid, void** ppvObj)
{
	// check if original dll can provide interface. then send *our* address
	*ppvObj = NULL;

	HRESULT hRes = m_pIDirect3DSurface9->QueryInterface(riid, ppvObj); 

	if (hRes == NOERROR)
	{
		*ppvObj = this;
	}
	
	return hRes;
}
ULONG __stdcall myIDirect3DSurface9::AddRef()
{
	return(m_pIDirect3DSurface9->AddRef());
}
ULONG __stdcall myIDirect3DSurface9::Release()
{
	// ATTENTION: This is a booby-trap ! Watch out !
	// If we create our own sprites, surfaces, etc. (thus increasing the ref counter
	// by external action), we need to delete that objects before calling the original
	// Release function	

    // release/delete own objects
    // .....
	
	// Calling original function now
	ULONG count = m_pIDirect3DSurface9->Release();
		
    // now, the Original Object has deleted itself, so do we here
	//delete(this);  // destructor will be called automatically

	return (count);
}
HRESULT __stdcall myIDirect3DSurface9::GetDevice(IDirect3DDevice9** ppDevice)
{
	return(m_pIDirect3DSurface9->GetDevice(ppDevice));
}
HRESULT __stdcall myIDirect3DSurface9::SetPrivateData(REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags)
{
	return(m_pIDirect3DSurface9->SetPrivateData(refguid,pData,SizeOfData,Flags));
}
HRESULT __stdcall myIDirect3DSurface9::GetPrivateData(REFGUID refguid,void* pData,DWORD* pSizeOfData)
{
	return(m_pIDirect3DSurface9->GetPrivateData(refguid,pData,pSizeOfData));
}
HRESULT __stdcall myIDirect3DSurface9::FreePrivateData(REFGUID refguid)
{
	return(m_pIDirect3DSurface9->FreePrivateData(refguid));
}
DWORD __stdcall myIDirect3DSurface9::SetPriority(DWORD PriorityNew)
{
	return(m_pIDirect3DSurface9->SetPriority(PriorityNew));
}
DWORD __stdcall myIDirect3DSurface9::GetPriority()
{
	return(m_pIDirect3DSurface9->GetPriority());
}
void __stdcall myIDirect3DSurface9::PreLoad()
{
	return(m_pIDirect3DSurface9->PreLoad());
}
D3DRESOURCETYPE __stdcall myIDirect3DSurface9::GetType()
{
	return(m_pIDirect3DSurface9->GetType());
}
HRESULT __stdcall myIDirect3DSurface9::GetContainer(REFIID riid,void** ppContainer)
{
	return(m_pIDirect3DSurface9->GetContainer(riid,ppContainer));
}
HRESULT __stdcall myIDirect3DSurface9::GetDesc(D3DSURFACE_DESC *pDesc)
{
	return(m_pIDirect3DSurface9->GetDesc(pDesc));
}
HRESULT __stdcall myIDirect3DSurface9::LockRect(D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags)
{
	HRESULT hres = (m_pIDirect3DSurface9->LockRect(pLockedRect,pRect,Flags));
	m_pLockedRect = pLockedRect;
	return hres;
}
HRESULT __stdcall myIDirect3DSurface9::UnlockRect()
{
	ATIDX9STEREOCOMMPACKET *pCommPacket = (ATIDX9STEREOCOMMPACKET *)((*m_pLockedRect).pBits);
	DWORD * outBuf = NULL;

	if(pCommPacket->dwSignature == 'STER' && pCommPacket->stereoCommand == ATI_STEREO_GETLINEOFFSET){
		OutputDebugString("Intercepting LineOffset...");
		outBuf = (DWORD*) pCommPacket->pOutBuffer;
	}

	HRESULT hres = (m_pIDirect3DSurface9->UnlockRect());

	if(outBuf != NULL){
		if(*outBuf > 0){
			char msg[100];
			sprintf(msg, "LineOffset found: %d", *outBuf);
			OutputDebugString(msg);
			extern DWORD gl_LineOffset;
			gl_LineOffset = *outBuf;
		}
	}

	return hres;
}
HRESULT __stdcall myIDirect3DSurface9::GetDC(HDC *phdc)
{
	return(m_pIDirect3DSurface9->GetDC(phdc));
}
HRESULT __stdcall myIDirect3DSurface9::ReleaseDC(HDC hdc)
{
	return(m_pIDirect3DSurface9->ReleaseDC(hdc));
}