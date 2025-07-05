set PATH=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.43.34808\bin\HostX86\x86;C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE;C:\Program Files (x86)\Windows Kits\10\bin;C:\D\dmd2\windows\bin;%PATH%
set DMD_LIB=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.43.34808\lib\x64;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\ucrt\x64;C:\Program Files (x86)\Windows Kits\10\lib\10.0.22621.0\um\x64
set VCINSTALLDIR=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\
set VCTOOLSINSTALLDIR=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.43.34808\
set VSINSTALLDIR=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\
set WindowsSdkDir=C:\Program Files (x86)\Windows Kits\10\
set WindowsSdkVersion=10.0.22621.0
set UniversalCRTSdkDir=C:\Program Files (x86)\Windows Kits\10\
set UCRTVersion=10.0.22621.0
"C:\Program Files (x86)\VisualD\pipedmd.exe" -deps x64\Debug\SimpleTodoListDlang.dep dmd -debug -m64 -g -gf -X -Xf"x64\Debug\SimpleTodoListDlang.json" -c -of"x64\Debug\SimpleTodoListDlang.obj" ListManager.d SimpleTodoListDlang.d TodoListManager.d
if %errorlevel% neq 0 goto reportError

set LIB=C:\D\dmd2\windows\bin\..\lib64
echo. > D:\3ClionPorject\SimpleProjectOfClang\SimpleTodoListDlang\SimpleTodoListDlang\x64\Debug\SimpleTodoListDlang.link.rsp
echo "x64\Debug\SimpleTodoListDlang.obj" /OUT:"x64\Debug\SimpleTodoListDlang.exe" user32.lib  >> D:\3ClionPorject\SimpleProjectOfClang\SimpleTodoListDlang\SimpleTodoListDlang\x64\Debug\SimpleTodoListDlang.link.rsp
echo kernel32.lib  >> D:\3ClionPorject\SimpleProjectOfClang\SimpleTodoListDlang\SimpleTodoListDlang\x64\Debug\SimpleTodoListDlang.link.rsp
echo legacy_stdio_definitions.lib /LIBPATH:"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.43.34808\lib\x64" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\ucrt\x64" /LIBPATH:"C:\Program Files (x86)\Windows Kits\10\lib\10.0.22621.0\um\x64" /DEBUG /PDB:"x64\Debug\SimpleTodoListDlang.pdb" /INCREMENTAL:NO /NOLOGO /NODEFAULTLIB:libcmt libcmtd.lib /SUBSYSTEM:CONSOLE >> D:\3ClionPorject\SimpleProjectOfClang\SimpleTodoListDlang\SimpleTodoListDlang\x64\Debug\SimpleTodoListDlang.link.rsp
"C:\Program Files (x86)\VisualD\mb2utf16.exe" D:\3ClionPorject\SimpleProjectOfClang\SimpleTodoListDlang\SimpleTodoListDlang\x64\Debug\SimpleTodoListDlang.link.rsp

"C:\Program Files (x86)\VisualD\pipedmd.exe" -msmode -deps x64\Debug\SimpleTodoListDlang.lnkdep "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.43.34808\bin\HostX86\x86\link.exe" @D:\3ClionPorject\SimpleProjectOfClang\SimpleTodoListDlang\SimpleTodoListDlang\x64\Debug\SimpleTodoListDlang.link.rsp
if %errorlevel% neq 0 goto reportError
if not exist "x64\Debug\SimpleTodoListDlang.exe" (echo "x64\Debug\SimpleTodoListDlang.exe" not created! && goto reportError)

goto noError

:reportError
set ERR=%ERRORLEVEL%
set DISPERR=%ERR%
if %ERR% LSS -65535 set DISPERR=0x%=EXITCODE%
echo Building x64\Debug\SimpleTodoListDlang.exe failed (error code %DISPERR%)!
exit /B %ERR%

:noError
