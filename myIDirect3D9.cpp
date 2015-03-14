// myIDirect3D9.cpp

#include "StdAfx.h"

myIDirect3D9::myIDirect3D9(IDirect3D9 *pOriginal)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::myIDirect3D9 called!");
#endif
    m_pIDirect3D9 = pOriginal;
}

myIDirect3D9::~myIDirect3D9(void)
{
}

HRESULT  __stdcall myIDirect3D9::QueryInterface(REFIID riid, void** ppvObj)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::QueryInterface called!");
#endif
    *ppvObj = NULL;

	// call this to increase AddRef at original object
	// and to check if such an interface is there

	HRESULT hRes = m_pIDirect3D9->QueryInterface(riid, ppvObj); 

	if (hRes == NOERROR) // if OK, send our "fake" address
	{
		*ppvObj = this;
	}
	
	return hRes;
}

ULONG    __stdcall myIDirect3D9::AddRef(void)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::AddRef called!");
#endif
    return(m_pIDirect3D9->AddRef());
}

ULONG    __stdcall myIDirect3D9::Release(void)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::Release called!");
#endif
    extern myIDirect3D9* gl_pmyIDirect3D9;

	// call original routine
	ULONG count = m_pIDirect3D9->Release();
	
    // in case no further Ref is there, the Original Object has deleted itself
	// so do we here
	if (count == 0) 
	{
		gl_pmyIDirect3D9 = NULL;
  	    delete(this); 
	}

	return(count);
}

HRESULT __stdcall myIDirect3D9::RegisterSoftwareDevice(void* pInitializeFunction)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::RegisterSoftwareDevice called!");
#endif
    return(m_pIDirect3D9->RegisterSoftwareDevice(pInitializeFunction));
}

UINT __stdcall myIDirect3D9::GetAdapterCount(void)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::GetAdapterCount called!");
#endif
    return(m_pIDirect3D9->GetAdapterCount());
}

HRESULT __stdcall myIDirect3D9::GetAdapterIdentifier(UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER9* pIdentifier)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::GetAdapterIdentifier called!");
#endif
    return(m_pIDirect3D9->GetAdapterIdentifier(Adapter,Flags,pIdentifier));
}

UINT __stdcall myIDirect3D9::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::GetAdapterModeCount called!");
#endif
    return(m_pIDirect3D9->GetAdapterModeCount(Adapter, Format));
}

HRESULT __stdcall myIDirect3D9::EnumAdapterModes(UINT Adapter,D3DFORMAT Format,UINT Mode,D3DDISPLAYMODE* pMode)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::EnumAdapterModes called!");
#endif
    return(m_pIDirect3D9->EnumAdapterModes(Adapter,Format,Mode,pMode));
}

HRESULT __stdcall myIDirect3D9::GetAdapterDisplayMode( UINT Adapter,D3DDISPLAYMODE* pMode)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::GetAdapterDisplayMode called!");
#endif
    return(m_pIDirect3D9->GetAdapterDisplayMode(Adapter,pMode));
}

HRESULT __stdcall myIDirect3D9::CheckDeviceType(UINT iAdapter,D3DDEVTYPE DevType,D3DFORMAT DisplayFormat,D3DFORMAT BackBufferFormat,BOOL bWindowed)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::CheckDeviceType called!");
#endif
    return(m_pIDirect3D9->CheckDeviceType(iAdapter,DevType,DisplayFormat,BackBufferFormat,bWindowed));
}

HRESULT __stdcall myIDirect3D9::CheckDeviceFormat(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::CheckDeviceFormat called!");
#endif
    return(m_pIDirect3D9->CheckDeviceFormat(Adapter,DeviceType,AdapterFormat,Usage,RType,CheckFormat));
}

HRESULT __stdcall myIDirect3D9::CheckDeviceMultiSampleType(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType,DWORD* pQualityLevels)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::CheckDeviceMultiSampleType called!");
#endif
    return(m_pIDirect3D9->CheckDeviceMultiSampleType(Adapter,DeviceType,SurfaceFormat,Windowed,MultiSampleType,pQualityLevels));
}

HRESULT __stdcall myIDirect3D9::CheckDepthStencilMatch(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::CheckDepthStencilMatch called!");
#endif
    return(m_pIDirect3D9->CheckDepthStencilMatch(Adapter,DeviceType,AdapterFormat,RenderTargetFormat,DepthStencilFormat));
}

HRESULT __stdcall myIDirect3D9::CheckDeviceFormatConversion(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SourceFormat,D3DFORMAT TargetFormat)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::CheckDeviceFormatConversion called!");
#endif
    return(m_pIDirect3D9->CheckDeviceFormatConversion(Adapter,DeviceType,SourceFormat,TargetFormat));
}

HRESULT __stdcall myIDirect3D9::GetDeviceCaps(UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::GetDeviceCaps called!");
#endif
    return(m_pIDirect3D9->GetDeviceCaps(Adapter,DeviceType,pCaps));
}

HMONITOR __stdcall myIDirect3D9::GetAdapterMonitor(UINT Adapter)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::GetAdapterMonitor called!");
#endif

    return(m_pIDirect3D9->GetAdapterMonitor(Adapter));
}

HRESULT __stdcall myIDirect3D9::CreateDevice(UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface)
{
#ifdef MYDIRECT3D9_DEBUGSTRINGS
	OutputDebugString("myIDirect3D9::CreateDevice called!");
#endif

#ifdef MYDIRECT3D_PASSTHROUGH
	return(m_pIDirect3D9->CreateDevice(Adapter,DeviceType,hFocusWindow,BehaviorFlags,pPresentationParameters,ppReturnedDeviceInterface));
#else
#ifdef MYDIRECT3D9_ORIG
	extern IDirect3DDevice9*   gl_pIDirect3DDevice9;
	HRESULT hres = m_pIDirect3D9->CreateDevice( Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, &gl_pIDirect3DDevice9);
	*ppReturnedDeviceInterface = gl_pIDirect3DDevice9;

	//HRESULT (__stdcall IDirect3DDevice9::*fptr) (CONST RECT*,CONST RECT*,HWND,CONST RGNDATA*) = &IDirect3DDevice9::Present;
	// tricky cast
	//void* pPtr = (void*&) fptr; // this works

	//Steal some bytes and show them!
	//StealBytes((void*)&(gl_pIDirect3DDevice9->Present)

	return(hres);
#else
    // global var
	extern myIDirect3DDevice9* gl_pmyIDirect3DDevice9;

	// we intercept this call and provide our own "fake" Device Object
	HRESULT hres = m_pIDirect3D9->CreateDevice( Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
    
	// Create our own Device object and store it in global pointer
	// note: the object will delete itself once Ref count is zero (similar to COM objects)
	gl_pmyIDirect3DDevice9 = new myIDirect3DDevice9(*ppReturnedDeviceInterface);
	
	// store our pointer (the fake one) for returning it to the calling progam
	*ppReturnedDeviceInterface = gl_pmyIDirect3DDevice9;

	return(hres); 
#endif
#endif
}
