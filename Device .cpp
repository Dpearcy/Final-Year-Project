#include "stdafx.h"
#include "Device .h"


CDevice::CDevice()
{
	ID3D11DeviceContext* g_pd3dDevice = NULL;
	ID3D11Device* Main_DEvice = NULL;
	ID3D10Device* Swap_Chain = NULL;
}
CDevice::~CDevice()
{
	if (g_pd3dDevice)     g_pd3dDevice->Release();
	if (DepthStencilView) DepthStencilView->Release();
	if (RenderTargetView) RenderTargetView->Release();
	if (DepthStencil)     DepthStencil->Release();
	if (SwapChain)        SwapChain->Release();
}
bool CDevice::InitDevice(HWND hWnd)
{
	// Many DirectX functions return a "HRESULT" variable to indicate success or failure. Microsoft code often uses
	// the FAILED macro to test this variable, you'll see it throughout the code - it's fairly self explanatory.
	HRESULT hr = S_OK;
	//D3D_FEATURE_LEVEL levelt = Main_DEvice->GetFeatureLevel();
	////////////////////////////////
	// Initialise Direct3D

	// Calculate the visible area the window we are using - the "client rectangle" refered to in the first function is the 
	// size of the interior of the window, i.e. excluding the frame and title
	RECT rc;
	GetClientRect(hWnd, &rc);
	g_ViewportWidth = 400; // rc.right - rc.left;
	g_ViewportHeight = 400; //rc.bottom - rc.top;


							// Create a Direct3D device (i.e. initialise D3D), and create a swap-chain (create a back buffer to render to)
	DXGI_SWAP_CHAIN_DESC sd;         // Structure to contain all the information needed
	ZeroMemory(&sd, sizeof(sd)); // Clear the structure to 0 - common Microsoft practice, not really good style
	sd.BufferCount = 1;
	sd.BufferDesc.Width = g_ViewportWidth;             // Target window size
	sd.BufferDesc.Height = g_ViewportHeight;           // --"--
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // Pixel format of target window
	sd.BufferDesc.RefreshRate.Numerator = 60;          // Refresh rate of monitor
	sd.BufferDesc.RefreshRate.Denominator = 1;         // --"--
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.OutputWindow = hWnd;                            // Target window
	sd.Windowed = TRUE; // Whether to render in a window (TRUE) or go fullscreen (FALSE)
	//D3D10CreateDeviceAndSwapChain(NULL,D3D10_DRIVER_TYPE_HARDWARE,NU)
	//hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_REFERENCE, NULL, 0,0, 0, 0, &sd,&SwapChain, &Main_DEvice, &levelt, &g_pd3dDevice);
	if (FAILED(hr)) return false;


	// Specify the render target as the back-buffer - this is an advanced topic. This code almost always occurs in the standard D3D setup
	ID3D11Texture2D* pBackBuffer;
	//hr = SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	if (FAILED(hr)) return false;
	//hr = Main_DEvice->CreateRenderTargetView(pBackBuffer, NULL, &RenderTargetView);
	//pBackBuffer->Release();
	if (FAILED(hr)) return false;

	// Select the back buffer and depth buffer to use for rendering now
	//g_pd3dDevice->OMSetRenderTargets(1, &RenderTargetView, DepthStencilView);


	// Setup the viewport - defines which part of the window we will render to, almost always the whole window
	D3D11_VIEWPORT vp;
	vp.Width = g_ViewportWidth;
	vp.Height = g_ViewportHeight;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	g_pd3dDevice->RSSetViewports(1, &vp);

	return true;
}