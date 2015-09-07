#pragma once

#include <Windows.h>


class Memory {
public:
	DWORD hPID;
	HANDLE hProc;

	bool Process(char* ProcessName);
	DWORD Module(LPSTR ModuleName, DWORD&);

	template <class cData>
	cData Read(DWORD dwAddress)
	{
		cData cRead;
		ReadProcessMemory(hProc, (LPVOID)dwAddress, &cRead, sizeof(cData), NULL);
		return cRead;
	}

	template <class cData>
	void Write(DWORD addr, cData val) {
		WriteProcessMemory(hProc, (LPVOID)addr, &val, sizeof(cData), NULL);
	}
};

extern Memory* gMemory;