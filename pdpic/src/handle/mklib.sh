#!/bin/ksh

gcc -g -c -fPIC -I . libstr.c
gcc -g -shared -o libstr.so libstr.o
