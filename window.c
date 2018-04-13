#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//�V���{����`
#define WINDOW_WIDTH     800
#define WINDOW_HEIGHT    800

//�C���X�^���X
HINSTANCE hInst;

//�E�B���h�E�v���[�W���[�̃R�[���o�b�N�֐�
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
   static char szWindowClass[] = "window";
   static char szTitle[] = "window app";

   WNDCLASSEX wcex;

   wcex.cbSize = sizeof(WNDCLASSEX);
   wcex.style = CS_HREDRAW | CS_VREDRAW;
   wcex.lpfnWndProc = WndProc;
   wcex.cbClsExtra = 0;
   wcex.cbWndExtra = 0;
   wcex.hInstance = hInstance;
   wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
   wcex.hCursor = LoadCursor(NULL,IDC_ARROW);
   wcex.hbrBackground =(HBRUSH)(COLOR_WINDOW + 1);
   wcex.lpszMenuName = NULL;
   wcex.lpszClassName = szWindowClass;
   wcex.hIconSm = LoadIcon(wcex.hInstance,MAKEINTRESOURCE(IDI_APPLICATION));

   if(!RegisterClassEx(&wcex))
   {
      MessageBox(NULL,"failed to create window","window02",MB_ICONEXCLAMATION);

      exit(1);
   }

   hInst = hInstance; 

   HWND hWnd = CreateWindow(
      szWindowClass,
      szTitle,
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT,CW_USEDEFAULT,
      WINDOW_WIDTH,WINDOW_HEIGHT,
      NULL,
      NULL,
      hInstance,
      NULL
   );

   if(!hWnd){
       MessageBox(NULL,"failed to create window","window02",MB_ICONEXCLAMATION);

      exit(2);
   }

   ShowWindow(hWnd,nCmdShow);
   UpdateWindow(hWnd);

   //���C���̃��[�v
   MSG msg;
   while(GetMessage(&msg,NULL,0,0)){
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }

   return (int)msg.wParam;
}

//�E�B���h�E�v���[�W���[
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   switch (message)
   {
      case WM_DESTROY:
         PostQuitMessage(0);
         break;
      default:
         return DefWindowProc(hWnd,message,wParam,lParam);
         break;
   }

   return 0;
}