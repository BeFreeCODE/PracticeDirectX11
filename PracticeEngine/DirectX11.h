#pragma once
#include "StdAfx.h"

class DirectX11
{
public:
	~DirectX11(void);
	
	static DirectX11* Instance()
	{
		if(m_Instance == nullptr)
		{
			m_Instance = new DirectX11;
		}

		return m_Instance;
	}

	void Initialize();

	void InitGraphics();
	void InitPipeline();
private:
	DirectX11();
	static DirectX11* m_Instance;
	ID3D11Device* m_pD3DDevice;
	ID3D11DeviceContext* m_pD3DDeviceContext;
	IDXGISwapChain* m_pSwapChain;
	ID3D11RenderTargetView* m_pRenderTargetView;

	ID3D11DepthStencilView* m_pZbuffer;

	ID3D11VertexShader* m_pVS;
	ID3D11PixelShader* m_pPS;
	ID3D11InputLayout* m_pLayout;
	ID3D11Buffer* m_pVBuffer;
	ID3D11Buffer* m_pIBuffer;
	ID3D11Buffer* m_pCBuffer;
};

