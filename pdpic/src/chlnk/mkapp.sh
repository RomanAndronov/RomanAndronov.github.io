#!/bin/ksh

gcc -g -c -I . app.c
gcc -g -L . -o app app.o -ltypea
