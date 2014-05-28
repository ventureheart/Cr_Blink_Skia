#!/bin/bash

rm ../../data/visualDiff/8888/*
rm ../../data/visualDiff/gpu/*

../out/Release/gm --config 8888 -w ../../data/visualDiff/8888
../out/Release/gm --config gpu -w ../../data/visualDiff/gpu

cat GMcases.txt > gm_name.txt
while read line 
do
  name=${line}*
  rm ../../data/visualDiff/8888/$name
  rm ../../data/visualDiff/gpu/$name
  #echo $name
done < gm_name.txt

cd ../../data/visualDiff
./rename_gpu.sh
cd -
../out/Release/skpdiff -f ../../data/visualDiff/8888 ../../data/visualDiff/gpu --alphaDir ../../data/visualDiff/alphaDir -o ../tools/skpdiff/skpdiff_output.json
