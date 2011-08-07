#! /bin/sh
export CPPUTEST_USE_MEM_LEAK_DETECTION=N
git submodule update --init
make -C CppUTest
make clean -C cslim
make -C cslim
make -C treadmill
make at -C treadmill
make cheat -C treadmill
