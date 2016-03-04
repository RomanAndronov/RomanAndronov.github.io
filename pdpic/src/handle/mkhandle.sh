#!/bin/ksh

TP="$1"
cat libhandle.h | sed "s/TYPE/"${TP}"/g" > lib${TP}.h
cat libhandle.c | sed "s/TYPE/"${TP}"/g" > lib${TP}.c
