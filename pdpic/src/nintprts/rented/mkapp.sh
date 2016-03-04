#!/bin/ksh

gcc -g -c -I . book.c
gcc -g -L . -o book book.o -lbook -lstr
