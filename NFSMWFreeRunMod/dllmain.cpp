#include "pch.h"
#include <Windows.h>
#include "injector.hpp"



DWORD WINAPI MainThread() {
	// Opponent modifier code. (C) 2021 ExOpts Team. No rights reserved. Licensed under GNU GPL. Hardcoded values used instead of values set by NFSMW Extra Options Configuration.
	injector::WriteMemory<unsigned char>(0x7abff9, 0, true);
	injector::WriteMemory<unsigned char>(0x7abffd, 3 + 0x01, true);
	injector::WriteMemory<unsigned char>(0x7ac01a, 0, true);
	injector::WriteMemory<unsigned char>(0x7ac00e, 3 + 0x01, true);
	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		MainThread();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
