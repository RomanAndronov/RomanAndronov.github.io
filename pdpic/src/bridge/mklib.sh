#!/bin/ksh

MDMLRTF=""
FPCKGTP=$1

if [ ${FPCKGTP} = MLRTF ]
then
	MDMLRTF="-DRPRT_MLRTF"
fi

gcc -D_GNU_SOURCE ${MDMLRTF} -g -c -fPIC -I . librprt.c

gcc -g -c -fPIC -I . librprtl.c
gcc -g -c -fPIC -I . librprtc.c
gcc -g -c -fPIC -I . librprtnwd.c

if [ ${FPCKGTP} = SLBTF ]
then
	gcc -g -shared -o librprt.so librprt.o librprtl.o librprtc.o librprtnwd.o -ldl
else
	gcc -g -shared -o librprt.so librprt.o -ldl
	gcc -g -shared -o librprtl.so librprtl.o
	gcc -g -shared -o librprtc.so librprtc.o
	gcc -g -shared -o librprtnwd.so librprtnwd.o
fi
