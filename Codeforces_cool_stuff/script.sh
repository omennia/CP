#!/bin/bash
g++ -std=c++14 -Wall -o next next.cpp

if (( $# < 1 ));  then 
    for i in ./*[0-9];
    do
            echo =========================
            echo $i
            echo =========================

            ./next < $i
            echo -------------------------
            echo
        done
    else
        ./next < $1
fi