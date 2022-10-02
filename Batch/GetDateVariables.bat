@echo off
:: /**
::  * mersonfufu@gmail.com
::  * ultima update em 16:04 23/05/2022
::  * versao 4
::  */

:: CALCULAR-DATA
:: DEFINE DATAH
setlocal ENABLEDELAYEDEXPANSION
for /f "skip=1 tokens=1-6" %%a in ('wmic path Win32_LocalTime Get Day^,Hour^,Minute^,Month^,Second^,Year /Format:table') do (
	if not "%%~f"=="" (
		:: FormattedDate
		set /A FormattedDate=10000 * %%f + 100 * %%d + %%a
		set FormattedDate=!FormattedDate:~0,4!-!FormattedDate:~4,2!-!FormattedDate:~6,2!
	)
)
endlocal & set DataH=%FormattedDate%
set AnoH=%DataH:~0,4%
set MesH=%DataH:~5,2%
:: if %MesH:~0,1% EQU 0 set MesH=%MesH:~1,1%
set DiaH=%DataH:~8,2%
:: if %DiaH:~0,1% EQU 0 set DiaH=%DiaH:~1,1%

echo Today is %AnoH%-%MesH%-%DiaH%
pause

:FIM