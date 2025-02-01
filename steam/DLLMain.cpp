#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <intrin.h>
#include <wininet.h>
#include <filesystem>
#include <fstream>
#include <array>
#include <map>
#include <unordered_map>
#include <tlhelp32.h>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "Ws2_32.lib")

#include "MinHook.h"
#pragma comment(lib, "libMinHook.x86.lib")

decltype(&CreateProcessW) oCreateProcessW;

BOOL
WINAPI
hooked_CreateProcessW(
	_In_opt_ LPCWSTR lpApplicationName,
	_Inout_opt_ LPWSTR lpCommandLine,
	_In_opt_ LPSECURITY_ATTRIBUTES lpProcessAttributes,
	_In_opt_ LPSECURITY_ATTRIBUTES lpThreadAttributes,
	_In_ BOOL bInheritHandles,
	_In_ DWORD dwCreationFlags,
	_In_opt_ LPVOID lpEnvironment,
	_In_opt_ LPCWSTR lpCurrentDirectory,
	_In_ LPSTARTUPINFOW lpStartupInfo,
	_Out_ LPPROCESS_INFORMATION lpProcessInformation
)
{
	if (!lpApplicationName || !wcsstr(lpApplicationName, L"csgo.exe"))
	{
		return oCreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
	}

	auto original = oCreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
	if (!original)
	{
		return original;
	}

	void* hack_address = VirtualAllocEx(lpProcessInformation->hProcess, reinterpret_cast<void*>(0x30930000), 0x41D000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!hack_address)
	{
		MessageBoxA(0, "Failed to allocate memory.", "ERROR", 0);
		return original;
	}

	void* user_struct = VirtualAllocEx(lpProcessInformation->hProcess, reinterpret_cast<void*>(0x1860000), 0x1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!user_struct)
	{
		MessageBoxA(0, "Failed to allocate memory.", "ERROR ( 2 )", 0);
		return original;
	}

	void* runtime_table = VirtualAllocEx(lpProcessInformation->hProcess, reinterpret_cast<void*>(0x1870000), 0x1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!runtime_table)
	{
		MessageBoxA(0, "Failed to allocate memory.", "ERROR ( 3 )", 0);
		return original;
	}

	void* runtime_table_2 = VirtualAllocEx(lpProcessInformation->hProcess, reinterpret_cast<void*>(0x1880000), 0x1000, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!runtime_table_2)
	{
		MessageBoxA(0, "Failed to allocate memory.", "ERROR ( 4 )", 0);
		return original;
	}

	//printf("[+] allocated memory\n");

	return original;
}

void main()
{
	//printf("[+] creating hooks...\n");
	if (MH_Initialize() != MH_OK)
	{
		MessageBoxA(0, "Failed to initialize minhook", "ERROR", MB_OK | MB_ICONERROR);
		//printf("[-] failed to initialize minhook\n");
		return;
	}

	if (MH_CreateHook(&CreateProcessW, hooked_CreateProcessW, reinterpret_cast<void**>(&oCreateProcessW)) != MH_OK)
	{
		MessageBoxA(0, "Failed to create hook", "ERROR", MB_OK | MB_ICONERROR);
		//printf("[-] failed to create hook at CreateProcessW\n");
		return;
	}

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
	{
		MessageBoxA(0, "Failed to enable hooks", "ERROR", MB_OK | MB_ICONERROR);
		//printf("[-] failed to enable hooks\n");
		return;
	}

	MessageBoxA(0, "Ready", "SUCCESS", MB_OK);

	//printf("[+] created hooks!\n");
}

bool __stdcall DllMain(HANDLE hinstDLL, uint32_t fdwReason, void* lpReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		//AllocConsole();
		SetConsoleTitleA("Alice Cracked this cheat muhuhahahahah");
		//freopen("CONOUT$", "w", stdout);
		CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(main), 0, 0, 0);
	}
	return true;
}