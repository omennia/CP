#!/bin/bash
g++ -std=c++14 -Wall -o next next.cpp

if (( $# < 1 )); then 
    for i in ./*[0-9];
        do
            echo =================
            ./next < $i
            echo =================
            echo
        done
    else
        if (( $# == 2 )); then
            ./next < $1 > $2
            tkdiff $2 esperado
        else
        ./next < $1
        fi
fi