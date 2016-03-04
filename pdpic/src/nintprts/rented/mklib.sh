#!/bin/ksh

gcc -g -c -fPIC -I . libbook.c
gcc -g -shared -o libbook.so libbook.o
