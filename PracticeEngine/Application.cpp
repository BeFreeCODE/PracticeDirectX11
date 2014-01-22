#include "Application.h"
#include "DirectX11.h"

Application::Application(void)
{
	m_screenWidth = 1024;
	m_screenHeight = 768;
	m_hInst = ::GetModuleHandle(NULL);
	Initialize();
}


Application::~Application(void)
{
}

bool Application::Initialize()
{
	LPWSTR WinClassName = L"WindowClass";
	LPWSTR WindowName = L"DirectX 11 - DX11Triangle";
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof( WNDCLASSEX );				//구조체 크기
	wcex.style = CS_HREDRAW | CS_VREDRAW;			// 윈도우 스타일
	wcex.lpfnWndProc = Application::WndProc;		//메세지 처리 콜백 함수
	wcex.cbClsExtra = 0;							//추가 클래스 지정
	wcex.cbWndExtra = 0;							//추가 윈도우 지정
	wcex.hInstance = m_hInst;						//인스턴스 핸들 지정
	wcex.hIcon = NULL;								// 실행 파일에 쓰일 아이콘 지정
	wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW);	//윈도우에 쓰일 커서 지정
	wcex.hbrBackground = ( HBRUSH )COLOR_WINDOW;	//윈도우 배경화면 지정
	wcex.lpszMenuName = NULL;						//메뉴 지정
	wcex.lpszClassName = L"WindowClass";				//클래스 네임 지정
	wcex.hIconSm = NULL;							// 윈도우 캡션에 쓰일 아이콘 지정

	if( !::RegisterClassEx( &wcex ) )
		return E_FAIL;

	m_hWnd = CreateWindowEx(NULL, 
		L"WindowClass",			// 윈도우 클래스 이름
		L"DirectX 11 - DX11Triangle" ,			// 윈도우 타이틀
		WS_OVERLAPPEDWINDOW ,	// 윈도우 스타일(캡션바와 경계를 갖는 윈도우)
		CW_USEDEFAULT,			// 윈도우가 생성될 위치 (X)
		CW_USEDEFAULT,			// 윈도우가 생성될 위치 (Y)
		m_screenWidth,			// 윈도우 크기 (Width)
		m_screenHeight,			// 윈도우 크기 (Height)
		NULL,					// 부모 윈도우 없음
		NULL,					// 메뉴 없음
		m_hInst,				// 윈도우 핸들
		NULL);					// 추가적인 메세지 없음
	
	MyAssert(m_hWnd != NULL,"윈도우 생성 실패",__LINE__);

	ShowWindow( m_hWnd, SW_SHOW );

	DirectX11::Instance()->Initialize();

	return true;
}

LRESULT CALLBACK Application::WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch(message)
	{
	case WM_QUIT:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd,message, wParam, lParam);
}