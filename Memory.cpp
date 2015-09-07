#include "Memory.h"
#include <TlHelp32.h> 

Memory* gMemory = new Memory();

bool Memory::Process(char * ProcessName)
{
	HANDLE hhPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 ProcEntry;
	ProcEntry.dwSize = sizeof(ProcEntry);


	do
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{

			Memory::hPID = ProcEntry.th32ProcessID;
			CloseHandle(hhPID);

			Memory::hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Memory::hPID);
			return true;
		}
	while (Process32Next(hhPID, &ProcEntry));
	return false;
}

DWORD Memory::Module(LPSTR ModuleName, DWORD& modSizeTo)
{
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, Memory::hPID);
	MODULEENTRY32 mEntry;
	mEntry.dwSize = sizeof(mEntry);

	do
		if (!strcmp(mEntry.szModule, ModuleName))
		{
			CloseHandle(hModule);
			modSizeTo = mEntry.modBaseSize;
			return (DWORD)mEntry.modBaseAddr;
		}
	while (Module32Next(hModule, &mEntry));
	return 0;
}