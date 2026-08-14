@echo off
setlocal EnableExtensions EnableDelayedExpansion

rem ===============================
rem   Build & Run Q2 Project
rem   (Windows - configurable)
rem ===============================

rem ---- Config (override-able before calling this script) ----
if not defined OUT_DIR    set "OUT_DIR=output"
if not defined OUT_BIN    set "OUT_BIN=Q2.exe"
if not defined OBJ_DIR    set "OBJ_DIR=%OUT_DIR%\obj"
if not defined SRC_FILES  set "SRC_FILES=main.cpp Car.cpp Node.cpp SinglyLinkedListOOP.cpp"

rem Optional stdin redirection
rem set "INPUT_FILE=TestCases\tc1.txt"

rem Compiler & flags
if not defined CXX (
  where g++ >nul 2>&1 && (set "CXX=g++") || (
    where clang++ >nul 2>&1 && (set "CXX=clang++") || (
      echo Error: Neither g++ nor clang++ found in PATH.
      exit /b 1
    )
  )
)
if not defined CXXFLAGS set "CXXFLAGS=-std=c++17 -O2 -Wall -Wextra -Wshadow"
if not defined LDFLAGS  set "LDFLAGS="

echo == Build config ==
echo CXX      : %CXX%
echo CXXFLAGS : %CXXFLAGS%
echo LDFLAGS  : %LDFLAGS%
echo OUT_DIR  : %OUT_DIR%
echo OUT_BIN  : %OUT_BIN%
echo OBJ_DIR  : %OBJ_DIR%
echo SRC      : %SRC_FILES%
echo.

rem ---- Prepare folders ----
if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"
if not exist "%OBJ_DIR%" mkdir "%OBJ_DIR%"

rem ---- Compile ----
set "OBJS="
for %%F in (%SRC_FILES%) do (
  set "BASE=%%~nF"
  set "OBJ=%OBJ_DIR%\!BASE!.o"
  echo [CXX] %%F ^> !OBJ!
  "%CXX%" %CXXFLAGS% -c "%%F" -o "!OBJ!"
  if errorlevel 1 exit /b 1
  set "OBJS=!OBJS! "!OBJ!""
)

rem ---- Link ----
set "TARGET=%OUT_DIR%\%OUT_BIN%"
echo [LD ] %TARGET%
for %%Z in (%OBJS%) do rem (just expanding)
"%CXX%" %CXXFLAGS% -o "%TARGET%" %OBJS% %LDFLAGS%
if errorlevel 1 exit /b 1
echo Built: %TARGET%
echo.

rem ---- Run ----
if defined INPUT_FILE (
  if exist "%INPUT_FILE%" (
    echo == Running with input: %INPUT_FILE% ==
    "%TARGET%" < "%INPUT_FILE%"
  ) else (
    echo Warning: INPUT_FILE "%INPUT_FILE%" not found. Running without redirection.
    "%TARGET%"
  )
) else (
  echo == Running ==
  "%TARGET%"
)

exit /b 0
