# RSGL 3DS
This is the official port of RSGL for the 3DS, done by EimaMei
RSGL Discord server for support: https://discord.gg/ckC7mqdjCb
# Notes
1. The library port is not finished yet, and the port will get constant updates to keep up with the main RSGL repository.<br />
2. This isn't a replacement of devkitpro's libraries, this is just used to port RSGL programs to 3DS or begin developing with RSGL for 3DS first since it's a bit easier to learn and use.<br />
3. Do not except to copy-paste code from RSGL's projects and except it to work. Compiling programs for computers and consoles will never be the same (especially for the 3ds), so if you're thinking of porting your applications from PC to 3DS via RSGL, you'll need to modify some stuff to work normally.
# Requirements for the development
1. A hacked 3DS (can be old or new)<br />
2. Homebrew<br />
3. DevkitPro with 3DS Development enabled<br />
# Guide on downloading the library
1. Download this repository<br />
2. Follow the makefile's instructions by using `make` in the terminal (you must have the terminal running inside the RSGL3DS folder)<br />
3. That's basically it. The `3DS` file is where your source file is. To compile the code, you need to `cd <the/path/to/3DS>` in the terminal and then type `make`.
# Plans
1. Add the main-library features<br />
2. Make a documentation and/or wiki for the port<br />
3. Create exclusive 3DS features (like 3D Mode)<br />
