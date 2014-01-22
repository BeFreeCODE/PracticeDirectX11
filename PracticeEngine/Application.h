#pragma once
#include "StdAfx.h"

class Application
{
public:
	Application(void);
	~Application(void);

	bool Initialize();
	static LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );	
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;
	
	int m_screenWidth;
	int m_screenHeight;
};

