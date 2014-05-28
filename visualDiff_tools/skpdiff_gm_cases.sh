#!/bin/bash

rm ../../data/visualDiff/8888/*
rm ../../data/visualDiff/gpu/*

cat GMcases.txt > gm_name.txt
while read line 
do
  ../out/Release/gm --config 8888 --match ${line} -w ../../data/visualDiff/8888
  ../out/Release/gm --config gpu --match ${line} -w ../../data/visualDiff/gpu
  ../out/Release/gm --config nvprmsaa4 --match ${line} -w ../../data/visualDiff/nvprmsaa4
  #echo $gpu
done < gm_name.txt

cd ../../data/visualDiff
./rename_gpu.sh
cd -
../out/Release/skpdiff -f ../../data/visualDiff/8888 ../../data/visualDiff/nvprmsaa4 --alphaDir ../../data/visualDiff/alphaDir -o ../tools/skpdiff/skpdiff_output.json
