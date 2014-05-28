#!/bin/bash

cat $1 | while read line
do
  scanf("%s", $line) 
  echo $line
done
