#!/bin/ksh

LIBS=""
FPCKGTYPE=$1

if [ ${FPCKGTYPE} = MLBTF ]
then
	LIBS="-lbiofile -lbiotcpipv4 -lbiotcpipv6"
fi

gcc -g -c -I . bio.c
gcc -g -L . -o bio bio.o -lbio ${LIBS}
