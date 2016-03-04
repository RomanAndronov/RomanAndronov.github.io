#!/bin/ksh

MDMLRTB=""
BPCKGTP=$1

gcc -g -c -fPIC -I . libdoc.c
gcc -g -shared -o libdoc.so libdoc.o

if [ ${BPCKGTP} = MLRTB ]
then
	MDMLRTF="-DDOC_MLRTB"
fi

gcc -D_GNU_SOURCE ${MDMLRTB} -g -c -fPIC -I . libdocbldr.c

gcc -g -c -fPIC -I . libdocbldrplain.c
gcc -g -c -fPIC -I . libdocbldrhtml.c

if [ ${BPCKGTP} = SLBTB ]
then
	gcc -g -shared -o libdocbldr.so libdocbldr.o libdocbldrplain.o libdocbldrhtml.o -ldl
else
	gcc -g -shared -o libdocbldr.so libdocbldr.o -ldl
	gcc -g -shared -o libdocbldrplain.so libdocbldrplain.o
	gcc -g -shared -o libdocbldrhtml.so libdocbldrhtml.o
fi
