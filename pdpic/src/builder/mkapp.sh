#!/bin/ksh

LIBS=""
BPCKGTYPE=$1

if [ ${BPCKGTYPE} = MLBTB ]
then
	LIBS="-ldocbldrplain -ldocbldrhtml"
fi

gcc -g -c -I . docbldr.c
gcc -g -L . -o docbldr docbldr.o -ldoc -ldocbldr ${LIBS}
