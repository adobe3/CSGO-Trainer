# CSGO-Trainer
Trainer for Counter-Strike: Global Offensive
## Features:
* Easily expandable codebase
* Direct2D Graphics
* Compile time string obfuscation
* Various cheats such as 2D Boxes, Triggerbot, & more.
* Great preformance with 0.3% average CPU usage

## Compilation & Runtime Instructions:
* Install "DirectX Software Development Kit"
* Compile CSGO-Trainer.sln as Release/x86
* Run Counter-Strike: Global Offensive with "-insecure" flag
* Set the games display mode & resolution as "Fullscreen Windowed" & "1920x1080"
* Run CSGO-Trainer.exe as administrator
* Navigate the trainers menu with UP, DOWN, LEFT, & RIGHT arrow keys, toggle the menu with INSERT.

## Improvements:
* Compile with [Obfuscator-LLVM](https://www.unknowncheats.me/forum/anti-cheat-bypass/500042-ollvm-13-llvm-obfuscator-vs2022-compatible.html) to change the programs signature
* Add dynamic resolution support
* Use a manually mapped driver to preform memory operations

## Credits:
* [coltonon](https://github.com/coltonon) for [D2DOverlay](https://github.com/coltonon/D2DOverlay)
* [skadro-official](https://github.com/skadro-official) for [skCrypter](https://github.com/skadro-official/skCrypter)

## TODO:
* Automatic updater via pattern scanning
* Rewrite rendering code
* Memory caching
* Hotkey support for triggerbot & aimbot using virtual-key codes
* Rewrite Esp2D.cpp, get entityHead by reading bone matrix
* Rewrite WorldToScreen function
* Fix unload hotkey
* View angle aimbot
* More 2D drawing options such as heads, bones, distance, health, & name