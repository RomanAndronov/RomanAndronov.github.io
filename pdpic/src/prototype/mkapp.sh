#!/bin/ksh

gcc -g -c -I . str.c
gcc -g -L . -o str str.o -lstr
