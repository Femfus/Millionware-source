#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <intrin.h>
#include <wininet.h>
#include <filesystem>
#include <fstream>
#include <format>
#include <map>
#include <array>
#include <unordered_map>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "Ws2_32.lib")

#include "bins.hpp"


void fix_imports()
{
	*reinterpret_cast<FARPROC*>(0x30BAB000) = GetProcAddress(LoadLibraryA("advapi32.dll"), "RegCreateKeyExW");
	*reinterpret_cast<FARPROC*>(0x30BAB004) = GetProcAddress(LoadLibraryA("advapi32.dll"), "RegEnumValueA");
	*reinterpret_cast<FARPROC*>(0x30BAB008) = GetProcAddress(LoadLibraryA("advapi32.dll"), "RegOpenKeyExA");
	*reinterpret_cast<FARPROC*>(0x30BAB00C) = GetProcAddress(LoadLibraryA("advapi32.dll"), "RegCloseKey");
	*reinterpret_cast<FARPROC*>(0x30BAB010) = GetProcAddress(LoadLibraryA("advapi32.dll"), "RegGetValueA");
	*reinterpret_cast<FARPROC*>(0x30BAB014) = GetProcAddress(LoadLibraryA("advapi32.dll"), "RegSetValueExW");
	*reinterpret_cast<FARPROC*>(0x30BAB018) = GetProcAddress(LoadLibraryA("advapi32.dll"), "RegQueryValueExW");
	*reinterpret_cast<FARPROC*>(0x30BAB01C) = GetProcAddress(LoadLibraryA("advapi32.dll"), "RegOpenKeyExW");
	*reinterpret_cast<FARPROC*>(0x30BAB024) = GetProcAddress(LoadLibraryA("imm32.dll"), "ImmReleaseContext");
	*reinterpret_cast<FARPROC*>(0x30BAB028) = GetProcAddress(LoadLibraryA("imm32.dll"), "ImmGetContext");
	*reinterpret_cast<FARPROC*>(0x30BAB02C) = GetProcAddress(LoadLibraryA("imm32.dll"), "ImmSetCompositionWindow");
	*reinterpret_cast<FARPROC*>(0x30BAB030) = GetProcAddress(LoadLibraryA("imm32.dll"), "ImmSetCandidateWindow");
	*reinterpret_cast<FARPROC*>(0x30BAB038) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetCurrentProcess");
	*reinterpret_cast<FARPROC*>(0x30BAB03C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetConsoleScreenBufferInfo");
	*reinterpret_cast<FARPROC*>(0x30BAB040) = GetProcAddress(LoadLibraryA("kernel32.dll"), "SetConsoleTextAttribute");
	*reinterpret_cast<FARPROC*>(0x30BAB044) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetStdHandle");
	*reinterpret_cast<FARPROC*>(0x30BAB048) = GetProcAddress(LoadLibraryA("kernel32.dll"), "WriteConsoleA");
	*reinterpret_cast<FARPROC*>(0x30BAB04C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "WriteFile");
	*reinterpret_cast<FARPROC*>(0x30BAB050) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetDynamicTimeZoneInformation");
	*reinterpret_cast<FARPROC*>(0x30BAB054) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetConsoleMode");
	*reinterpret_cast<FARPROC*>(0x30BAB058) = GetProcAddress(LoadLibraryA("kernel32.dll"), "HeapCreate");
	*reinterpret_cast<FARPROC*>(0x30BAB05C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "HeapFree");
	*reinterpret_cast<FARPROC*>(0x30BAB060) = GetProcAddress(LoadLibraryA("kernel32.dll"), "Thread32Next");
	*reinterpret_cast<FARPROC*>(0x30BAB064) = GetProcAddress(LoadLibraryA("kernel32.dll"), "Thread32First");
	*reinterpret_cast<FARPROC*>(0x30BAB068) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetCurrentThreadId");
	*reinterpret_cast<FARPROC*>(0x30BAB06C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "SuspendThread");
	*reinterpret_cast<FARPROC*>(0x30BAB070) = GetProcAddress(LoadLibraryA("kernel32.dll"), "ResumeThread");
	*reinterpret_cast<FARPROC*>(0x30BAB074) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CreateToolhelp32Snapshot");
	*reinterpret_cast<FARPROC*>(0x30BAB078) = GetProcAddress(LoadLibraryA("kernel32.dll"), "Sleep");
	*reinterpret_cast<FARPROC*>(0x30BAB07C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "HeapReAlloc");
	*reinterpret_cast<FARPROC*>(0x30BAB080) = GetProcAddress(LoadLibraryA("kernel32.dll"), "HeapAlloc");
	*reinterpret_cast<FARPROC*>(0x30BAB084) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetThreadContext");
	*reinterpret_cast<FARPROC*>(0x30BAB088) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetProcAddress");
	*reinterpret_cast<FARPROC*>(0x30BAB08C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetModuleHandleW");
	*reinterpret_cast<FARPROC*>(0x30BAB090) = GetProcAddress(LoadLibraryA("kernel32.dll"), "FlushInstructionCache");
	*reinterpret_cast<FARPROC*>(0x30BAB094) = GetProcAddress(LoadLibraryA("kernel32.dll"), "SetThreadContext");
	*reinterpret_cast<FARPROC*>(0x30BAB098) = GetProcAddress(LoadLibraryA("kernel32.dll"), "OpenThread");
	*reinterpret_cast<FARPROC*>(0x30BAB09C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GlobalFree");
	*reinterpret_cast<FARPROC*>(0x30BAB0A0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetTickCount64");
	*reinterpret_cast<FARPROC*>(0x30BAB0A4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "FormatMessageA");
	*reinterpret_cast<FARPROC*>(0x30BAB0A8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "LocalFree");
	*reinterpret_cast<FARPROC*>(0x30BAB0AC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "LoadLibraryA");
	*reinterpret_cast<FARPROC*>(0x30BAB0B0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "FreeLibrary");
	*reinterpret_cast<FARPROC*>(0x30BAB0B4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "QueryPerformanceFrequency");
	*reinterpret_cast<FARPROC*>(0x30BAB0B8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "QueryPerformanceCounter");
	*reinterpret_cast<FARPROC*>(0x30BAB0BC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "WaitNamedPipeW");
	*reinterpret_cast<FARPROC*>(0x30BAB0C0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "PeekNamedPipe");
	*reinterpret_cast<FARPROC*>(0x30BAB0C4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetLastError");
	*reinterpret_cast<FARPROC*>(0x30BAB0C8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "WideCharToMultiByte");
	*reinterpret_cast<FARPROC*>(0x30BAB0CC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CreateFileW");
	*reinterpret_cast<FARPROC*>(0x30BAB0D0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "MultiByteToWideChar");
	*reinterpret_cast<FARPROC*>(0x30BAB0D4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "lstrlenW");
	*reinterpret_cast<FARPROC*>(0x30BAB0D8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetModuleFileNameW");
	*reinterpret_cast<FARPROC*>(0x30BAB0DC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "FindFirstFileExW");
	*reinterpret_cast<FARPROC*>(0x30BAB0E0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "FindNextFileW");
	*reinterpret_cast<FARPROC*>(0x30BAB0E4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "K32GetModuleFileNameExW");
	*reinterpret_cast<FARPROC*>(0x30BAB0E8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GlobalUnlock");
	*reinterpret_cast<FARPROC*>(0x30BAB0EC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetCurrentProcessId");
	*reinterpret_cast<FARPROC*>(0x30BAB0F0) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GlobalLock");
	*reinterpret_cast<FARPROC*>(0x30BAB0F4) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CloseHandle");
	*reinterpret_cast<FARPROC*>(0x30BAB0F8) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetFileAttributesExW");
	*reinterpret_cast<FARPROC*>(0x30BAB0FC) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GlobalAlloc");
	*reinterpret_cast<FARPROC*>(0x30BAB100) = GetProcAddress(LoadLibraryA("kernel32.dll"), "OpenProcess");
	*reinterpret_cast<FARPROC*>(0x30BAB104) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetProcessDEPPolicy");
	*reinterpret_cast<FARPROC*>(0x30BAB108) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetWindowsDirectoryA");
	*reinterpret_cast<FARPROC*>(0x30BAB10C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetLocaleInfoEx");
	*reinterpret_cast<FARPROC*>(0x30BAB110) = GetProcAddress(LoadLibraryA("kernel32.dll"), "InitializeSListHead");
	*reinterpret_cast<FARPROC*>(0x30BAB114) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetSystemTimeAsFileTime");
	*reinterpret_cast<FARPROC*>(0x30BAB118) = GetProcAddress(LoadLibraryA("kernel32.dll"), "IsDebuggerPresent");
	*reinterpret_cast<FARPROC*>(0x30BAB11C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "TerminateProcess");
	*reinterpret_cast<FARPROC*>(0x30BAB120) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CreateFileA");
	*reinterpret_cast<FARPROC*>(0x30BAB124) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetFileSizeEx");
	*reinterpret_cast<FARPROC*>(0x30BAB128) = GetProcAddress(LoadLibraryA("kernel32.dll"), "MapViewOfFile");
	*reinterpret_cast<FARPROC*>(0x30BAB12C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "SetUnhandledExceptionFilter");
	*reinterpret_cast<FARPROC*>(0x30BAB130) = GetProcAddress(LoadLibraryA("kernel32.dll"), "UnmapViewOfFile");
	*reinterpret_cast<FARPROC*>(0x30BAB134) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CreateFileMappingA");
	*reinterpret_cast<FARPROC*>(0x30BAB138) = GetProcAddress(LoadLibraryA("kernel32.dll"), "UnhandledExceptionFilter");
	*reinterpret_cast<FARPROC*>(0x30BAB13C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "IsProcessorFeaturePresent");
	*reinterpret_cast<FARPROC*>(0x30BAB140) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CreateEventW");
	*reinterpret_cast<FARPROC*>(0x30BAB144) = GetProcAddress(LoadLibraryA("kernel32.dll"), "WaitForSingleObjectEx");
	*reinterpret_cast<FARPROC*>(0x30BAB148) = GetProcAddress(LoadLibraryA("kernel32.dll"), "ResetEvent");
	*reinterpret_cast<FARPROC*>(0x30BAB14C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "SetEvent");
	*reinterpret_cast<FARPROC*>(0x30BAB150) = GetProcAddress(LoadLibraryA("kernel32.dll"), "DeleteCriticalSection");
	*reinterpret_cast<FARPROC*>(0x30BAB154) = GetProcAddress(LoadLibraryA("kernel32.dll"), "InitializeCriticalSectionAndSpinCount");
	*reinterpret_cast<FARPROC*>(0x30BAB158) = GetProcAddress(LoadLibraryA("kernel32.dll"), "LeaveCriticalSection");
	*reinterpret_cast<FARPROC*>(0x30BAB15C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "EnterCriticalSection");
	*reinterpret_cast<FARPROC*>(0x30BAB160) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetFileInformationByHandleEx");
	*reinterpret_cast<FARPROC*>(0x30BAB164) = GetProcAddress(LoadLibraryA("kernel32.dll"), "MoveFileExW");
	*reinterpret_cast<FARPROC*>(0x30BAB168) = GetProcAddress(LoadLibraryA("kernel32.dll"), "AreFileApisANSI");
	*reinterpret_cast<FARPROC*>(0x30BAB16C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "GetModuleFileNameA");
	*reinterpret_cast<FARPROC*>(0x30BAB170) = GetProcAddress(LoadLibraryA("kernel32.dll"), "CreateDirectoryW");
	*reinterpret_cast<FARPROC*>(0x30BAB174) = GetProcAddress(LoadLibraryA("kernel32.dll"), "FindClose");
	*reinterpret_cast<FARPROC*>(0x30BAB178) = GetProcAddress(LoadLibraryA("kernel32.dll"), "ReadFile");
	*reinterpret_cast<FARPROC*>(0x30BAB17C) = GetProcAddress(LoadLibraryA("kernel32.dll"), "FindFirstFileW");
	*reinterpret_cast<FARPROC*>(0x30BAB180) = GetProcAddress(LoadLibraryA("kernel32.dll"), "SetFileInformationByHandle");
	*reinterpret_cast<FARPROC*>(0x30BAB188) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Xbad_function_call@std@@YAXXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB18C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?id@?$numpunct@D@std@@2V0locale@2@A");
	*reinterpret_cast<FARPROC*>(0x30BAB190) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Fiopen@std@@YAPAU_iobuf@@PBDHH@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB194) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Syserror_map@std@@YAPBDH@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB198) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?getloc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QBE?AVlocale@2@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB19C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?sputc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QAEHD@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1A0) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Osfx@?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEXXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1A4) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?flush@?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV12@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1A8) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??0?$basic_istream@DU?$char_traits@D@std@@@std@@QAE@PAV?$basic_streambuf@DU?$char_traits@D@std@@@1@_N@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1AC) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?sputn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QAE_JPBD_J@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1B0) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?setstate@?$basic_ios@DU?$char_traits@D@std@@@std@@QAEXH_N@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1B4) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?write@?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV12@PBD_J@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1B8) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??1?$basic_istream@DU?$char_traits@D@std@@@std@@UAE@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1BC) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?read@?$basic_istream@DU?$char_traits@D@std@@@std@@QAEAAV12@PAD_J@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1C0) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?peek@?$basic_istream@DU?$char_traits@D@std@@@std@@QAEHXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1C4) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?seekg@?$basic_istream@DU?$char_traits@D@std@@@std@@QAEAAV12@_JH@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1C8) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?tellg@?$basic_istream@DU?$char_traits@D@std@@@std@@QAE?AV?$fpos@U_Mbstatet@@@2@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1CC) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?unsetf@ios_base@std@@QAEXH@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1D0) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?good@ios_base@std@@QBE_NXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1D4) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??1?$codecvt@DDU_Mbstatet@@@std@@MAE@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1D8) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??0facet@locale@std@@IAE@I@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1DC) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Decref@facet@locale@std@@UAEPAV_Facet_base@3@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1E0) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Incref@facet@locale@std@@UAEXXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1E4) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Gettrue@_Locinfo@std@@QBEPBDXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1E8) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Getfalse@_Locinfo@std@@QBEPBDXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1EC) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??1_Locinfo@std@@QAE@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB1F0) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??0_Locinfo@std@@QAE@PBD@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1F4) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Query_perf_frequency");
	*reinterpret_cast<FARPROC*>(0x30BAB1F8) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Throw_C_error@std@@YAXH@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB1FC) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Mtx_destroy_in_situ");
	*reinterpret_cast<FARPROC*>(0x30BAB200) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Mtx_lock");
	*reinterpret_cast<FARPROC*>(0x30BAB204) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Mtx_init_in_situ");
	*reinterpret_cast<FARPROC*>(0x30BAB208) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Query_perf_counter");
	*reinterpret_cast<FARPROC*>(0x30BAB20C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Mtx_unlock");
	*reinterpret_cast<FARPROC*>(0x30BAB210) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Xtime_get_ticks");
	*reinterpret_cast<FARPROC*>(0x30BAB214) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?setw@std@@YA?AU?$_Smanip@_J@1@_J@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB218) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?put@?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV12@D@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB21C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?sbumpc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QAEHXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB220) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?clear@?$basic_ios@DU?$char_traits@D@std@@@std@@QAEXH_N@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB224) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Cnd_signal");
	*reinterpret_cast<FARPROC*>(0x30BAB228) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Throw_Cpp_error@std@@YAXH@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB22C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Thrd_sleep");
	*reinterpret_cast<FARPROC*>(0x30BAB230) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?GetCurrentThreadId@platform@details@Concurrency@@YAJXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB234) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Thrd_join");
	*reinterpret_cast<FARPROC*>(0x30BAB238) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Cnd_destroy_in_situ");
	*reinterpret_cast<FARPROC*>(0x30BAB23C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Mtx_current_owns");
	*reinterpret_cast<FARPROC*>(0x30BAB240) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Cnd_init_in_situ");
	*reinterpret_cast<FARPROC*>(0x30BAB244) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Cnd_timedwait");
	*reinterpret_cast<FARPROC*>(0x30BAB248) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Cnd_broadcast");
	*reinterpret_cast<FARPROC*>(0x30BAB24C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "_Cnd_do_broadcast_at_thread_exit");
	*reinterpret_cast<FARPROC*>(0x30BAB250) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Xinvalid_argument@std@@YAXPBD@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB254) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Init@locale@std@@CAPAV_Locimp@12@_N@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB258) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?uncaught_exceptions@std@@YAHXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB25C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??Bid@locale@std@@QAEIXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB260) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?always_noconv@codecvt_base@std@@QBE_NXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB264) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??1?$basic_ios@DU?$char_traits@D@std@@@std@@UAE@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB268) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?xsputn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAE_JPBD_J@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB26C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?xsgetn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAE_JPAD_J@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB270) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?showmanyc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAE_JXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB274) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??1?$basic_streambuf@DU?$char_traits@D@std@@@std@@UAE@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB278) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??0?$basic_ostream@DU?$char_traits@D@std@@@std@@QAE@PAV?$basic_streambuf@DU?$char_traits@D@std@@@1@_N@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB27C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??0?$basic_ios@DU?$char_traits@D@std@@@std@@IAE@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB280) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Pninc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAEPADXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB284) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?out@?$codecvt@DDU_Mbstatet@@@std@@QBEHAAU_Mbstatet@@PBD1AAPBDPAD3AAPAD@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB288) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?in@?$codecvt@DDU_Mbstatet@@@std@@QBEHAAU_Mbstatet@@PBD1AAPBDPAD3AAPAD@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB28C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Init@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAEXXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB290) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??0?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAE@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB294) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?unshift@?$codecvt@DDU_Mbstatet@@@std@@QBEHAAU_Mbstatet@@PAD1AAPAD@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB298) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Getcat@?$codecvt@DDU_Mbstatet@@@std@@SAIPAPBVfacet@locale@2@PBV42@@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB29C) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?id@?$codecvt@DDU_Mbstatet@@@std@@2V0locale@2@A");
	*reinterpret_cast<FARPROC*>(0x30BAB2A0) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Xout_of_range@std@@YAXPBD@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB2A4) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Getgloballocale@locale@std@@CAPAV_Locimp@12@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB2A8) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??0_Lockit@std@@QAE@H@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB2AC) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??1_Lockit@std@@QAE@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB2B0) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Random_device@std@@YAIXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB2B4) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Getcvt@_Locinfo@std@@QBE?AU_Cvtvec@@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB2B8) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Xlength_error@std@@YAXPBD@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB2BC) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Xbad_alloc@std@@YAXXZ");
	*reinterpret_cast<FARPROC*>(0x30BAB2C0) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "?_Winerror_map@std@@YAHH@Z");
	*reinterpret_cast<FARPROC*>(0x30BAB2C4) = GetProcAddress(LoadLibraryA("msvcp140.dll"), "??1?$basic_ostream@DU?$char_traits@D@std@@@std@@UAE@XZ");
	*reinterpret_cast<FARPROC*>(0x30BAB2CC) = GetProcAddress(LoadLibraryA("shell32.dll"), "ShellExecuteA");
	*reinterpret_cast<FARPROC*>(0x30BAB2D4) = GetProcAddress(LoadLibraryA("user32.dll"), "FlashWindowEx");
	*reinterpret_cast<FARPROC*>(0x30BAB2D8) = GetProcAddress(LoadLibraryA("user32.dll"), "GetKeyState");
	*reinterpret_cast<FARPROC*>(0x30BAB2DC) = GetProcAddress(LoadLibraryA("user32.dll"), "ShowWindow");
	*reinterpret_cast<FARPROC*>(0x30BAB2E0) = GetProcAddress(LoadLibraryA("user32.dll"), "GetKeyNameTextA");
	*reinterpret_cast<FARPROC*>(0x30BAB2E4) = GetProcAddress(LoadLibraryA("user32.dll"), "MapVirtualKeyA");
	*reinterpret_cast<FARPROC*>(0x30BAB2E8) = GetProcAddress(LoadLibraryA("user32.dll"), "SetWindowLongW");
	*reinterpret_cast<FARPROC*>(0x30BAB2EC) = GetProcAddress(LoadLibraryA("user32.dll"), "GetClipboardData");
	*reinterpret_cast<FARPROC*>(0x30BAB2F0) = GetProcAddress(LoadLibraryA("user32.dll"), "CallWindowProcW");
	*reinterpret_cast<FARPROC*>(0x30BAB2F4) = GetProcAddress(LoadLibraryA("user32.dll"), "LoadCursorA");
	*reinterpret_cast<FARPROC*>(0x30BAB2F8) = GetProcAddress(LoadLibraryA("user32.dll"), "ScreenToClient");
	*reinterpret_cast<FARPROC*>(0x30BAB2FC) = GetProcAddress(LoadLibraryA("user32.dll"), "ClientToScreen");
	*reinterpret_cast<FARPROC*>(0x30BAB300) = GetProcAddress(LoadLibraryA("user32.dll"), "GetWindowThreadProcessId");
	*reinterpret_cast<FARPROC*>(0x30BAB304) = GetProcAddress(LoadLibraryA("user32.dll"), "GetCursorPos");
	*reinterpret_cast<FARPROC*>(0x30BAB308) = GetProcAddress(LoadLibraryA("user32.dll"), "SetCursor");
	*reinterpret_cast<FARPROC*>(0x30BAB30C) = GetProcAddress(LoadLibraryA("user32.dll"), "SetCursorPos");
	*reinterpret_cast<FARPROC*>(0x30BAB310) = GetProcAddress(LoadLibraryA("user32.dll"), "GetClientRect");
	*reinterpret_cast<FARPROC*>(0x30BAB314) = GetProcAddress(LoadLibraryA("user32.dll"), "GetForegroundWindow");
	*reinterpret_cast<FARPROC*>(0x30BAB318) = GetProcAddress(LoadLibraryA("user32.dll"), "SetClipboardData");
	*reinterpret_cast<FARPROC*>(0x30BAB31C) = GetProcAddress(LoadLibraryA("user32.dll"), "IsWindowUnicode");
	*reinterpret_cast<FARPROC*>(0x30BAB320) = GetProcAddress(LoadLibraryA("user32.dll"), "ReleaseCapture");
	*reinterpret_cast<FARPROC*>(0x30BAB324) = GetProcAddress(LoadLibraryA("user32.dll"), "EmptyClipboard");
	*reinterpret_cast<FARPROC*>(0x30BAB328) = GetProcAddress(LoadLibraryA("user32.dll"), "SetCapture");
	*reinterpret_cast<FARPROC*>(0x30BAB32C) = GetProcAddress(LoadLibraryA("user32.dll"), "GetCapture");
	*reinterpret_cast<FARPROC*>(0x30BAB330) = GetProcAddress(LoadLibraryA("user32.dll"), "TrackMouseEvent");
	*reinterpret_cast<FARPROC*>(0x30BAB334) = GetProcAddress(LoadLibraryA("user32.dll"), "CloseClipboard");
	*reinterpret_cast<FARPROC*>(0x30BAB338) = GetProcAddress(LoadLibraryA("user32.dll"), "GetWindowTextLengthW");
	*reinterpret_cast<FARPROC*>(0x30BAB33C) = GetProcAddress(LoadLibraryA("user32.dll"), "IsWindow");
	*reinterpret_cast<FARPROC*>(0x30BAB340) = GetProcAddress(LoadLibraryA("user32.dll"), "GetWindowTextA");
	*reinterpret_cast<FARPROC*>(0x30BAB344) = GetProcAddress(LoadLibraryA("user32.dll"), "EnumWindows");
	*reinterpret_cast<FARPROC*>(0x30BAB348) = GetProcAddress(LoadLibraryA("user32.dll"), "MessageBoxA");
	*reinterpret_cast<FARPROC*>(0x30BAB34C) = GetProcAddress(LoadLibraryA("user32.dll"), "OpenClipboard");
	*reinterpret_cast<FARPROC*>(0x30BAB354) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "__std_exception_destroy");
	*reinterpret_cast<FARPROC*>(0x30BAB358) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "__std_type_info_destroy_list");
	*reinterpret_cast<FARPROC*>(0x30BAB35C) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "__CxxFrameHandler");
	*reinterpret_cast<FARPROC*>(0x30BAB360) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "_except_handler4_common");
	*reinterpret_cast<FARPROC*>(0x30BAB364) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "__current_exception_context");
	*reinterpret_cast<FARPROC*>(0x30BAB368) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "__current_exception");
	*reinterpret_cast<FARPROC*>(0x30BAB36C) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "memchr");
	*reinterpret_cast<FARPROC*>(0x30BAB370) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "strrchr");
	*reinterpret_cast<FARPROC*>(0x30BAB374) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "strchr");
	*reinterpret_cast<FARPROC*>(0x30BAB378) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "strstr");
	*reinterpret_cast<FARPROC*>(0x30BAB37C) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "_purecall");
	*reinterpret_cast<FARPROC*>(0x30BAB380) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "__std_terminate");
	*reinterpret_cast<FARPROC*>(0x30BAB384) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "_CxxThrowException");
	*reinterpret_cast<FARPROC*>(0x30BAB388) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "memmove");
	*reinterpret_cast<FARPROC*>(0x30BAB38C) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "memset");
	*reinterpret_cast<FARPROC*>(0x30BAB390) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "__std_exception_copy");
	*reinterpret_cast<FARPROC*>(0x30BAB394) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "_setjmp3");
	*reinterpret_cast<FARPROC*>(0x30BAB398) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "longjmp");
	*reinterpret_cast<FARPROC*>(0x30BAB39C) = GetProcAddress(LoadLibraryA("vcruntime140.dll"), "memcpy");
	*reinterpret_cast<FARPROC*>(0x30BAB3A4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_strtoi64");
	*reinterpret_cast<FARPROC*>(0x30BAB3A8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strtod");
	*reinterpret_cast<FARPROC*>(0x30BAB3AC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_strtoui64");
	*reinterpret_cast<FARPROC*>(0x30BAB3B0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strtol");
	*reinterpret_cast<FARPROC*>(0x30BAB3B4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "atoi");
	*reinterpret_cast<FARPROC*>(0x30BAB3BC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_lock_file");
	*reinterpret_cast<FARPROC*>(0x30BAB3C0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_unlock_file");
	*reinterpret_cast<FARPROC*>(0x30BAB3C8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "realloc");
	*reinterpret_cast<FARPROC*>(0x30BAB3CC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "malloc");
	*reinterpret_cast<FARPROC*>(0x30BAB3D0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "free");
	*reinterpret_cast<FARPROC*>(0x30BAB3D4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_callnewh");
	*reinterpret_cast<FARPROC*>(0x30BAB3D8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "calloc");
	*reinterpret_cast<FARPROC*>(0x30BAB3E0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "___lc_codepage_func");
	*reinterpret_cast<FARPROC*>(0x30BAB3E4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "localeconv");
	*reinterpret_cast<FARPROC*>(0x30BAB3EC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_pow_precise");
	*reinterpret_cast<FARPROC*>(0x30BAB3F0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "floor");
	*reinterpret_cast<FARPROC*>(0x30BAB3F4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_CIatan2");
	*reinterpret_cast<FARPROC*>(0x30BAB3F8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "ceil");
	*reinterpret_cast<FARPROC*>(0x30BAB3FC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_sin_precise");
	*reinterpret_cast<FARPROC*>(0x30BAB400) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_cos_precise");
	*reinterpret_cast<FARPROC*>(0x30BAB404) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_acos_precise");
	*reinterpret_cast<FARPROC*>(0x30BAB408) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_sqrt_precise");
	*reinterpret_cast<FARPROC*>(0x30BAB40C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_CIfmod");
	*reinterpret_cast<FARPROC*>(0x30BAB410) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_fdclass");
	*reinterpret_cast<FARPROC*>(0x30BAB414) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_dclass");
	*reinterpret_cast<FARPROC*>(0x30BAB418) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "roundf");
	*reinterpret_cast<FARPROC*>(0x30BAB41C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "copysignf");
	*reinterpret_cast<FARPROC*>(0x30BAB420) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fmaxf");
	*reinterpret_cast<FARPROC*>(0x30BAB424) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "ldexp");
	*reinterpret_cast<FARPROC*>(0x30BAB428) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "remainderf");
	*reinterpret_cast<FARPROC*>(0x30BAB42C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_dsign");
	*reinterpret_cast<FARPROC*>(0x30BAB430) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_fdsign");
	*reinterpret_cast<FARPROC*>(0x30BAB434) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_dclass");
	*reinterpret_cast<FARPROC*>(0x30BAB438) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_hypotf");
	*reinterpret_cast<FARPROC*>(0x30BAB43C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_asin_precise");
	*reinterpret_cast<FARPROC*>(0x30BAB440) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_atan_precise");
	*reinterpret_cast<FARPROC*>(0x30BAB444) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_exp_precise");
	*reinterpret_cast<FARPROC*>(0x30BAB448) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_libm_sse2_tan_precise");
	*reinterpret_cast<FARPROC*>(0x30BAB44C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_dsign");
	*reinterpret_cast<FARPROC*>(0x30BAB454) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "abort");
	*reinterpret_cast<FARPROC*>(0x30BAB458) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "exit");
	*reinterpret_cast<FARPROC*>(0x30BAB45C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_errno");
	*reinterpret_cast<FARPROC*>(0x30BAB460) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_beginthreadex");
	*reinterpret_cast<FARPROC*>(0x30BAB464) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_invalid_parameter_noinfo_noreturn");
	*reinterpret_cast<FARPROC*>(0x30BAB468) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_initterm_e");
	*reinterpret_cast<FARPROC*>(0x30BAB46C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_initterm");
	*reinterpret_cast<FARPROC*>(0x30BAB470) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_cexit");
	*reinterpret_cast<FARPROC*>(0x30BAB474) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_crt_atexit");
	*reinterpret_cast<FARPROC*>(0x30BAB478) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_execute_onexit_table");
	*reinterpret_cast<FARPROC*>(0x30BAB47C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_register_onexit_function");
	*reinterpret_cast<FARPROC*>(0x30BAB480) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_initialize_onexit_table");
	*reinterpret_cast<FARPROC*>(0x30BAB484) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_initialize_narrow_environment");
	*reinterpret_cast<FARPROC*>(0x30BAB488) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_configure_narrow_argv");
	*reinterpret_cast<FARPROC*>(0x30BAB48C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_seh_filter_dll");
	*reinterpret_cast<FARPROC*>(0x30BAB490) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "terminate");
	*reinterpret_cast<FARPROC*>(0x30BAB498) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__stdio_common_vsnprintf_s");
	*reinterpret_cast<FARPROC*>(0x30BAB49C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__stdio_common_vswprintf");
	*reinterpret_cast<FARPROC*>(0x30BAB4A0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fputc");
	*reinterpret_cast<FARPROC*>(0x30BAB4A4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fflush");
	*reinterpret_cast<FARPROC*>(0x30BAB4A8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fclose");
	*reinterpret_cast<FARPROC*>(0x30BAB4AC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_wfopen");
	*reinterpret_cast<FARPROC*>(0x30BAB4B0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__stdio_common_vfprintf");
	*reinterpret_cast<FARPROC*>(0x30BAB4B4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fgetc");
	*reinterpret_cast<FARPROC*>(0x30BAB4B8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__acrt_iob_func");
	*reinterpret_cast<FARPROC*>(0x30BAB4BC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fwrite");
	*reinterpret_cast<FARPROC*>(0x30BAB4C0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fgetpos");
	*reinterpret_cast<FARPROC*>(0x30BAB4C4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "setvbuf");
	*reinterpret_cast<FARPROC*>(0x30BAB4C8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "ungetc");
	*reinterpret_cast<FARPROC*>(0x30BAB4CC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fsetpos");
	*reinterpret_cast<FARPROC*>(0x30BAB4D0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fread");
	*reinterpret_cast<FARPROC*>(0x30BAB4D4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_fseeki64");
	*reinterpret_cast<FARPROC*>(0x30BAB4D8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_get_stream_buffer_pointers");
	*reinterpret_cast<FARPROC*>(0x30BAB4DC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__stdio_common_vsscanf");
	*reinterpret_cast<FARPROC*>(0x30BAB4E0) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__stdio_common_vsprintf");
	*reinterpret_cast<FARPROC*>(0x30BAB4E4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "__stdio_common_vsprintf_s");
	*reinterpret_cast<FARPROC*>(0x30BAB4E8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "fseek");
	*reinterpret_cast<FARPROC*>(0x30BAB4EC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "ftell");
	*reinterpret_cast<FARPROC*>(0x30BAB4F4) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strncpy");
	*reinterpret_cast<FARPROC*>(0x30BAB4F8) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_strnicmp");
	*reinterpret_cast<FARPROC*>(0x30BAB4FC) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "toupper");
	*reinterpret_cast<FARPROC*>(0x30BAB500) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strcat_s");
	*reinterpret_cast<FARPROC*>(0x30BAB504) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "tolower");
	*reinterpret_cast<FARPROC*>(0x30BAB508) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "isdigit");
	*reinterpret_cast<FARPROC*>(0x30BAB50C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "wcsncmp");
	*reinterpret_cast<FARPROC*>(0x30BAB510) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strncmp");
	*reinterpret_cast<FARPROC*>(0x30BAB514) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_mbsdup");
	*reinterpret_cast<FARPROC*>(0x30BAB51C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_localtime64_s");
	*reinterpret_cast<FARPROC*>(0x30BAB520) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "strftime");
	*reinterpret_cast<FARPROC*>(0x30BAB524) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_time64");
	*reinterpret_cast<FARPROC*>(0x30BAB528) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_gmtime64_s");
	*reinterpret_cast<FARPROC*>(0x30BAB52C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "_localtime64");
	*reinterpret_cast<FARPROC*>(0x30BAB530) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "clock");
	*reinterpret_cast<FARPROC*>(0x30BAB538) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "rand");
	*reinterpret_cast<FARPROC*>(0x30BAB53C) = GetProcAddress(LoadLibraryA("ucrtbase.dll"), "qsort");
	*reinterpret_cast<FARPROC*>(0x30BAB544) = GetProcAddress(LoadLibraryA("ntdll.dll"), "NtQueryVirtualMemory");
	*reinterpret_cast<FARPROC*>(0x30BAB548) = GetProcAddress(LoadLibraryA("ntdll.dll"), "NtProtectVirtualMemory");
	*reinterpret_cast<FARPROC*>(0x30BAB54C) = GetProcAddress(LoadLibraryA("ntdll.dll"), "NtAllocateVirtualMemory");
	*reinterpret_cast<FARPROC*>(0x30BAB550) = GetProcAddress(LoadLibraryA("ntdll.dll"), "NtFreeVirtualMemory");
	*reinterpret_cast<FARPROC*>(0x30BAB554) = GetProcAddress(LoadLibraryA("ntdll.dll"), "NtQuerySystemInformation");
}

int find_pattern(const char* Module, const char* szPattern, int offset = 0)
{
	// Pattern to bytes
	int PatternBytes[256];
	int PatternBytesSize = 0;
	for (char* Current = (const_cast<char*>(szPattern)); Current < (const_cast<char*>(szPattern) + strlen(szPattern)); Current++) {
		if (*Current == '?') {
			++Current;
			if (*Current == '?')
				++Current;
			PatternBytes[PatternBytesSize] = -1;
			PatternBytesSize++;
		}
		else {
			PatternBytes[PatternBytesSize] = strtoul(Current, &Current, 16);
			PatternBytesSize++;
		}
	}

	BYTE* ScanAddress = (BYTE*)LoadLibraryA(Module);
	auto dosHeader = (PIMAGE_DOS_HEADER)ScanAddress;
	auto ntHeaders = (PIMAGE_NT_HEADERS)(ScanAddress + dosHeader->e_lfanew);
	int ScanSize = ntHeaders->OptionalHeader.SizeOfImage - PatternBytesSize;

	// Scan
	for (int i = 0; i < ScanSize; i++)
	{
		bool Found = true;
		for (int j = 0; j < PatternBytesSize; ++j)
		{
			if (ScanAddress[i + j] != PatternBytes[j] && PatternBytes[j] != -1)
			{
				Found = false;
				break;
			}
		}
		if (Found)
			return reinterpret_cast<int>(&ScanAddress[i]) + offset;
	}

	std::cout << "Failed to find " << szPattern << " in " << Module << std::endl;
	system("pause");

	return 0;
}

struct module_info_t
{
	uint32_t start = 0;
	uint32_t end = 0;
	std::string name = "";
};

// c&p from somewhere
typedef void* (*create_interface_fn)(const char* pName, int* pReturnCode);

create_interface_fn get_module_factory(HMODULE module)
{
	return reinterpret_cast<create_interface_fn>(GetProcAddress(module, "CreateInterface"));
}

void* get_interface(HMODULE module, const char* szInterfaceVersion)
{
	create_interface_fn f = get_module_factory(module);
	auto result = reinterpret_cast<void*>(f(szInterfaceVersion, nullptr));

	return result;
}


std::vector<module_info_t> g_modules = {};
std::unordered_map<uint32_t, std::string> g_interfaces = {};

void init()
{
	g_interfaces.emplace(0x61A0F0D4, "engine.VEngineRandom001");
	g_interfaces.emplace(0x5C3C789C, "client.VCLIENTTOOLS001");
	g_interfaces.emplace(0x5F04AFA8, "vgui2.VGUI_InputInternal001");
	g_interfaces.emplace(0x61C6CB70, "engine.BlackBoxVersion001");
	g_interfaces.emplace(0x5C37F378, "client.GameUI011");
	g_interfaces.emplace(0x61A10F58, "engine.VSERVERENGINETOOLS001");
	g_interfaces.emplace(0x5F1547D0, "vguimatsurface.VGUI_Surface031");
	g_interfaces.emplace(0x619FFEB4, "engine.VPhysicsDebugOverlay001");
	g_interfaces.emplace(0x6198E6DC, "engine.IEngineSoundServer003");
	g_interfaces.emplace(0x6E32AC38, "inputsystem.InputStackSystemVersion001");
	g_interfaces.emplace(0x6E4B03D0, "filesystem_stdio.QueuedLoaderVersion001");
	g_interfaces.emplace(0x61A07404, "engine.EngineTraceClient004");
	g_interfaces.emplace(0x619FFEB0, "engine.VDebugOverlay004");
	g_interfaces.emplace(0x61A0F8E8, "engine.FileLoggingListener001");
	g_interfaces.emplace(0x5F79D5E8, "materialsystem.MaterialSystemHardwareConfig013");
	g_interfaces.emplace(0x64D4A688, "engine.StaticPropMgrServer002");
	g_interfaces.emplace(0x61A0634C, "engine.BugReporterUserName001");
	g_interfaces.emplace(0x5F760004, "materialsystem.ShaderSystem002");
	g_interfaces.emplace(0x61A01CF4, "engine.VEngineEffects001");
	g_interfaces.emplace(0x57F0A470, "client.IEffects001");
	g_interfaces.emplace(0x6C8B2980, "datacache.VResourceAccessControl001");
	g_interfaces.emplace(0x6E4AFF28, "filesystem_stdio.VNewAsyncFileSystem001");
	g_interfaces.emplace(0x61A07818, "engine.GAMEEVENTSMANAGER001");
	g_interfaces.emplace(0x6C8A4F18, "datacache.MDLCache004");
	g_interfaces.emplace(0x61A0D560, "engine.VModelInfoClient004");
	g_interfaces.emplace(0x6C8A4E20, "datacache.VDataCache003");
	g_interfaces.emplace(0x61A10F5C, "engine.VTOOLFRAMEWORKVERSION002");
	g_interfaces.emplace(0x6E4AFFAC, "filesystem_stdio.VBaseFileSystem011");
	g_interfaces.emplace(0x5F79D4D0, "materialsystem.ShaderDLL004");
	g_interfaces.emplace(0x57C562DC, "tier0>g_pMemAlloc");
	g_interfaces.emplace(0x5C37DF28, "client.VClientPrediction001");
	g_interfaces.emplace(0x61A10E40, "engine.XboxSystemInterface002");
	g_interfaces.emplace(0x6C89A3C0, "datacache.VPrecacheSystem001");
	g_interfaces.emplace(0x57F04EB8, "client.ClientRenderTargets001");
	g_interfaces.emplace(0x6198E65C, "engine.IEngineSoundClient003");
	g_interfaces.emplace(0x57F218CC, "client.VGuiModuleLoader003");
	g_interfaces.emplace(0x5F75FE48, "materialsystem.VMaterialSystemStub001");
	g_interfaces.emplace(0x64D4A3D0, "engine.SpatialPartition001");
	g_interfaces.emplace(0x745C9A10, "vstdlib.EventSystem001");
	g_interfaces.emplace(0x57C562DC, "tier0>g_pMemAlloc");
	g_interfaces.emplace(0x5C37B010, "client.GameMovement001");
	g_interfaces.emplace(0x61A10FB0, "engine.VCLIENTENGINETOOLS001");
	g_interfaces.emplace(0x61A0EE90, "engine.VEngineClientStringTable001");
	g_interfaces.emplace(0x5F040670, "vgui2.VGUI_System010");
	g_interfaces.emplace(0x5F65FE98, "studiorender.VStudioRender026");
	g_interfaces.emplace(0x5BF50100, "client.ClientLeafSystem002");
	g_interfaces.emplace(0x5F8CAA5C, "vphysics.VPhysicsCollision007");
	g_interfaces.emplace(0x5F75DE10, "materialsystem.COLORCORRECTION_VERSION_1");
	g_interfaces.emplace(0x64D4CE58, "engine.VENGINETOOLFRAMEWORK003");
	g_interfaces.emplace(0x5BF5010C, "client.ClientAlphaPropertyMgrV001");
	g_interfaces.emplace(0x61A05B48, "engine.VEngineServer023");
	g_interfaces.emplace(0x64D4A684, "engine.StaticPropMgrClient005");
	g_interfaces.emplace(0x5F04AFA8, "vgui2.VGUI_InputInternal001");
	g_interfaces.emplace(0x61A07510, "engine.EngineTraceServer004");
	g_interfaces.emplace(0x61C7C4C8, "engine.GAMEEVENTSMANAGER002");
	g_interfaces.emplace(0x61BE4720, "engine.VEngineModel016");
	g_interfaces.emplace(0x5F75F8A0, "materialsystem.VMaterialSystemConfig004");
	g_interfaces.emplace(0x61A0EECC, "engine.VEngineServerStringTable001");
	g_interfaces.emplace(0x61A0FF8C, "engine.VENGINE_GAMEUIFUNCS_VERSION005");
	g_interfaces.emplace(0x61A04518, "engine.ISERVERPLUGINHELPERS001");
	g_interfaces.emplace(0x619FD3E8, "engine.VEngineClient014");
	g_interfaces.emplace(0x57F08CF8, "client.VCLIENTMATERIALSYSTEM001");
	g_interfaces.emplace(0x5F8D6078, "vphysics.VPhysicsSurfaceProps001");
	g_interfaces.emplace(0x5C6CDC48, "matchmaking.VENGINE_GAMETYPES_VERSION002");
	g_interfaces.emplace(0x61A0E1CC, "engine.INETSUPPORT_003");
	g_interfaces.emplace(0x61A10728, "engine.VoiceServer002");
	g_interfaces.emplace(0x5F8CAA20, "vphysics.VPhysics031");
	g_interfaces.emplace(0x745CF6AC, "vstdlib.VProcessUtils002");
	g_interfaces.emplace(0x5F04C498, "vgui2.VGUI_ivgui008");
	g_interfaces.emplace(0x61A01D14, "engine.VEngineRenderView014");
	g_interfaces.emplace(0x57F118D0, "client.VParticleSystemQuery004");
	g_interfaces.emplace(0x64D4CE58, "engine.VENGINETOOLFRAMEWORK003");
	g_interfaces.emplace(0x61A10768, "engine.VProfExport001");
	g_interfaces.emplace(0x64D4D0F8, "engine.VEngineVGui001");
	g_interfaces.emplace(0x5BF3FFB4, "client.VClientEntityList003");
	g_interfaces.emplace(0x5F04C2D0, "vgui2.VGUI_Scheme010");
	g_interfaces.emplace(0x61A0FF90, "engine.VENGINE_HLDS_API_VERSION002");
	g_interfaces.emplace(0x61A06B98, "engine.VCvarQuery001");
	g_interfaces.emplace(0x57F08A18, "client.GameClientExports001");
	g_interfaces.emplace(0x5F0408C4, "vgui2.VGUI_Panel009");
	g_interfaces.emplace(0x5BF1AC40, "client.VClientDllSharedAppSystems001");
	g_interfaces.emplace(0x61C09180, "engine.VEngineShadowMgr002");
	g_interfaces.emplace(0x61A10030, "engine.VENGINE_LAUNCHER_API_VERSION004");
	g_interfaces.emplace(0x5CEE8A70, "localize.Localize_001");
	g_interfaces.emplace(0x5C6BA3F4, "matchmaking.MATCHFRAMEWORK_001");
	g_interfaces.emplace(0x61C6C730, "engine.GameServerData001");
	g_interfaces.emplace(0x5F782AC8, "materialsystem.VMaterialSystem080");
	g_interfaces.emplace(0x6E4AFFA8, "filesystem_stdio.VFileSystem017");
	g_interfaces.emplace(0x61A0D5C8, "engine.VModelInfoServer002");
	g_interfaces.emplace(0x5BF1AC58, "client.VClient018");
	g_interfaces.emplace(0x5D3FC098, "panorama.PanoramaUIEngine001");
	g_interfaces.emplace(0x57F2160C, "client.GameConsole004");
	g_interfaces.emplace(0x745CD310, "vstdlib.VEngineCvar007");
	g_interfaces.emplace(0x5F1547D4, "vguimatsurface.SchemeSurface001");
	g_interfaces.emplace(0x5C35FBC0, "client.RenderToRTHelper001");
	g_interfaces.emplace(0x6C8A4F1C, "datacache.VStudioDataCache005");
	g_interfaces.emplace(0x57F21774, "client.RunGameEngine005");
	g_interfaces.emplace(0x6E335388, "inputsystem.InputSystemVersion001");
}

void call_dllmain()
{
	uint32_t oep = 0x30B18E52;

	__asm
	{
		push 0
		push 1
		push 0x1860000
		call oep
	}
}

void check_mem(void* address, int size)
{
	MEMORY_BASIC_INFORMATION mem;
	if (!VirtualQuery(reinterpret_cast<void*>(address), &mem, sizeof(mem)))
	{
		std::cout << "Failed to query memory ( did u inject steam_module.dll into steam.exe ? )" << std::endl;
		Sleep(3000);
		TerminateProcess(reinterpret_cast<HANDLE>(-1), 0);
	}

	if (mem.RegionSize != size)
	{
		std::cout << "Failed to find memory ( did u inject steam_module.dll into steam.exe ? )" << std::endl;
		Sleep(3000);
		TerminateProcess(reinterpret_cast<HANDLE>(-1), 0);
	}
}

void main()
{
	unsigned char user_struct_1[56] = {
	0x38, 0x00, 0x86, 0x01, 0x38, 0x00, 0x86, 0x01, 0x9F, 0x36, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x73, 0x2B, 0x6C, 0x6A, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x4F, 0x00, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x87, 0x01, 0x00, 0x00, 0x88, 0x01
	};

	unsigned char user_struct_2[9] = {
	0x50, 0x69, 0x6E, 0x6B, 0x4B, 0x69, 0x6E, 0x67, 0x00
	};

	unsigned char runtime_table_data[632] = {
	0xDB, 0xFA, 0x30, 0x01, 0x40, 0xB9, 0x6C, 0x57, 0x20, 0x4D, 0x7D, 0x05,
	0xF0, 0xA9, 0x4C, 0x57, 0x16, 0xF3, 0x81, 0x07, 0x80, 0x38, 0x2D, 0x57,
	0x8F, 0x74, 0x80, 0x0A, 0x60, 0xD5, 0x37, 0x57, 0xEA, 0x54, 0x2F, 0x0E,
	0x30, 0xCC, 0x7B, 0x57, 0x7C, 0x5F, 0x98, 0x0E, 0xCC, 0x9D, 0x2B, 0x57,
	0x15, 0xFA, 0xDE, 0x11, 0x20, 0x41, 0x45, 0x57, 0xB9, 0x56, 0x2A, 0x14,
	0xE0, 0x65, 0xF3, 0x5C, 0x99, 0x04, 0x09, 0x17, 0x73, 0xDE, 0x38, 0x57,
	0x96, 0x51, 0x20, 0x17, 0x10, 0x6F, 0x50, 0x57, 0xA1, 0x19, 0x76, 0x18,
	0x1A, 0xF6, 0x6E, 0x61, 0x17, 0xAE, 0x11, 0x1A, 0x53, 0x38, 0x52, 0x57,
	0x32, 0xD9, 0xE1, 0x1A, 0xB0, 0x66, 0x63, 0x57, 0xE3, 0xBD, 0x67, 0x1D,
	0x36, 0x4B, 0x50, 0x57, 0x88, 0x89, 0x0A, 0x22, 0x80, 0x6C, 0x67, 0x57,
	0x29, 0x19, 0x49, 0x22, 0x90, 0xDE, 0x4E, 0x57, 0xCF, 0xF0, 0xDF, 0x24,
	0x90, 0x00, 0x3F, 0x57, 0x0C, 0x6E, 0x6C, 0x2F, 0x38, 0x50, 0x44, 0x57,
	0x6A, 0x59, 0x51, 0x30, 0xEB, 0xD9, 0x37, 0x57, 0x62, 0xAA, 0xFB, 0x36,
	0x59, 0x1B, 0x6D, 0x57, 0x76, 0xE9, 0x97, 0x37, 0x12, 0xD7, 0x71, 0x61,
	0x54, 0x2C, 0xC9, 0x37, 0xF0, 0x76, 0x30, 0x57, 0x03, 0xF3, 0x4E, 0x38,
	0xF0, 0xB4, 0x55, 0x57, 0xB2, 0xCC, 0xBB, 0x4D, 0x90, 0xCF, 0x6A, 0x5F,
	0xA9, 0x99, 0x47, 0x4E, 0xE3, 0xE9, 0x52, 0x57, 0x62, 0x26, 0x5E, 0x4E,
	0xBB, 0x26, 0x2B, 0x57, 0x89, 0xE4, 0x11, 0x52, 0x30, 0xD2, 0x43, 0x57,
	0x12, 0x6B, 0x77, 0x5A, 0x32, 0xC8, 0x8E, 0x57, 0x8C, 0x5B, 0x37, 0x62,
	0xD0, 0xE4, 0x53, 0x61, 0x7F, 0x9F, 0xFD, 0x68, 0x90, 0xD3, 0x4B, 0x57,
	0x13, 0xAA, 0x05, 0x6A, 0x70, 0x6B, 0x47, 0x57, 0xEC, 0x13, 0x87, 0x6C,
	0x99, 0x42, 0x39, 0x57, 0x4B, 0x67, 0x7E, 0x6E, 0xF0, 0x46, 0x46, 0x57,
	0xE0, 0xB3, 0xC3, 0x75, 0x30, 0x08, 0x2D, 0x57, 0x0E, 0x70, 0xD5, 0x77,
	0x40, 0x31, 0x46, 0x57, 0xD5, 0x8C, 0x17, 0x7B, 0xDA, 0x76, 0x9F, 0x5F,
	0xE7, 0x9D, 0xDF, 0x7B, 0x90, 0x81, 0x4A, 0x57, 0xB1, 0xE9, 0xA5, 0x7C,
	0xA0, 0x68, 0x6B, 0x61, 0x59, 0x8C, 0x47, 0x7F, 0x50, 0xBF, 0x8B, 0x57,
	0x9E, 0x98, 0x8F, 0x7F, 0x70, 0xC1, 0x6C, 0x57, 0x4D, 0x85, 0x55, 0x84,
	0x90, 0xFC, 0x2C, 0x57, 0xCB, 0x9A, 0x0E, 0x86, 0x15, 0x6A, 0x51, 0x57,
	0x02, 0xA8, 0x57, 0x87, 0xB5, 0x32, 0x55, 0x57, 0xE6, 0x78, 0xA5, 0x8B,
	0x10, 0x0A, 0xF6, 0x5C, 0x84, 0x50, 0xE3, 0x8D, 0x30, 0x75, 0x30, 0x57,
	0xCB, 0x84, 0xAC, 0x8E, 0x80, 0x77, 0x59, 0x61, 0xEE, 0xD0, 0xEE, 0x91,
	0xB3, 0x06, 0x7C, 0x57, 0x34, 0xF8, 0xAE, 0x9B, 0x4C, 0x69, 0x30, 0x57,
	0x0F, 0x53, 0x97, 0x9E, 0x60, 0xA2, 0x5D, 0x57, 0x3B, 0x44, 0x89, 0xA0,
	0xC2, 0x02, 0x46, 0x57, 0xD0, 0x4C, 0x82, 0xA4, 0x90, 0x63, 0xAB, 0x57,
	0x35, 0x78, 0x7C, 0xAA, 0xB0, 0x38, 0x42, 0x57, 0xCF, 0x8A, 0xD6, 0xAE,
	0x90, 0x7F, 0x7B, 0x57, 0xD5, 0x56, 0x84, 0xB4, 0x30, 0x13, 0x72, 0x57,
	0xA3, 0x26, 0xC0, 0xB4, 0x60, 0x36, 0x30, 0x57, 0x28, 0xB9, 0x99, 0xB6,
	0xB6, 0x55, 0x3E, 0x57, 0x5B, 0x2C, 0x52, 0xBA, 0xA8, 0xDC, 0x33, 0x57,
	0x3A, 0x78, 0xBB, 0xBF, 0xC9, 0xFA, 0x55, 0x57, 0x75, 0x1E, 0x75, 0xC2,
	0xB0, 0x86, 0xAB, 0x57, 0x36, 0xDB, 0x2E, 0xC5, 0xA0, 0xAB, 0x53, 0x61,
	0x86, 0xE4, 0x48, 0xC8, 0xF0, 0x30, 0x55, 0x61, 0x69, 0x0B, 0xB9, 0xC8,
	0x04, 0xAA, 0x51, 0x57, 0x22, 0x88, 0xE8, 0xC8, 0x68, 0xD6, 0x54, 0x57,
	0x88, 0x08, 0x97, 0xCD, 0x90, 0x0C, 0x46, 0x57, 0x66, 0x5E, 0xE6, 0xCE,
	0x32, 0xCA, 0x51, 0x57, 0x02, 0xE6, 0x9F, 0xD2, 0xC5, 0xBA, 0x64, 0x57,
	0x8C, 0x48, 0xA6, 0xD4, 0x4F, 0x09, 0x46, 0x57, 0xF4, 0x3C, 0xD3, 0xD5,
	0x80, 0xD5, 0x66, 0x57, 0xCD, 0x7C, 0xEB, 0xD8, 0x9F, 0xFB, 0x2F, 0x57,
	0xD5, 0x97, 0x98, 0xDA, 0x2B, 0xE8, 0x3D, 0x57, 0xB5, 0xAE, 0x27, 0xDB,
	0xB6, 0x55, 0x3E, 0x57, 0x9D, 0xA8, 0x59, 0xDF, 0x85, 0x02, 0x46, 0x57,
	0xA7, 0x4B, 0xD2, 0xEA, 0x00, 0x3D, 0x6B, 0x61, 0x17, 0x23, 0x4C, 0xEC,
	0xE4, 0x08, 0x7C, 0x57, 0x2B, 0xE7, 0x38, 0xF1, 0x30, 0x19, 0x4F, 0x57,
	0xA9, 0x20, 0xD6, 0xF6, 0x80, 0xDA, 0x4E, 0x61, 0x96, 0xD9, 0x0D, 0xF7,
	0x50, 0x5E, 0x8B, 0x57, 0x88, 0x22, 0x50, 0xF7, 0x40, 0x62, 0x2F, 0x57,
	0xAC, 0x31, 0x09, 0xFA, 0x10, 0xD6, 0x4F, 0x57
	};

	unsigned char runtime_table_2_data[784] = {
	0x2C, 0x2C, 0xD0, 0x01, 0xD4, 0xF0, 0xA0, 0x61, 0x8E, 0x93, 0xFB, 0x01,
	0x9C, 0x78, 0x3C, 0x5C, 0x2D, 0x51, 0xD2, 0x03, 0xA8, 0xAF, 0x04, 0x5F,
	0xB9, 0xB6, 0x12, 0x04, 0x70, 0xCB, 0xC6, 0x61, 0xE8, 0xA9, 0x25, 0x06,
	0x78, 0xF3, 0x37, 0x5C, 0x56, 0x74, 0x2E, 0x0A, 0x58, 0x0F, 0xA1, 0x61,
	0x58, 0xE7, 0xA9, 0x0B, 0xD0, 0x47, 0x15, 0x5F, 0x19, 0xC7, 0xDA, 0x0B,
	0xB4, 0xFE, 0x9F, 0x61, 0x08, 0x5C, 0x40, 0x0D, 0xDC, 0xE6, 0x98, 0x61,
	0xA6, 0x52, 0x4A, 0x0D, 0x38, 0xAC, 0x32, 0x6E, 0xFB, 0x59, 0xFA, 0x0F,
	0xD0, 0x03, 0x4B, 0x6E, 0xF3, 0xAC, 0xFD, 0x16, 0x04, 0x74, 0xA0, 0x61,
	0xDA, 0x2A, 0x79, 0x1C, 0xB0, 0xFE, 0x9F, 0x61, 0xA5, 0x65, 0xBB, 0x1C,
	0xE8, 0xF8, 0xA0, 0x61, 0x56, 0x55, 0xCB, 0x1C, 0xE8, 0xD5, 0x79, 0x5F,
	0xE4, 0x46, 0x60, 0x1E, 0x88, 0xA6, 0xD4, 0x64, 0xFE, 0xD6, 0x79, 0x25,
	0x4C, 0x63, 0xA0, 0x61, 0xF3, 0x0E, 0x60, 0x27, 0x04, 0x00, 0x76, 0x5F,
	0x05, 0x73, 0x82, 0x28, 0xF4, 0x1C, 0xA0, 0x61, 0x6F, 0x96, 0x0B, 0x2A,
	0x70, 0xA4, 0xF0, 0x57, 0x2A, 0x96, 0xF3, 0x2A, 0x80, 0x29, 0x8B, 0x6C,
	0x33, 0x31, 0x75, 0x2E, 0x28, 0xFF, 0x4A, 0x6E, 0x31, 0x93, 0x4B, 0x30,
	0x18, 0x78, 0xA0, 0x61, 0xB6, 0x80, 0x85, 0x31, 0x18, 0x4F, 0x8A, 0x6C,
	0x68, 0x7E, 0xDD, 0x31, 0x60, 0xD5, 0xA0, 0x61, 0xAD, 0x92, 0x3B, 0x32,
	0x20, 0x4E, 0x8A, 0x6C, 0x7E, 0x4C, 0x5D, 0x35, 0x5C, 0x0F, 0xA1, 0x61,
	0xAA, 0x43, 0x88, 0x39, 0xAC, 0xFF, 0x4A, 0x6E, 0xA9, 0xD0, 0xE0, 0x39,
	0xD0, 0xD4, 0x79, 0x5F, 0x58, 0x75, 0xAC, 0x3E, 0xDC, 0x62, 0xC5, 0x57,
	0xC7, 0x69, 0x8E, 0x3F, 0x28, 0xDF, 0x37, 0x5C, 0x5E, 0x95, 0xF5, 0x3F,
	0x40, 0x0E, 0xA1, 0x61, 0x58, 0x94, 0x63, 0x42, 0xC0, 0xA3, 0x89, 0x6C,
	0x8F, 0x14, 0x47, 0x47, 0xB8, 0x4E, 0xF0, 0x57, 0xDF, 0xAE, 0x3B, 0x48,
	0x5C, 0xE6, 0x98, 0x61, 0x08, 0x4D, 0x15, 0x49, 0xCC, 0x18, 0xF2, 0x57,
	0xBB, 0x3A, 0x81, 0x4C, 0x48, 0xFE, 0x75, 0x5F, 0xEB, 0x1B, 0x29, 0x4E,
	0xD0, 0xA3, 0xD4, 0x64, 0xDA, 0x43, 0xD6, 0x50, 0x10, 0x9A, 0x5C, 0x74,
	0x0D, 0xF1, 0xE5, 0x51, 0xDC, 0x62, 0xC5, 0x57, 0xB1, 0x69, 0x43, 0x52,
	0x10, 0xB0, 0x37, 0x5C, 0x9C, 0x5A, 0xF3, 0x54, 0xB0, 0x0F, 0xA1, 0x61,
	0x24, 0x45, 0x1E, 0x5A, 0x90, 0xEE, 0xA0, 0x61, 0xBF, 0x02, 0x45, 0x5A,
	0x70, 0x06, 0x04, 0x5F, 0x32, 0x7C, 0x8E, 0x5A, 0x98, 0xFE, 0x65, 0x5F,
	0xB3, 0xFE, 0xBD, 0x5A, 0x00, 0x01, 0xF5, 0x5B, 0x57, 0xA7, 0x9C, 0x5D,
	0x5C, 0xAA, 0x8C, 0x5F, 0x47, 0x15, 0x02, 0x61, 0x10, 0xDE, 0x75, 0x5F,
	0xB2, 0x64, 0x7E, 0x62, 0x58, 0xCE, 0xD4, 0x64, 0x87, 0x97, 0x74, 0x63,
	0x0C, 0x01, 0xF5, 0x5B, 0x2B, 0x14, 0xA4, 0x63, 0x48, 0x5B, 0xA0, 0x61,
	0xF0, 0x61, 0xDE, 0x63, 0x84, 0xA6, 0xD4, 0x64, 0xFD, 0x35, 0xAB, 0x64,
	0xA8, 0xAF, 0x04, 0x5F, 0x59, 0x1F, 0x21, 0x6C, 0x10, 0x75, 0xA0, 0x61,
	0x0D, 0x55, 0xC1, 0x6E, 0xC8, 0xC4, 0xC7, 0x61, 0xB5, 0xD1, 0xDE, 0x6E,
	0x20, 0x47, 0xBE, 0x61, 0xAE, 0xA8, 0xFD, 0x6E, 0xA0, 0xF8, 0x75, 0x5F,
	0xF8, 0x17, 0x36, 0x6F, 0xCC, 0xEE, 0xA0, 0x61, 0xE8, 0x04, 0xBC, 0x72,
	0x8C, 0xFF, 0xA0, 0x61, 0x45, 0x58, 0xF4, 0x7C, 0x18, 0x45, 0xA0, 0x61,
	0x68, 0x7F, 0x7C, 0x7E, 0xE8, 0xD3, 0x9F, 0x61, 0xB7, 0x30, 0x83, 0x7E,
	0xF8, 0x8C, 0xF0, 0x57, 0x27, 0x9A, 0x3E, 0x88, 0x78, 0x60, 0x8D, 0x5F,
	0xD8, 0x4C, 0xA6, 0x8A, 0x48, 0xDC, 0x6C, 0x5C, 0x11, 0xE7, 0xC9, 0x8A,
	0xCC, 0xE1, 0xA0, 0x61, 0x8F, 0x1F, 0x7D, 0x8D, 0x28, 0x07, 0xA1, 0x61,
	0x2D, 0x62, 0x15, 0x8F, 0x20, 0xAA, 0x8C, 0x5F, 0x20, 0xB4, 0x7B, 0x9A,
	0xAC, 0xF6, 0x5C, 0x74, 0x39, 0x4D, 0xFB, 0x9A, 0x98, 0xC4, 0x04, 0x5F,
	0x90, 0xAB, 0xCE, 0x9F, 0x14, 0x1D, 0xA0, 0x61, 0x9B, 0x00, 0x4C, 0xA8,
	0xD0, 0x18, 0xF1, 0x57, 0xC9, 0x99, 0x2D, 0xAB, 0x58, 0xCE, 0xD4, 0x64,
	0xFB, 0x8A, 0xB1, 0xAB, 0x68, 0x07, 0xA1, 0x61, 0x13, 0xAF, 0x2F, 0xAC,
	0xF8, 0xD0, 0xD4, 0x64, 0x4D, 0x23, 0xD9, 0xAD, 0xB4, 0xFF, 0xF3, 0x5B,
	0x15, 0xD9, 0xFD, 0xAF, 0xD0, 0xC2, 0x04, 0x5F, 0x30, 0x07, 0x99, 0xB0,
	0x90, 0xFF, 0xA0, 0x61, 0x13, 0xA6, 0xD9, 0xBF, 0x98, 0x6B, 0xA0, 0x61,
	0xD8, 0xFE, 0x2A, 0xC1, 0x18, 0x8A, 0xF0, 0x57, 0xD4, 0xD2, 0xDA, 0xC5,
	0xC4, 0x08, 0x04, 0x5F, 0xA3, 0x12, 0x8C, 0xCA, 0x40, 0xAC, 0xF1, 0x5B,
	0x6E, 0x10, 0xF2, 0xCA, 0x80, 0x91, 0xC0, 0x61, 0x7F, 0xCA, 0xDF, 0xCE,
	0x30, 0x00, 0xA1, 0x61, 0xF5, 0xC3, 0xBE, 0xD5, 0x70, 0x8A, 0xEE, 0x5C,
	0x53, 0x25, 0x08, 0xD8, 0xF4, 0xA3, 0x6B, 0x5C, 0x10, 0x7B, 0x41, 0xDA,
	0x30, 0xC7, 0xC6, 0x61, 0x59, 0xDA, 0x33, 0xE2, 0xC8, 0x2A, 0x78, 0x5F,
	0x0F, 0x3F, 0xCE, 0xE2, 0xA8, 0xFF, 0x4A, 0x6E, 0x6A, 0xBC, 0xC3, 0xEA,
	0xC8, 0xD5, 0xA0, 0x61, 0x41, 0xEB, 0x9F, 0xF1, 0x58, 0xAC, 0xF1, 0x5B,
	0x46, 0x86, 0x29, 0xF2, 0x98, 0xC0, 0x3F, 0x5D, 0x30, 0x7E, 0xDB, 0xF2,
	0x0C, 0x16, 0xF2, 0x57, 0xB2, 0xDC, 0x2D, 0xF3, 0x10, 0xD3, 0x5C, 0x74,
	0xAB, 0xED, 0x73, 0xF3, 0xD4, 0x47, 0x15, 0x5F, 0x5B, 0x31, 0x82, 0xF7,
	0xC0, 0xFB, 0x35, 0x5C, 0x64, 0xD3, 0x83, 0xF7, 0x1C, 0x4F, 0x8A, 0x6C,
	0xCB, 0x66, 0x17, 0xF9, 0x74, 0x17, 0xF2, 0x57, 0xFD, 0xF6, 0x9C, 0xFC,
	0x88, 0x53, 0x33, 0x6E
	};

	void* hack_address = reinterpret_cast<void*>(0x30930000); check_mem(hack_address, 0x0041D000);
	void* user_struct = reinterpret_cast<void*>(0x1860000); check_mem(user_struct, 0x00001000);
	void* runtime_table = reinterpret_cast<void*>(0x1870000); check_mem(runtime_table, 0x00001000);
	void* runtime_table_2 = reinterpret_cast<void*>(0x1880000); check_mem(runtime_table_2, 0x00001000);

	std::cout << "Waiting for serverbrowser.dll" << std::endl;
	while (!GetModuleHandleA("serverbrowser.dll"))
	{
		Sleep(100);
	}
	std::cout << "Found serverbrowser.dll" << std::endl;

	std::cout << "Init..." << std::endl;

	init();

	std::cout << "Fixing runtime tables" << std::endl;

	// table 1

	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x4) = find_pattern("client.dll", "84 C0 75 09 38 05");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xc) = find_pattern("client.dll", "55 8B EC 8B 0D ?? ?? ?? ?? 83 EC 0C 8B 01 53 56 57 FF 90");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x14) = find_pattern("client.dll", "55 8B EC 83 E4 F8 81 EC 84 00 00 00 53 8B D9 56 57 83 BB 60 32 00 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1c) = find_pattern("client.dll", "55 8B EC 8B 0D ?? ?? ?? ?? 8B 01 5D FF 60 ?? CC 55 8B EC 83 E4 C0");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x24) = find_pattern("client.dll", "55 8B EC 8B 45 14 3D 59 1B 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x2c) = find_pattern("client.dll", "8B 0D ?? ?? ?? ?? BA ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 C4 04");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x34) = find_pattern("client.dll", "55 8B EC 83 EC 10 53 56 57 8B F9 8B 87 E8 00 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x3c) = find_pattern("shaderapidx9.dll", "A1 ?? ?? ?? ?? A8 01 75 17 83 C8 01 B9 ?? ?? ?? ?? 68 ?? ?? ?? ?? A3 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B 0D ?? ?? ?? ?? 8B 01 FF 50 ?? 83 F8 01");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x44) = find_pattern("client.dll", "56 52 FF 50 ?? 89 44 24 14");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x4c) = find_pattern("client.dll", "56 8B F1 85 F6 74 31");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x54) = find_pattern("engine.dll", "E8 ?? ?? ?? ?? 84 C0 8B 45 08");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x5c) = find_pattern("client.dll", "E8 ?? ?? ?? ?? FF 76 0C 8D 48 04");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x64) = find_pattern("client.dll", "55 8B EC 83 EC 0C 53 56 8B 71 58");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x6c) = find_pattern("client.dll", "84 C0 75 0D F6 87 28 0A 00 00 0A");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x74) = find_pattern("client.dll", "55 8B EC 51 53 56 8B 75 08 8B D9 57 6B FE 34");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x7c) = find_pattern("client.dll", "55 8B EC 83 EC 08 8B 15 ?? ?? ?? ?? 0F 57 C0");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x84) = find_pattern("client.dll", "55 8B EC 53 8B 5D 08 56 57 8B F9 33 F6 39 77 28");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x8c) = find_pattern("client.dll", "E8 ?? ?? ?? ?? 8B 0E 83 C1 10");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x94) = find_pattern("client.dll", "B9 ?? ?? ?? ?? F3 0F 11 04 24 FF 50 ?? FF D7");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x9c) = find_pattern("client.dll", "84 C0 75 0C 5B");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xa4) = find_pattern("engine.dll", "E8 ?? ?? ?? ?? 83 C4 08 84 C0 75 10 FF 75 0C");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xac) = find_pattern("client.dll", "55 8B EC 83 E4 F8 83 EC 64 53 56 57 8B F1");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xb4) = find_pattern("client.dll", "55 8B EC 83 E4 F8 83 EC 70 56 57 8B F9 89 7C 24 14");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xbc) = find_pattern("materialsystem.dll", "55 8B EC 83 EC 0C 56 8B F1 8A 46 20");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xc4) = find_pattern("client.dll", "84 C0 75 05 B0 01");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xcc) = find_pattern("client.dll", "A1 ?? ?? ?? ?? 5E 8B 40 10");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xd4) = find_pattern("client.dll", "55 8B EC 51 56 8B F1 85 F6 74 68");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xdc) = find_pattern("client.dll", "E8 ?? ?? ?? ?? 83 C4 08 84 C0 75 10");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xe4) = find_pattern("engine.dll", "A1 ?? ?? ?? ?? B9 ?? ?? ?? ?? 56 FF 50 ?? 8B 34 85");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xec) = find_pattern("client.dll", "53 8B DC 83 EC 08 83 E4 F8 83 C4 04 55 8B 6B 04 89 6C 24 04 8B EC 81 EC D0 05 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xf4) = find_pattern("client.dll", "55 8B EC 81 EC 00 01 00 00 56 8B F1 83 3C B5");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0xfc) = find_pattern("client.dll", "B9 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B 5D 08 85 C0");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x104) = find_pattern("client.dll", "55 8B EC 8B 45 10 53 56 8B F1 57");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x10c) = find_pattern("client.dll", "56 8B F1 57 8B BE 5C 34 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x114) = find_pattern("client.dll", "55 8B EC 83 EC 18 57 8B F9 89 7D F4");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x11c) = find_pattern("steamnetworkingsockets.dll", "B8 ?? ?? ?? ?? B9 ?? ?? ?? ?? 0F 43 05");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x124) = find_pattern("client.dll", "A1 ?? ?? ?? ?? 56 8B F1 B9 ?? ?? ?? ?? FF 50 ?? A1");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x12c) = find_pattern("engine.dll", "55 8B EC 83 EC 08 56 8B F1 8B 4D 04");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x134) = find_pattern("client.dll", "55 8B EC 51 53 56 57 8B D9 C6 45 FF 01");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x13c) = find_pattern("client.dll", "55 8B EC 83 E4 F8 83 EC 28 8B 4D 08 56 57 E8 ?? ?? ?? ?? 8B F8 8D 4C 24 0C");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x144) = find_pattern("client.dll", "55 8B EC 8B 45 18 81 EC 30 03 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x14c) = find_pattern("client.dll", "A1 ?? ?? ?? ?? 8B 0D ?? ?? ?? ?? 6A 00 68 ?? ?? ?? ?? C6 80 A0 0C 00 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x154) = find_pattern("client.dll", "E8 ?? ?? ?? ?? 83 C4 0C 8D 4D F8");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x15c) = find_pattern("shaderapidx9.dll", "A1 ?? ?? ?? ?? 50 8B 08 FF 51 ?? 85 C0");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x164) = find_pattern("client.dll", "55 8B EC 83 E4 F8 51 53 56 57 8B F1 E8 ?? ?? ?? ?? 8B 7D 08");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x16c) = find_pattern("engine.dll", "55 8B EC 81 EC 34 01 00 00 56");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x174) = find_pattern("client.dll", "83 F8 05 75 0D");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x17c) = find_pattern("client.dll", "FF D0 A1 ?? ?? ?? ?? B9");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x184) = find_pattern("client.dll", "55 8B EC 83 E4 F8 83 EC 78 56 89 4C 24 14");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x18c) = find_pattern("client.dll", "89 35 ?? ?? ?? ?? F3 0F 10 48 20");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x194) = find_pattern("client.dll", "55 8B EC 51 33 C0 C7 45 FC FF FF FF FF 56 8B F1 81 26 00 00 00 FF C6 46 03 00 89 46 10 89 46 14 88 46 18 89 46 20 89 46 1C 89 46 24 89 46 04 89 46 08 89 46 0C FF 15 ?? ?? ?? ?? 6A 01 FF 75 08 8D 4D FC 8B 10 51 8B C8 FF 52 ?? 8B 0E 33 4D FC 81 E1 FF FF FF 00 31 0E 8B CE 6A 01 FF 75 0C 88 46 03 C1 F8 08 66 89 46 12 E8 ?? ?? ?? ?? 85 C0 74 0A FF 75 10 8B C8 E8 ?? ?? ?? ?? 8B C6");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x19c) = find_pattern("client.dll", "53 8B D9 83 C8 FF");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1a4) = find_pattern("client.dll", "8B 01 FF 90 ?? ?? ?? ?? 8B 80 C8 00 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1ac) = find_pattern("client.dll", "55 8B EC 83 E4 F8 8B 4D 08 BA ?? ?? ?? ?? E8 ?? ?? ?? ?? 85 C0 75 12");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1b4) = find_pattern("client.dll", "53 56 66 8B 35 ?? ?? ?? ?? BB FF FF 00 00 57 90 66 3B F3 74 24 A1 ?? ?? ?? ?? 0F B7 CE 8B 3C C8 66 8B 74 C8 06 8B 47 08 8D 4F 08 8B 40 24 FF D0 84 C0 74 09 66 3B F3 75 DC 5F 5E 5B C3 85 FF 74 F8 8B CF");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1bc) = find_pattern("client.dll", "0F 11 05 ?? ?? ?? ?? 83 C8 01");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1c4) = find_pattern("client.dll", "0F 10 05 ?? ?? ?? ?? 8D 85 78 FE FF FF");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1cc) = find_pattern("client.dll", "84 C0 75 38 8B 0D ?? ?? ?? ?? 8B 01 8B 80 48 01 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1d4) = find_pattern("client.dll", "55 8B EC 83 E4 F8 83 EC 34 53 8B 5D 0C 89 4C 24 04");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1dc) = find_pattern("engine.dll", "8B 0D ?? ?? ?? ?? 56 83 B9 88 03 00 00 01");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1e4) = find_pattern("engine.dll", "55 8B EC 81 EC 58 0B 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1ec) = find_pattern("client.dll", "F3 0F 10 86 5C 04 01 00 0F 2F 40 10 76 30");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1f4) = find_pattern("client.dll", "8B 35 ?? ?? ?? ?? FF 10 0F B7 C0 B9 ?? ?? ?? ?? 50 FF 56 ?? 85 C0");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x1fc) = find_pattern("client.dll", "55 8B EC 8B 4D 04 56 E8 ?? ?? ?? ?? 8B 75 08");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x204) = find_pattern("client.dll", "A3 ?? ?? ?? ?? 57 8B CB");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x20c) = find_pattern("client.dll", "84 C0 0F 85 ?? ?? ?? ?? 8B CB E8 ?? ?? ?? ?? 84 C0 0F 85 ?? ?? ?? ?? 83 BF 70 0F 01 00 02");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x214) = find_pattern("client.dll", "A1 ?? ?? ?? ?? 0F 94 C1 85 C0");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x21c) = find_pattern("client.dll", "55 8B EC 83 E4 F8 B8 3C 10 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x224) = find_pattern("client.dll", "8B 0D ?? ?? ?? ?? 83 FF FF 74 07 8B 0C BD ?? ?? ?? ?? 3B F1");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x22c) = find_pattern("client.dll", "8B 0D ?? ?? ?? ?? 8B 45 FC 51 8B D4");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x234) = find_pattern("client.dll", "0F 11 05 ?? ?? ?? ?? 83 C8 01");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x23c) = find_pattern("client.dll", "8D 8E 98 32 00 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x244) = find_pattern("engine.dll", "55 8B EC 83 E4 F0 B8 38 01 10 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x24c) = find_pattern("client.dll", "83 F8 05 75 17");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x254) = find_pattern("client.dll", "55 8B EC 8B 55 04 56 8B F1 57 8D 8E 6C 04 01 00");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x25c) = find_pattern("engine.dll", "53 56 57 8B DA 8B F9 FF 15");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x264) = find_pattern("client.dll", "55 8B EC 51 56 8B F1 8D 45 FC 57");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x26c) = find_pattern("client.dll", "55 8B EC 53 8B 5D 08 56 8B F1 83 FB FF");
	*reinterpret_cast<uint32_t*>(runtime_table_data + 0x274) = find_pattern("client.dll", "55 8B EC 83 EC 14 53 56 57 FF 75 18");

	// table 2
	for (int i = 0; i < sizeof(runtime_table_2_data); i += 8)
	{
		uint32_t address = *reinterpret_cast<uint32_t*>(runtime_table_2_data + i + 0x4);

		if (auto search = g_interfaces.find(address); search != g_interfaces.end())
		{

			if (search->second.find(">") != std::string::npos)
			{
				std::string dll_name = search->second.substr(0, search->second.find(">"));
				std::string name = search->second.substr(search->second.find(">") + 1, search->second.length() - search->second.find(">"));

				const auto address = GetProcAddress(LoadLibraryA(dll_name.data()), name.data());
				if (!address)
				{
					std::cout << "Failed to find " << dll_name << "->" << name << std::endl;
					system("pause");
				}
				*reinterpret_cast<uint32_t*>(runtime_table_2_data + i + 0x4) = reinterpret_cast<uint32_t>(address);
			}
			else
			{
				std::string dll_name = search->second.substr(0, search->second.find("."));
				std::string name = search->second.substr(search->second.find(".") + 1, search->second.length() - search->second.find("."));
				void* address = get_interface(LoadLibraryA(dll_name.data()), name.data());
				if (!address)
				{
					std::cout << "Failed to find " << dll_name << "->" << name << std::endl;
					system("pause");
				}
				*reinterpret_cast<uint32_t*>(runtime_table_2_data + i + 0x4) = reinterpret_cast<uint32_t>(address);
			}
		}
		else
			std::cout << "Not found address: " << std::hex << address << std::dec << std::endl;
	}

	std::cout << "Fixed runtime tables" << std::endl;

	memcpy(hack_address, hack_bin, sizeof(hack_bin));
	memcpy(user_struct, user_struct_1, sizeof(user_struct_1));
	memcpy(reinterpret_cast<void*>(reinterpret_cast<uint32_t>(user_struct) + 0x38), user_struct_2, sizeof(user_struct_2));
	memcpy(runtime_table, runtime_table_data, sizeof(runtime_table_data));
	memcpy(runtime_table_2, runtime_table_2_data, sizeof(runtime_table_2_data));

	std::array<uint8_t, 6> lifetime_sub_patch = { 0xE9, 0xED, 0x02, 0x00, 0x00, 0x90 };

	memcpy(reinterpret_cast<void*>(0x30A654D1), lifetime_sub_patch.data(), lifetime_sub_patch.size());

	std::cout << "Fixing imports" << std::endl;
	fix_imports();
	std::cout << "Fixed imports" << std::endl;

	std::cout << "Calling DLLMain" << std::endl;

	CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(call_dllmain), 0, 0, 0);

	std::cout << "Called DLLMain" << std::endl;
	std::cout << "Owned by PinkKing#8199 ( https://discord.gg/GHKuYjZrdM ) <3" << std::endl;
}

bool __stdcall DllMain(HANDLE hinstDLL, uint32_t fdwReason, void* lpReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		AllocConsole();
		SetConsoleTitleA("millionware.vip crack");
		freopen("CONOUT$", "w", stdout);
		CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(main), 0, 0, 0);
	}
	return true;
}