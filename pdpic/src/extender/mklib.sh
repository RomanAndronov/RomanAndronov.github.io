#!/bin/ksh

MDMLRTF=""
FPCKGTP=$1

if [ ${FPCKGTP} = MLRTF ]
then
	MDMLRTF="-DGSE_MLRTF"
fi

gcc -D_GNU_SOURCE ${MDMLRTF} -g -c -fPIC -I . libshape.c

gcc -g -c -fPIC -I . libshapeoval.c
gcc -g -c -fPIC -I . libshapeellipse.c
gcc -g -c -fPIC -I . libshapecircle.c

if [ ${FPCKGTP} = SLBTF ]
then
	gcc -g -shared -o libshape.so \
		libshape.o \
		libshapeoval.o \
		libshapeellipse.o \
		libshapecircle.o -ldl
else
	gcc -g -shared -o libshape.so libshape.o -ldl
	gcc -g -shared -o libshapeoval.so libshapeoval.o
	gcc -g -shared -o libshapeellipse.so libshapeellipse.o
	gcc -g -shared -o libshapecircle.so libshapecircle.o
fi
