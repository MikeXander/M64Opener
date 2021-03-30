#include <windows.h>
#include <winuser.h>
#include <shellapi.h>
#include <stdlib.h>
#include <string>

bool endswith(const char *str, const char *ending) {
	return !strcmp(&str[strlen(str) - strlen(ending)], &ending[0]);
}

// reads characters until a newline or EOF
// returns the length of the string read in
// does not detect buffer overflow
int readline(char *buffer, FILE *f) {
	int pos = 0;
	char c;
	while (fscanf(f, "%c", &c) == 1) {
		if (c == '\n') break;
		buffer[pos++] = c;
	}
	buffer[pos] = '\0';
	return pos;
}

void error(const char *text) {
	MessageBox(NULL, text, NULL, MB_OK);
	exit(1);
}

int main (int argc, char *argv[]) {
	
	*(strrchr(argv[0], '\\') + 1) = 0; // cutoff directory at the last slash
	char config_path[1024] = {0};
	strcpy(config_path, argv[0]);
	strcat(config_path, "config.txt");
	FILE *config = fopen(config_path, "r");
	if (config == NULL) {
		error("config.txt could not be opened");
	}
	
	char emu_path[1024] = {0};
	if (readline(emu_path, config) == 0) {
		error("no emulator path specified in config.txt");
	}
	
	char mupen_args[1024] = {0};
	int pos = 0;
	while (true) {
		int ret = readline(mupen_args + pos, config);
		if (ret == 0) break;
		pos += ret;
	}
	
	fclose(config);
	
	if (argc > 1) {
		if (endswith(argv[1], ".st")) {
			strcat(mupen_args, "-st \"");
			strcat(mupen_args, argv[1]);
			strcat(mupen_args, "\"");
		} else if (endswith(argv[1], ".m64")) {
			strcat(mupen_args, "-m64 \"");
			strcat(mupen_args, argv[1]);
			strcat(mupen_args, "\"");
		}
	}
	
	int failed = (int)ShellExecute(NULL, "open", emu_path, mupen_args, NULL, SW_SHOW) <= 32;
	if (failed) {
		error("Failed to open Mupen");
	}
	return 0;
}