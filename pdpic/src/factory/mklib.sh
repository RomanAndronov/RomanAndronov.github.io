#!/bin/ksh

MDMLRTF=""
FPCKGTP=$1

if [ ${FPCKGTP} = MLRTF ]
then
	MDMLRTF="-DIO_MLRTF"
fi

gcc -D_GNU_SOURCE ${MDMLRTF} -g -c -fPIC -I . libbio.c

gcc -g -c -fPIC -I . libbiofile.c
gcc -g -c -fPIC -I . libbiotcpipv4.c
gcc -g -c -fPIC -I . libbiotcpipv6.c

if [ ${FPCKGTP} = SLBTF ]
then
	gcc -g -shared -o libbio.so libbio.o libbiofile.o libbiotcpipv4.o libbiotcpipv6.o -ldl
else
	gcc -g -shared -o libbio.so libbio.o -ldl
	gcc -g -shared -o libbiofile.so libbiofile.o
	gcc -g -shared -o libbiotcpipv4.so libbiotcpipv4.o
	gcc -g -shared -o libbiotcpipv6.so libbiotcpipv6.o
fi
