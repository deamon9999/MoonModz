#include "pch.h"
#include <cstdint>
#include <stdio.h>
#include <stdlib.h>

using LoadSystemFile_call = __int64(*)(__int64 state, const char* scriptName);
uint64_t luaClass = 0x0;


auto grabClass() -> void {
	while (true) {
		Sleep(250);
		uint64_t* c1 = (uint64_t*)(GetModuleHandleA("citizen-scripting-lua") + 0x4FECC8);
		if (*c1 != 0)
			luaClass = *c1;
	}
}

auto doStuff() -> void {
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)grabClass, 0, 0, 0);
	
	LoadSystemFile_call lsfC = (LoadSystemFile_call)(GetModuleHandleA("citizen-scripting-lua") + 0x50D50);

	printf("Press F5 to execute C:/nigger.lua\n");
	while (true) {
		if (GetAsyncKeyState(VK_F5)) {
			lsfC(luaClass, "C:\\nigger.lua");
		}
	}

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if(ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)doStuff, 0, 0, 0);

    return TRUE;
}

