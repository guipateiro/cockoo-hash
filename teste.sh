#!/bin/bash
make
for i in 1 2 3 4
do
    ./myht < teste$i.in > temp.out
    diff teste$i.out temp.out -c
done