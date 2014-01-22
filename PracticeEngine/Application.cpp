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
	wcex.cbSize = sizeof( WNDCLASSEX );				//����ü ũ��
	wcex.style = CS_HREDRAW | CS_VREDRAW;			// ������ ��Ÿ��
	wcex.lpfnWndProc = Application::WndProc;		//�޼��� ó�� �ݹ� �Լ�
	wcex.cbClsExtra = 0;							//�߰� Ŭ���� ����
	wcex.cbWndExtra = 0;							//�߰� ������ ����
	wcex.hInstance = m_hInst;						//�ν��Ͻ� �ڵ� ����
	wcex.hIcon = NULL;								// ���� ���Ͽ� ���� ������ ����
	wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW);	//�����쿡 ���� Ŀ�� ����
	wcex.hbrBackground = ( HBRUSH )COLOR_WINDOW;	//������ ���ȭ�� ����
	wcex.lpszMenuName = NULL;						//�޴� ����
	wcex.lpszClassName = L"WindowClass";				//Ŭ���� ���� ����
	wcex.hIconSm = NULL;							// ������ ĸ�ǿ� ���� ������ ����

	if( !::RegisterClassEx( &wcex ) )
		return E_FAIL;

	m_hWnd = CreateWindowEx(NULL, 
		L"WindowClass",			// ������ Ŭ���� �̸�
		L"DirectX 11 - DX11Triangle" ,			// ������ Ÿ��Ʋ
		WS_OVERLAPPEDWINDOW ,	// ������ ��Ÿ��(ĸ�ǹٿ� ��踦 ���� ������)
		CW_USEDEFAULT,			// �����찡 ������ ��ġ (X)
		CW_USEDEFAULT,			// �����찡 ������ ��ġ (Y)
		m_screenWidth,			// ������ ũ�� (Width)
		m_screenHeight,			// ������ ũ�� (Height)
		NULL,					// �θ� ������ ����
		NULL,					// �޴� ����
		m_hInst,				// ������ �ڵ�
		NULL);					// �߰����� �޼��� ����
	
	MyAssert(m_hWnd != NULL,"������ ���� ����",__LINE__);

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