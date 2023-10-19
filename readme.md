Currently an empty SFML project that renders an empty window.

I'm using CLion on Windows. If you're using a mac you'll need another version of SFML.

To build and run the project correctly on Windows first download [this](https://www.sfml-dev.org/files/SFML-2.6.0-windows-gcc-13.1.0-mingw-64-bit.zip), 
unzip it and put it in the libraries folder in the project directory.

Then download [this](https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-msvcrt-r5/winlibs-x86_64-posix-seh-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z),
unzip it using 7zip, open the file and move the mingw64 file to somewhere on your C drive.

Then in CLion under File>Settings>Toolchains set the Toolset from Bundled MinGW to the version of MinGW you just downloaded and hit apply.