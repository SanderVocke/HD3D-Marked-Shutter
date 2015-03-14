#include "StdAfx.h"
#include "myIDirect3DDevice9.h"
#include "AtiDx9Stereo.h"
#include <stdio.h>

myIDirect3DDevice9::myIDirect3DDevice9(IDirect3DDevice9* pOriginal)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::myIDirect3DDevice9 called!");
#endif

    m_pIDirect3DDevice9 = pOriginal; // store the pointer to original object
	extern DWORD gl_LineOffset;
	gl_LineOffset = 0;
}

myIDirect3DDevice9::~myIDirect3DDevice9(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::~myIDirect3DDevice9 called!");
#endif
}

HRESULT myIDirect3DDevice9::QueryInterface (REFIID riid, void** ppvObj)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::QueryInterface called!");
#endif

    // check if original dll can provide interface. then send *our* address
	*ppvObj = NULL;

	HRESULT hRes = m_pIDirect3DDevice9->QueryInterface(riid, ppvObj); 

	if (hRes == NOERROR)
	{
		*ppvObj = this;
	}
	
	return hRes;
}

ULONG myIDirect3DDevice9::AddRef(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::AddRef called!");
#endif

    return(m_pIDirect3DDevice9->AddRef());
}

ULONG myIDirect3DDevice9::Release(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::Release called!");
#endif

	// ATTENTION: This is a booby-trap ! Watch out !
	// If we create our own sprites, surfaces, etc. (thus increasing the ref counter
	// by external action), we need to delete that objects before calling the original
	// Release function	
	
	// global var
	extern myIDirect3DDevice9* gl_pmyIDirect3DDevice9;

    // release/delete own objects
    // .....
	
	// Calling original function now
	ULONG count = m_pIDirect3DDevice9->Release();
		
    // now, the Original Object has deleted itself, so do we here
	gl_pmyIDirect3DDevice9 = NULL;
	//delete(this);  // destructor will be called automatically

	return (count);
}

HRESULT myIDirect3DDevice9::TestCooperativeLevel(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::TestCooperativeLevel called!");
#endif

    return(m_pIDirect3DDevice9->TestCooperativeLevel());
}

UINT myIDirect3DDevice9::GetAvailableTextureMem(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetAvailableTextureMem called!");
#endif

    return(m_pIDirect3DDevice9->GetAvailableTextureMem());
}

HRESULT myIDirect3DDevice9::EvictManagedResources(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::EvictManagedResources called!");
#endif

    return(m_pIDirect3DDevice9->EvictManagedResources());
}

HRESULT myIDirect3DDevice9::GetDirect3D(IDirect3D9** ppD3D9)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetDirect3D called!");
#endif

    return(m_pIDirect3DDevice9->GetDirect3D(ppD3D9));
}

HRESULT myIDirect3DDevice9::GetDeviceCaps(D3DCAPS9* pCaps)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetDeviceCaps called!");
#endif

    return(m_pIDirect3DDevice9->GetDeviceCaps(pCaps));
}

HRESULT myIDirect3DDevice9::GetDisplayMode(UINT iSwapChain,D3DDISPLAYMODE* pMode)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetDisplayMode called!");
#endif

    return(m_pIDirect3DDevice9->GetDisplayMode(iSwapChain, pMode));
}

HRESULT myIDirect3DDevice9::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetCreationParameters called!");
#endif

    return(m_pIDirect3DDevice9->GetCreationParameters(pParameters));
}

HRESULT myIDirect3DDevice9::SetCursorProperties(UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetCursorProperties called!");
#endif

    return(m_pIDirect3DDevice9->SetCursorProperties(XHotSpot,YHotSpot,pCursorBitmap));
}

void    myIDirect3DDevice9::SetCursorPosition(int X,int Y,DWORD Flags)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetCursorPosition called!");
#endif

    return(m_pIDirect3DDevice9->SetCursorPosition(X,Y,Flags));
}

BOOL    myIDirect3DDevice9::ShowCursor(BOOL bShow)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::ShowCursor called!");
#endif

    return(m_pIDirect3DDevice9->ShowCursor(bShow));
}

HRESULT myIDirect3DDevice9::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain)  
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateAdditionalSwapChain called!");
#endif

    return(m_pIDirect3DDevice9->CreateAdditionalSwapChain(pPresentationParameters,pSwapChain));
}

HRESULT myIDirect3DDevice9::GetSwapChain(UINT iSwapChain,IDirect3DSwapChain9** pSwapChain)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetSwapChain called!");
#endif

    return(m_pIDirect3DDevice9->GetSwapChain(iSwapChain,pSwapChain));
}

UINT    myIDirect3DDevice9::GetNumberOfSwapChains(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetNumberOfSwapChains called!");
#endif

    return(m_pIDirect3DDevice9->GetNumberOfSwapChains());
}

HRESULT myIDirect3DDevice9::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::Reset called!");
#endif

    return(m_pIDirect3DDevice9->Reset(pPresentationParameters));
}

HRESULT myIDirect3DDevice9::Present(CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::Present called!");
#endif

#ifndef MYDIRECT3DDEVICE_PASSTHROUGH
    // we may want to draw own things here before flipping surfaces
    // ... draw own stuff ...
	this->ShowWeAreHere();
#endif
    
    // call original routine
	HRESULT hres = m_pIDirect3DDevice9->Present( pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);

	return (hres);
}

HRESULT myIDirect3DDevice9::GetBackBuffer(UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetBackBuffer called!");
#endif

    return(m_pIDirect3DDevice9->GetBackBuffer(iSwapChain,iBackBuffer,Type,ppBackBuffer));
}

HRESULT myIDirect3DDevice9::GetRasterStatus(UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetRasterStatus called!");
#endif

    return(m_pIDirect3DDevice9->GetRasterStatus(iSwapChain,pRasterStatus));
}

HRESULT myIDirect3DDevice9::SetDialogBoxMode(BOOL bEnableDialogs)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetDialogBoxMode called!");
#endif

    return(m_pIDirect3DDevice9->SetDialogBoxMode(bEnableDialogs));
}

void    myIDirect3DDevice9::SetGammaRamp(UINT iSwapChain,DWORD Flags,CONST D3DGAMMARAMP* pRamp)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetGammaRamp called!");
#endif

    return(m_pIDirect3DDevice9->SetGammaRamp(iSwapChain,Flags,pRamp));
}

void    myIDirect3DDevice9::GetGammaRamp(UINT iSwapChain,D3DGAMMARAMP* pRamp)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetGammaRamp called!");
#endif

    return(m_pIDirect3DDevice9->GetGammaRamp(iSwapChain,pRamp));
}

HRESULT myIDirect3DDevice9::CreateTexture(UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateTexture called!");
#endif

    return(m_pIDirect3DDevice9->CreateTexture(Width,Height,Levels,Usage,Format,Pool,ppTexture,pSharedHandle));
}

HRESULT myIDirect3DDevice9::CreateVolumeTexture(UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateVolumeTexture called!");
#endif

    return(m_pIDirect3DDevice9->CreateVolumeTexture(Width,Height,Depth,Levels,Usage,Format,Pool,ppVolumeTexture,pSharedHandle));
}

HRESULT myIDirect3DDevice9::CreateCubeTexture(UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateCubeTexture called!");
#endif

    return(m_pIDirect3DDevice9->CreateCubeTexture(EdgeLength,Levels,Usage,Format,Pool,ppCubeTexture,pSharedHandle));
}

HRESULT myIDirect3DDevice9::CreateVertexBuffer(UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateVertexBuffer called!");
#endif

    return(m_pIDirect3DDevice9->CreateVertexBuffer(Length,Usage,FVF,Pool,ppVertexBuffer,pSharedHandle));
}

HRESULT myIDirect3DDevice9::CreateIndexBuffer(UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateIndexBuffer called!");
#endif

    return(m_pIDirect3DDevice9->CreateIndexBuffer(Length,Usage,Format,Pool,ppIndexBuffer,pSharedHandle));
}

HRESULT myIDirect3DDevice9::CreateRenderTarget(UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateRenderTarget called!");
#endif

    return(m_pIDirect3DDevice9->CreateRenderTarget(Width,Height,Format,MultiSample,MultisampleQuality,Lockable,ppSurface,pSharedHandle));
}

HRESULT myIDirect3DDevice9::CreateDepthStencilSurface(UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateDepthStencilSurface called!");
#endif

    return(m_pIDirect3DDevice9->CreateDepthStencilSurface(Width,Height,Format,MultiSample,MultisampleQuality,Discard,ppSurface,pSharedHandle));
}

HRESULT myIDirect3DDevice9::UpdateSurface(IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,CONST POINT* pDestPoint)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::UpdateSurface called!");
#endif

    return(m_pIDirect3DDevice9->UpdateSurface(pSourceSurface,pSourceRect,pDestinationSurface,pDestPoint));
}

HRESULT myIDirect3DDevice9::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::UpdateTexture called!");
#endif

    return(m_pIDirect3DDevice9->UpdateTexture(pSourceTexture,pDestinationTexture));
}

HRESULT myIDirect3DDevice9::GetRenderTargetData(IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetRenderTargetData called!");
#endif

    return(m_pIDirect3DDevice9->GetRenderTargetData(pRenderTarget,pDestSurface));
}

HRESULT myIDirect3DDevice9::GetFrontBufferData(UINT iSwapChain,IDirect3DSurface9* pDestSurface)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetFrontBufferData called!");
#endif

    return(m_pIDirect3DDevice9->GetFrontBufferData(iSwapChain,pDestSurface));
}

HRESULT myIDirect3DDevice9::StretchRect(IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestSurface,CONST RECT* pDestRect,D3DTEXTUREFILTERTYPE Filter)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::StretchRect called!");
#endif

    return(m_pIDirect3DDevice9->StretchRect(pSourceSurface,pSourceRect,pDestSurface,pDestRect,Filter));
}

HRESULT myIDirect3DDevice9::ColorFill(IDirect3DSurface9* pSurface,CONST RECT* pRect,D3DCOLOR color)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::ColorFill called!");
#endif

    return(m_pIDirect3DDevice9->ColorFill(pSurface,pRect,color));
}

HRESULT myIDirect3DDevice9::CreateOffscreenPlainSurface(UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateOffscreenPlainSurface called!");
#endif

	if(Format == (D3DFORMAT)FOURCC_AQBS){
		OutputDebugString("AMD HD3D Comms Surface intercepted!");
		// global var
		extern myIDirect3DSurface9* gl_pmyIDirect3DSurface9;

		// we intercept this call and provide our own "fake" Device Object
		HRESULT hres = m_pIDirect3DDevice9->CreateOffscreenPlainSurface(Width,Height,Format,Pool,ppSurface,pSharedHandle);
		
		// Create our own Device object and store it in global pointer
		// note: the object will delete itself once Ref count is zero (similar to COM objects)
		gl_pmyIDirect3DSurface9 = new myIDirect3DSurface9(*ppSurface);
		
		// store our pointer (the fake one) for returning it to the calling progam
		*ppSurface = gl_pmyIDirect3DSurface9;
		return hres;
	}

    return(m_pIDirect3DDevice9->CreateOffscreenPlainSurface(Width,Height,Format,Pool,ppSurface,pSharedHandle));
}

HRESULT myIDirect3DDevice9::SetRenderTarget(DWORD RenderTargetIndex,IDirect3DSurface9* pRenderTarget)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetRenderTarget called!");
#endif

    return(m_pIDirect3DDevice9->SetRenderTarget(RenderTargetIndex,pRenderTarget));
}

HRESULT myIDirect3DDevice9::GetRenderTarget(DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetRenderTarget called!");
#endif

    return(m_pIDirect3DDevice9->GetRenderTarget(RenderTargetIndex,ppRenderTarget));
}

HRESULT myIDirect3DDevice9::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetDepthStencilSurface called!");
#endif

    return(m_pIDirect3DDevice9->SetDepthStencilSurface(pNewZStencil));
}

HRESULT myIDirect3DDevice9::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetDepthStencilSurface called!");
#endif

    return(m_pIDirect3DDevice9->GetDepthStencilSurface(ppZStencilSurface));
}

HRESULT myIDirect3DDevice9::BeginScene(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::BeginScene called!");
#endif

    return(m_pIDirect3DDevice9->BeginScene());
}

HRESULT myIDirect3DDevice9::EndScene(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::EndScene called!");
#endif

    return(m_pIDirect3DDevice9->EndScene());
}

HRESULT myIDirect3DDevice9::Clear(DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::Clear called!");
#endif

    return(m_pIDirect3DDevice9->Clear(Count,pRects,Flags,Color,Z,Stencil));
}

HRESULT myIDirect3DDevice9::SetTransform(D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetTransform called!");
#endif

    return(m_pIDirect3DDevice9->SetTransform(State,pMatrix));
}

HRESULT myIDirect3DDevice9::GetTransform(D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetTransform called!");
#endif

    return(m_pIDirect3DDevice9->GetTransform(State,pMatrix));
}

HRESULT myIDirect3DDevice9::MultiplyTransform(D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::MultiplyTransform called!");
#endif

    return(m_pIDirect3DDevice9->MultiplyTransform(State,pMatrix));
}

HRESULT myIDirect3DDevice9::SetViewport(CONST D3DVIEWPORT9* pViewport)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetViewport called!");
#endif

    return(m_pIDirect3DDevice9->SetViewport(pViewport));
}

HRESULT myIDirect3DDevice9::GetViewport(D3DVIEWPORT9* pViewport)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetViewport called!");
#endif

    return(m_pIDirect3DDevice9->GetViewport(pViewport));
}

HRESULT myIDirect3DDevice9::SetMaterial(CONST D3DMATERIAL9* pMaterial)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetMaterial called!");
#endif

    return(m_pIDirect3DDevice9->SetMaterial(pMaterial));
}

HRESULT myIDirect3DDevice9::GetMaterial(D3DMATERIAL9* pMaterial)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetMaterial called!");
#endif

    return(m_pIDirect3DDevice9->GetMaterial(pMaterial));
}

HRESULT myIDirect3DDevice9::SetLight(DWORD Index,CONST D3DLIGHT9* pLight)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetLight called!");
#endif

    return(m_pIDirect3DDevice9->SetLight(Index,pLight));
}

HRESULT myIDirect3DDevice9::GetLight(DWORD Index,D3DLIGHT9* pLight)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetLight called!");
#endif

    return(m_pIDirect3DDevice9->GetLight(Index,pLight));
}

HRESULT myIDirect3DDevice9::LightEnable(DWORD Index,BOOL Enable)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::LightEnable called!");
#endif

    return(m_pIDirect3DDevice9->LightEnable(Index,Enable));
}

HRESULT myIDirect3DDevice9::GetLightEnable(DWORD Index,BOOL* pEnable)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetLightEnable called!");
#endif

    return(m_pIDirect3DDevice9->GetLightEnable(Index, pEnable));
}

HRESULT myIDirect3DDevice9::SetClipPlane(DWORD Index,CONST float* pPlane)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetClipPlane called!");
#endif

    return(m_pIDirect3DDevice9->SetClipPlane(Index, pPlane));
}

HRESULT myIDirect3DDevice9::GetClipPlane(DWORD Index,float* pPlane)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetClipPlane called!");
#endif

    return(m_pIDirect3DDevice9->GetClipPlane(Index,pPlane));
}

HRESULT myIDirect3DDevice9::SetRenderState(D3DRENDERSTATETYPE State,DWORD Value)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetRenderState called!");
#endif

    return(m_pIDirect3DDevice9->SetRenderState(State, Value));
}

HRESULT myIDirect3DDevice9::GetRenderState(D3DRENDERSTATETYPE State,DWORD* pValue)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetRenderState called!");
#endif

    return(m_pIDirect3DDevice9->GetRenderState(State, pValue));
}

HRESULT myIDirect3DDevice9::CreateStateBlock(D3DSTATEBLOCKTYPE Type,IDirect3DStateBlock9** ppSB)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateStateBlock called!");
#endif

    return(m_pIDirect3DDevice9->CreateStateBlock(Type,ppSB));
}

HRESULT myIDirect3DDevice9::BeginStateBlock(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::BeginStateBlock called!");
#endif

    return(m_pIDirect3DDevice9->BeginStateBlock());
}

HRESULT myIDirect3DDevice9::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::EndStateBlock called!");
#endif

    return(m_pIDirect3DDevice9->EndStateBlock(ppSB));
}

HRESULT myIDirect3DDevice9::SetClipStatus(CONST D3DCLIPSTATUS9* pClipStatus)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetClipStatus called!");
#endif

    return(m_pIDirect3DDevice9->SetClipStatus(pClipStatus));
}

HRESULT myIDirect3DDevice9::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetClipStatus called!");
#endif

    return(m_pIDirect3DDevice9->GetClipStatus( pClipStatus));
}

HRESULT myIDirect3DDevice9::GetTexture(DWORD Stage,IDirect3DBaseTexture9** ppTexture)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetTexture called!");
#endif

    return(m_pIDirect3DDevice9->GetTexture(Stage,ppTexture));
}

HRESULT myIDirect3DDevice9::SetTexture(DWORD Stage,IDirect3DBaseTexture9* pTexture)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetTexture called!");
#endif

    return(m_pIDirect3DDevice9->SetTexture(Stage,pTexture));
}

HRESULT myIDirect3DDevice9::GetTextureStageState(DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetTextureStageState called!");
#endif

    return(m_pIDirect3DDevice9->GetTextureStageState(Stage,Type, pValue));
}

HRESULT myIDirect3DDevice9::SetTextureStageState(DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetTextureStageState called!");
#endif

    return(m_pIDirect3DDevice9->SetTextureStageState(Stage,Type,Value));
}

HRESULT myIDirect3DDevice9::GetSamplerState(DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD* pValue)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetSamplerState called!");
#endif

    return(m_pIDirect3DDevice9->GetSamplerState(Sampler,Type, pValue));
}

HRESULT myIDirect3DDevice9::SetSamplerState(DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD Value)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetSamplerState called!");
#endif

    return(m_pIDirect3DDevice9->SetSamplerState(Sampler,Type,Value));
}

HRESULT myIDirect3DDevice9::ValidateDevice(DWORD* pNumPasses)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::ValidateDevice called!");
#endif

    return(m_pIDirect3DDevice9->ValidateDevice( pNumPasses));
}

HRESULT myIDirect3DDevice9::SetPaletteEntries(UINT PaletteNumber,CONST PALETTEENTRY* pEntries)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetPaletteEntries called!");
#endif

    return(m_pIDirect3DDevice9->SetPaletteEntries(PaletteNumber, pEntries));
}

HRESULT myIDirect3DDevice9::GetPaletteEntries(UINT PaletteNumber,PALETTEENTRY* pEntries)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetPaletteEntries called!");
#endif

    return(m_pIDirect3DDevice9->GetPaletteEntries(PaletteNumber, pEntries));
}

HRESULT myIDirect3DDevice9::SetCurrentTexturePalette(UINT PaletteNumber)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetCurrentTexturePalette called!");
#endif

    return(m_pIDirect3DDevice9->SetCurrentTexturePalette(PaletteNumber));
}

HRESULT myIDirect3DDevice9::GetCurrentTexturePalette(UINT *PaletteNumber)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetCurrentTexturePalette called!");
#endif

    return(m_pIDirect3DDevice9->GetCurrentTexturePalette(PaletteNumber));
}

HRESULT myIDirect3DDevice9::SetScissorRect(CONST RECT* pRect)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetScissorRect called!");
#endif

    return(m_pIDirect3DDevice9->SetScissorRect( pRect));
}

HRESULT myIDirect3DDevice9::GetScissorRect( RECT* pRect)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetScissorRect called!");
#endif

    return(m_pIDirect3DDevice9->GetScissorRect( pRect));
}

HRESULT myIDirect3DDevice9::SetSoftwareVertexProcessing(BOOL bSoftware)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetSoftwareVertexProcessing called!");
#endif

    return(m_pIDirect3DDevice9->SetSoftwareVertexProcessing(bSoftware));
}

BOOL    myIDirect3DDevice9::GetSoftwareVertexProcessing(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetSoftwareVertexProcessing called!");
#endif

    return(m_pIDirect3DDevice9->GetSoftwareVertexProcessing());
}

HRESULT myIDirect3DDevice9::SetNPatchMode(float nSegments)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetNPatchMode called!");
#endif

    return(m_pIDirect3DDevice9->SetNPatchMode(nSegments));
}

float   myIDirect3DDevice9::GetNPatchMode(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetNPatchMode called!");
#endif

    return(m_pIDirect3DDevice9->GetNPatchMode());
}

HRESULT myIDirect3DDevice9::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::DrawPrimitive called!");
#endif

    return(m_pIDirect3DDevice9->DrawPrimitive(PrimitiveType,StartVertex,PrimitiveCount));
}

HRESULT myIDirect3DDevice9::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::DrawIndexedPrimitive called!");
#endif

    return(m_pIDirect3DDevice9->DrawIndexedPrimitive(PrimitiveType,BaseVertexIndex,MinVertexIndex,NumVertices,startIndex,primCount));
}

HRESULT myIDirect3DDevice9::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::DrawPrimitiveUP called!");
#endif

    return(m_pIDirect3DDevice9->DrawPrimitiveUP(PrimitiveType,PrimitiveCount,pVertexStreamZeroData,VertexStreamZeroStride));
}

HRESULT myIDirect3DDevice9::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::DrawIndexedPrimitiveUP called!");
#endif

    return(m_pIDirect3DDevice9->DrawIndexedPrimitiveUP(PrimitiveType,MinVertexIndex,NumVertices,PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData,VertexStreamZeroStride));
}

HRESULT myIDirect3DDevice9::ProcessVertices(UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::ProcessVertices called!");
#endif

    return(m_pIDirect3DDevice9->ProcessVertices( SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags));
}

HRESULT myIDirect3DDevice9::CreateVertexDeclaration(CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateVertexDeclaration called!");
#endif

    return(m_pIDirect3DDevice9->CreateVertexDeclaration( pVertexElements,ppDecl));
}

HRESULT myIDirect3DDevice9::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetVertexDeclaration called!");
#endif

    return(m_pIDirect3DDevice9->SetVertexDeclaration(pDecl));
}

HRESULT myIDirect3DDevice9::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetVertexDeclaration called!");
#endif

    return(m_pIDirect3DDevice9->GetVertexDeclaration(ppDecl));
}

HRESULT myIDirect3DDevice9::SetFVF(DWORD FVF)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetFVF called!");
#endif

    return(m_pIDirect3DDevice9->SetFVF(FVF));
}

HRESULT myIDirect3DDevice9::GetFVF(DWORD* pFVF)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetFVF called!");
#endif

    return(m_pIDirect3DDevice9->GetFVF(pFVF));
}

HRESULT myIDirect3DDevice9::CreateVertexShader(CONST DWORD* pFunction,IDirect3DVertexShader9** ppShader)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateVertexShader called!");
#endif

    return(m_pIDirect3DDevice9->CreateVertexShader(pFunction,ppShader));
}

HRESULT myIDirect3DDevice9::SetVertexShader(IDirect3DVertexShader9* pShader)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetVertexShader called!");
#endif

    return(m_pIDirect3DDevice9->SetVertexShader(pShader));
}

HRESULT myIDirect3DDevice9::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetVertexShader called!");
#endif

    return(m_pIDirect3DDevice9->GetVertexShader(ppShader));
}

HRESULT myIDirect3DDevice9::SetVertexShaderConstantF(UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetVertexShaderConstantF called!");
#endif

    return(m_pIDirect3DDevice9->SetVertexShaderConstantF(StartRegister,pConstantData, Vector4fCount));
}

HRESULT myIDirect3DDevice9::GetVertexShaderConstantF(UINT StartRegister,float* pConstantData,UINT Vector4fCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetVertexShaderConstantF called!");
#endif

    return(m_pIDirect3DDevice9->GetVertexShaderConstantF(StartRegister,pConstantData,Vector4fCount));
}

HRESULT myIDirect3DDevice9::SetVertexShaderConstantI(UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetVertexShaderConstantI called!");
#endif

    return(m_pIDirect3DDevice9->SetVertexShaderConstantI(StartRegister,pConstantData,Vector4iCount));
}

HRESULT myIDirect3DDevice9::GetVertexShaderConstantI(UINT StartRegister,int* pConstantData,UINT Vector4iCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetVertexShaderConstantI called!");
#endif

    return(m_pIDirect3DDevice9->GetVertexShaderConstantI(StartRegister,pConstantData,Vector4iCount));
}

HRESULT myIDirect3DDevice9::SetVertexShaderConstantB(UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetVertexShaderConstantB called!");
#endif

    return(m_pIDirect3DDevice9->SetVertexShaderConstantB(StartRegister,pConstantData,BoolCount));
}

HRESULT myIDirect3DDevice9::GetVertexShaderConstantB(UINT StartRegister,BOOL* pConstantData,UINT BoolCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetVertexShaderConstantB called!");
#endif

    return(m_pIDirect3DDevice9->GetVertexShaderConstantB(StartRegister,pConstantData,BoolCount));
}

HRESULT myIDirect3DDevice9::SetStreamSource(UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetStreamSource called!");
#endif

    return(m_pIDirect3DDevice9->SetStreamSource(StreamNumber,pStreamData,OffsetInBytes,Stride));
}

HRESULT myIDirect3DDevice9::GetStreamSource(UINT StreamNumber,IDirect3DVertexBuffer9** ppStreamData,UINT* OffsetInBytes,UINT* pStride)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetStreamSource called!");
#endif

    return(m_pIDirect3DDevice9->GetStreamSource(StreamNumber,ppStreamData,OffsetInBytes,pStride));
}

HRESULT myIDirect3DDevice9::SetStreamSourceFreq(UINT StreamNumber,UINT Divider)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetStreamSourceFreq called!");
#endif

    return(m_pIDirect3DDevice9->SetStreamSourceFreq(StreamNumber,Divider));
}

HRESULT myIDirect3DDevice9::GetStreamSourceFreq(UINT StreamNumber,UINT* Divider)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetStreamSourceFreq called!");
#endif

    return(m_pIDirect3DDevice9->GetStreamSourceFreq(StreamNumber,Divider));
}

HRESULT myIDirect3DDevice9::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetIndices called!");
#endif

    return(m_pIDirect3DDevice9->SetIndices(pIndexData));
}

HRESULT myIDirect3DDevice9::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetIndices called!");
#endif

    return(m_pIDirect3DDevice9->GetIndices(ppIndexData));
}

HRESULT myIDirect3DDevice9::CreatePixelShader(CONST DWORD* pFunction,IDirect3DPixelShader9** ppShader)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreatePixelShader called!");
#endif

    return(m_pIDirect3DDevice9->CreatePixelShader(pFunction,ppShader));
}

HRESULT myIDirect3DDevice9::SetPixelShader(IDirect3DPixelShader9* pShader)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetPixelShader called!");
#endif

    return(m_pIDirect3DDevice9->SetPixelShader(pShader));
}

HRESULT myIDirect3DDevice9::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetPixelShader called!");
#endif

    return(m_pIDirect3DDevice9->GetPixelShader(ppShader));
}

HRESULT myIDirect3DDevice9::SetPixelShaderConstantF(UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetPixelShaderConstantF called!");
#endif

    return(m_pIDirect3DDevice9->SetPixelShaderConstantF(StartRegister,pConstantData,Vector4fCount));
}

HRESULT myIDirect3DDevice9::GetPixelShaderConstantF(UINT StartRegister,float* pConstantData,UINT Vector4fCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetPixelShaderConstantF called!");
#endif

    return(m_pIDirect3DDevice9->GetPixelShaderConstantF(StartRegister,pConstantData,Vector4fCount));
}

HRESULT myIDirect3DDevice9::SetPixelShaderConstantI(UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetPixelShaderConstantI called!");
#endif

    return(m_pIDirect3DDevice9->SetPixelShaderConstantI(StartRegister,pConstantData,Vector4iCount));
}

HRESULT myIDirect3DDevice9::GetPixelShaderConstantI(UINT StartRegister,int* pConstantData,UINT Vector4iCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetPixelShaderConstantI called!");
#endif

    return(m_pIDirect3DDevice9->GetPixelShaderConstantI(StartRegister,pConstantData,Vector4iCount));
}

HRESULT myIDirect3DDevice9::SetPixelShaderConstantB(UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::SetPixelShaderConstantB called!");
#endif

    return(m_pIDirect3DDevice9->SetPixelShaderConstantB(StartRegister,pConstantData,BoolCount));
}

HRESULT myIDirect3DDevice9::GetPixelShaderConstantB(UINT StartRegister,BOOL* pConstantData,UINT BoolCount)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::GetPixelShaderConstantB called!");
#endif

    return(m_pIDirect3DDevice9->GetPixelShaderConstantB(StartRegister,pConstantData,BoolCount));
}

HRESULT myIDirect3DDevice9::DrawRectPatch(UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::DrawRectPatch called!");
#endif

    return(m_pIDirect3DDevice9->DrawRectPatch(Handle,pNumSegs, pRectPatchInfo));
}

HRESULT myIDirect3DDevice9::DrawTriPatch(UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::DrawTriPatch called!");
#endif

    return(m_pIDirect3DDevice9->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo));
}

HRESULT myIDirect3DDevice9::DeletePatch(UINT Handle)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::DeletePatch called!");
#endif

    return(m_pIDirect3DDevice9->DeletePatch(Handle));
}

HRESULT myIDirect3DDevice9::CreateQuery(D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::CreateQuery called!");
#endif

    return(m_pIDirect3DDevice9->CreateQuery(Type,ppQuery));
}

// This is our test function
void myIDirect3DDevice9::ShowWeAreHere(void)
{
#ifdef MYDIRECT3DDEVICE_DEBUGSTRINGS
	OutputDebugString("myIDirect3DDevice9::ShowWeAreHere called!");
#endif

	extern DWORD gl_LineOffset;

	if(gl_LineOffset > 0){ //only put our marker if actually in HD3D mode and buffer size detected!
		GetViewport(&Viewport);
		D3DVIEWPORT9 old = Viewport;
		D3DRECT recleft = {0,0,MARKER_SIZE,MARKER_SIZE};	
		D3DRECT recright = {0,gl_LineOffset,MARKER_SIZE,gl_LineOffset+MARKER_SIZE};	

		Viewport.X = recleft.x1;
		Viewport.Y = recleft.y1;
		Viewport.Width = recleft.x2-recleft.x1;
		Viewport.Height = recleft.y2-recleft.y1;
		SetViewport((const D3DVIEWPORT9 *) &Viewport);	
		m_pIDirect3DDevice9->Clear(1, &recleft, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255,255,255,255),0 ,0);

		Viewport.X = recright.x1;
		Viewport.Y = recright.y1;
		Viewport.Width = recright.x2-recright.x1;
		Viewport.Height = recright.y2-recright.y1;
		SetViewport((const D3DVIEWPORT9 *) &Viewport);
		m_pIDirect3DDevice9->Clear(1, &recright, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255,0,0,0),0 ,0);

		Viewport = old;
		SetViewport((const D3DVIEWPORT9 *) &Viewport);
	}
}



