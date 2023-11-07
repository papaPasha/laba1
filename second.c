#include <stdio.h>
#include <Windows.h>

int main(int argc, char** argv)
{
	STARTUPINFO startupinfo;
	PROCESS_INFORMATION processinformation;

	ZeroMemory(&startupinfo, sizeof(startupinfo));

	startupinfo.cb = sizeof(startupinfo);

	ZeroMemory(&processinformation, sizeof(processinformation));

	if (argc != 2)
	{
		printf("Usage: %s [cmdline]\n", argv[0]);
		return;
	}

	if (!CreateProcess("C:\\Users\\brobu\\source\\repos\\second.c\\x64\\Debug\\second.c.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startupinfo, &processinformation))
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
	}

	WaitForSingleObject(processinformation.hProcess, INFINITE);

	CloseHandle(processinformation.hProcess);
	CloseHandle(processinformation.hThread);

	return 0;
}
