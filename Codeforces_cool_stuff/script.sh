#!/bin/bash
g++ -std=c++14 -Wall -o next next.cpp
if [[ "$1" == "debug" ]];
    then
    g++ -std=c++17 -O2 -Wall -Wextra -Wno-unused-result -Wno-char-subscripts -Wshadow -Wfloat-equal -Wconversion -Wformat-signedness -Wvla -Wduplicated-cond -Wlogical-op -Wredundant-decls -ggdb3 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined,address,float-divide-by-zero,float-cast-overflow -fno-omit-frame-pointer -fno-optimize-sibling-calls -fstack-protector-all -fno-sanitize-recover=all -o next next.cpp 
fi


if (( $# < 1 )); then 
    for i in ./*[0-9];
        do
            cnt=$(wc -w $i | cut -d " " -f 1)
            if (( $cnt > 0 )); then
                echo =================
                ./next < $i
                echo =================
                echo
            fi
        done
else
        if [[ "$1" == "-c" ]]; then
            for i in ./*[0-9]
                do
                > $i
                done
        elif (( $# == 2 )); then
            ./next < $1 > $2
            tkdiff $2 esperado
        elif [[ "$1" != "debug" ]]; then
            ./next < $1
        else
            # case for debug
            for i in ./*[0-9];
                do
                    echo $i
                    cnt=$(wc -w $i | cut -d " " -f 1)
                    if (( $cnt > 0 )); then
                        echo =================
                        ./next < $i
                        echo =================
                        echo
                    fi
                done
        fi
fi