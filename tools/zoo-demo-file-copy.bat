@echo off
set source_path=D:\Code\_svn\zoo-demo
set target_path=D:\Code\_git\zoo-demo
echo copy[%source_path%]to[%target_path%]:
pause

echo ----------------------------------------plugins catalog
xcopy /y /s /e %source_path%\plugins\*.* %target_path%\plugins\

echo ----------------------------------------tools catalog
xcopy /y /s /e %source_path%\tools\*.* %target_path%\tools\

echo ----------------------------------------CMakeModules catalog
xcopy /y /s /e %source_path%\CMakeModules\*.* %target_path%\CMakeModules\

copy %source_path%\CMakeLists.txt %target_path%\CMakeLists.txt

pause
