#!/bin/ksh

LIBS=""
FPCKGTYPE=$1

if [ ${FPCKGTYPE} = MLBTF ]
then
	LIBS="-lrprtl -lrprtc -lrprtnwd"
fi

gcc -g -c -I . rprt.c
gcc -g -L . -o rprt rprt.o -lrprt ${LIBS} -lbio
