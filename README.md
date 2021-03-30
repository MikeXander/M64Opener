# M64Opener
A shortcut for opening .m64 and .st files in [MupenLua](https://github.com/mkdasher/mupen64-rr-lua-) on Windows. This makes use of the `-m64` command line argument requires Mupen version 1.0.6 or greater, and for `-st` or `-lua` you need version 1.0.7 or greater.

The first line of `config.txt` is the emulator path. The following lines are the commandline arguments that get passed to the emulator.

## Seting as Default
To set this as the default program to open .m64/.st files:
1. Either right click on a .m64/.st file and select "Open with..." or simply double click on the file
2. Click "More apps"
3. Scroll down, select "Look for another app on this PC"
4. Navigate to `M64Opener.exe` and select it
5. Select "Always use this app to open .m64/.st files" and press OK

## Build
To build this yourself install gcc and run `gcc -o M64Opener.exe main.cpp`

## Future Development
- read from `mupen64.cfg` instead of `config.txt`
- open appropriate ROM by searching for CRC in recent ROMs
- better error handling (buffer overflow)
