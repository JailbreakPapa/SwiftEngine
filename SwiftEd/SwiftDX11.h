#pragma once
/*Still Deciding if i should use qt or imgui, ill use imgui for now,and learn qt when i have time.*/
#ifndef SWIFT_DX
#define SWIFT_DX
#endif
#include <iostream>
#include <d3d11.h>
#include <imgui-1.86/imgui.h>
#include <imgui-1.86/backends/imgui_impl_dx11.h>
#include <imgui-1.86/backends/imgui_impl_win32.h>
#include <Windows.h>
namespace SwiftRender
{
	class SwiftDX11
	{
		
		bool DX11Init();
		bool Shutdown();
		bool Remove();
		//DX11 Types 
		std::unique_ptr<ID3D11Device> DXDevice;
		std::unique_ptr<IDXGISwapChain> DXSwapChain;
		std::unique_ptr<ID3D11DeviceContext> DXDeviceContext;
		std::unique_ptr<ID3D11RenderTargetView> DXRenderTargetView;
		std::unique_ptr<DXGI_MODE_DESC> BufferDesc;
		bool Detached;
	};
}