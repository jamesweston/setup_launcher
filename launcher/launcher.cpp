// launcher.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ShellAPI.h"
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	DWORD dwVersion = 0; 
	DWORD dwMajorVersion = 0;
    dwVersion = GetVersion();
	dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));

	// ShellExecutInfo
	SHELLEXECUTEINFO ShRunUpdate = {0};
	ShRunUpdate.cbSize = sizeof(SHELLEXECUTEINFO);
	ShRunUpdate.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShRunUpdate.hwnd = NULL;
	ShRunUpdate.lpVerb = NULL;	
	ShRunUpdate.lpParameters = NULL;	
	ShRunUpdate.lpDirectory = NULL;
	ShRunUpdate.nShow = SW_SHOW;
	ShRunUpdate.hInstApp = NULL;	
	ShRunUpdate.lpFile = L"meamodsetup.exe";

	if ( dwMajorVersion >= 6 )
	{
		ShRunUpdate.lpVerb = L"runas";
		// Execute the file with the parameters
		ShellExecuteEx(&ShRunUpdate);
	}	
	else if (dwMajorVersion >= 5)
	{
		ShRunUpdate.lpVerb = NULL;
		// Execute the file with the parameters
		ShellExecuteEx(&ShRunUpdate);
	}
	else
		MessageBox(NULL, L"This application requires Windows 2000 or above", L"MeaMod Installer", MB_OK | MB_ICONEXCLAMATION);

	// Wait until it's ready
	WaitForSingleObject(ShRunUpdate.hProcess, INFINITE);
}

