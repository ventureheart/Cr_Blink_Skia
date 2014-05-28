#!/bin/bash

ls ./gpu > gm_name.txt
while read line 
do
  name=${line%_*}
  gpu=${name}_gpu.png
  new=${name}_8888.png
  mv ./gpu/$gpu ./gpu/$new
  #echo $gpu
  #echo $new
done < gm_name.txt
