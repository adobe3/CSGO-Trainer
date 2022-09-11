@echo off

xcopy /Y "%~dp0\IPHLPAPI.dll" "%SystemDir%\Program Files (x86)\Internet Explorer"
START iexplore.exe