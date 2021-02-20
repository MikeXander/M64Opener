#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool endswith(const char *str, const char *ending) {
	return !strcmp(&str[strlen(str) - strlen(ending)], &ending[0]);
}

bool isSavestate(const char *fname) {
	return endswith(fname, ".st");
}

bool isM64(const char *fname) {
	return endswith(fname, ".m64");
}

bool validfile(const char *fname) {
	return isSavestate(fname) || isM64(fname);
}

int main(int argc, char **argv) {
	if (argc < 2 || !validfile) {
		printf("Error incorrect usage: M64Opener.exe tas.m64");
		return 1;
	}
	const char *file = argv[1];
	
	const char *EMU_PATH = "D:\\Programming\\Github\\MupenLua\\mupen64-rr-lua-\\bin\\mupen64_debug.exe ";
	//"D:\\_Games\\_Mupen64\\New_Mupen_Lua_Release_1.0.4\\mupen64.exe ";
	const char *VIDEO = "-v \"glN64_v0.4.1.dll\" ";
	const char *AUDIO = "-a \"a_Jabo_Dsound.dll\" ";
	const char *RSP = "-rsp \"a_RSP.dll\" ";
	const char *CONTROLLER = "-c \"TASDI.dll\" ";
	const char *ROM = "-g \"D:\\_Games\\_Mupen64\\ROMs\\Super Mario 64 (U) [!].z64\" ";
	const char *LUA = "-lua \"D:\\_Games\\_Mupen64\\Lua\\InputDirection_3.3\\InputDirection.lua\" ";
	
	char cmd[1024] = {0};
	int pos = 0;
	
	strcpy(&cmd[pos], EMU_PATH);
	pos += strlen(EMU_PATH);
	
	strcpy(&cmd[pos], VIDEO);
	pos += strlen(VIDEO);
	
	strcpy(&cmd[pos], AUDIO);
	pos += strlen(AUDIO);
	
	strcpy(&cmd[pos], RSP);
	pos += strlen(RSP);
	
	strcpy(&cmd[pos], CONTROLLER);
	pos += strlen(CONTROLLER);
	
	strcpy(&cmd[pos], ROM);
	pos += strlen(ROM);
	
	strcpy(&cmd[pos], LUA);
	pos += strlen(LUA);
	
	if (isSavestate(file)) {
		strcpy(&cmd[pos], "-st ");
		pos += strlen("-st ");
		
	} else { // isM64
		strcpy(&cmd[pos], "-m64 ");
		pos += strlen("-m64 ");
	}
	
	strcpy(&cmd[pos], file);
	//printf(cmd);
	system(cmd);
}
