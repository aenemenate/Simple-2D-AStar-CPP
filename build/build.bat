
@echo off

pushd "%~dp0"
pushd "../"

echo .
echo Compiling example . . .
cl /std:c++17 /EHsc ./example/main.cpp ./src/astar.cpp ./src/grid.cpp ./src/node.cpp
echo Deleting objs . . .
del *.obj
popd
popd