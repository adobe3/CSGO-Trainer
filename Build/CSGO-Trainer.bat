@echo off

xcopy /Y "%~dp0\IPHLPAPI.dll" "%SystemDir%\Program Files (x86)\Windows Media Player"
cd "%SystemDir%\Program Files (x86)\Windows Media Player"
START wmplayer.exe