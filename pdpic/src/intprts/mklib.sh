#!/bin/ksh

gcc -g -c -fPIC -I . libbook.c
gcc -g -L . -shared -o libbook.so libbook.o -lstr
