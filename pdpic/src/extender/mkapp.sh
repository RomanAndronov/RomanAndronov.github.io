#!/bin/ksh

LIBS=""
FPCKGTYPE=$1

if [ ${FPCKGTYPE} = MLBTF ]
then
	LIBS="-lshapeoval -lshapeellipse -lshapecircle"
fi

gcc -g -c -I . shape.c
gcc -g -L . -o shape shape.o -lshape ${LIBS}
