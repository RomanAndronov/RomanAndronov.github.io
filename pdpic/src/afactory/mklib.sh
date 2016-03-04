#!/bin/ksh

CARMLRTAF=""
FPCKGTP=$1

if [ ${FPCKGTP} = MLRTAF ]
then
	CARMLRTAF="-DCAR_MLRTAF"
fi

gcc -D_GNU_SOURCE ${CARMLRTAF} -g -c -fPIC -I . libcaf.c

gcc -g -c -fPIC -I . libcafred.c
gcc -g -c -fPIC -I . libcafgreen.c
gcc -g -c -fPIC -I . libcafblue.c
gcc -g -c -fPIC -I . libframe.c
gcc -g -c -fPIC -I . libframered.c
gcc -g -c -fPIC -I . libframegreen.c
gcc -g -c -fPIC -I . libframeblue.c

if [ ${FPCKGTP} = SLBTAF ]
then
	gcc -g -shared -o libcaf.so libcaf.o \
		libcafred.o \
		libcafgreen.o \
		libcafblue.o \
		libframe.o \
		libframered.o \
		libframegreen.o \
		libframeblue.o -ldl
else
	gcc -g -shared -o libcaf.so \
		libcaf.o \
		libframe.o -ldl
	gcc -g -shared -o libcafred.so \
		libcafred.o \
		libframered.o
	gcc -g -shared -o libcafgreen.so \
		libcafgreen.o \
		libframegreen.o
	gcc -g -shared -o libcafblue.so \
		libcafblue.o \
		libframeblue.o
fi
