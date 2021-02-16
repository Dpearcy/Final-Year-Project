#ifndef DEVICE_H_INCLUDED // Header guard - prevents file being included more than once (would cause errors)
#define DEVICE_H_INCLUDED
#include <Windows.h>
#include <memory>
#include <d3d11.h>
//#include <d3dx11.h>
#include <string>
#include <math.h>
class CDevice
{
private:
	ID3D11DeviceContext* g_pd3dDevice = NULL;
	ID3D11Device* Main_DEvice = NULL;
	ID3D10Device* Swap_Chain = NULL;
	IDXGISwapChain*         SwapChain;
	ID3D11Texture2D*        DepthStencil;
	ID3D11DepthStencilView* DepthStencilView;
	ID3D11RenderTargetView* RenderTargetView;
	int g_ViewportWidth;
	int g_ViewportHeight;
public:

	CDevice();
	bool InitDevice(HWND hWnd);

	~CDevice();
	int Makeg_Viewport(std::string target);
	ID3D11DeviceContext* GetDevice();
	ID3D11DepthStencilView* GetDepthStencilView();
	ID3D11RenderTargetView* GetRenderTargetView();
	HRESULT SendPresent();
};

#endif
