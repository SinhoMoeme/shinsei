@echo off
setlocal

for /f "usebackq delims=" %%A in ("msys2_path.txt") do (
    set "MSYS2=%%A"
    goto :done
)

:done

if not defined MSYS2 (
    echo Failed to read msys2_path.txt
    pause
    exit /b 1
)

set "CURDIR=%CD%"
set "CYGPATH=%MSYS2%\usr\bin\cygpath.exe"

for /f "usebackq delims=" %%P in (`""%CYGPATH%" -u "%CURDIR%""`) do (
    set "MSYSDIR=%%P"
)

"%MSYS2%\usr\bin\bash.exe" -l -c ^
"export MSYSTEM=UCRT64; source /etc/profile; cd \"$(cygpath -u '%CD%')\"; ./build_mingw.sh"
