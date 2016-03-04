#!/bin/ksh

gcc -g -c -fPIC -I . libtypec.c
gcc -g -shared -o libtypec.so libtypec.o

gcc -g -c -fPIC -I . libtypeb.c
gcc -g -L . -shared -o libtypeb.so libtypeb.o -ltypec

gcc -g -c -fPIC -I . libtypea.c
gcc -g -L . -shared -o libtypea.so libtypea.o -ltypeb

