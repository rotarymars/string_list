#!/usr/bin/bash

for directory in */; do
  echo Processing $directory
  cd $directory
  g++ -O3 main.cpp
  ./a.out
  cd ..
done