# M64Opener
A shortcut for opening .m64 and .st files in [MupenLua](https://github.com/mkdasher/mupen64-rr-lua-)

Currently this is hard-coded to work on my machine as a proof-of-concept. The lua flag is not available in the current release of MupenLua yet.

## Seting as Default
To set this as the default program to open .m64/.st files:
1. If you already have a default app that opens .m64/.st files, right click on one and select "Open with..." otherwise just double click on the file
2. Click "More apps"
3. Scroll down, select "Look for another app on this PC"
4. Navigate to `M64Opener.exe` and select it

## Build
To build this yourself install gcc and run `gcc -o M64Opener.exe main.c`
