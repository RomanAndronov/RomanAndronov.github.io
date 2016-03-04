#!/bin/ksh

LIBS=""
FPCKGTYPE=$1

if [ ${FPCKGTYPE} = MLBTAF ]
then
	LIBS="-lcafred -lcafgreen -lcafblue"
fi

gcc -g -c -I . caf.c
gcc -g -L . -o caf caf.o -lcaf ${LIBS}
