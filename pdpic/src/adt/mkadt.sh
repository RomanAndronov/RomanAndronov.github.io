#!/bin/ksh

TP="$1"
cat libadt.h | sed "s/TYPE/"${TP}"/g" > lib${TP}.h
cat libadt.c | sed "s/TYPE/"${TP}"/g" > lib${TP}.c
