
Debian
====================
This directory contains files used to package gpuniond/gpunion-qt
for Debian-based Linux systems. If you compile gpuniond/gpunion-qt yourself, there are some useful files here.

## gpunion: URI support ##


gpunion-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install gpunion-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your gpunion-qt binary to `/usr/bin`
and the `../../share/pixmaps/gpunion128.png` to `/usr/share/pixmaps`

gpunion-qt.protocol (KDE)

