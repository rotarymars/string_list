#!/usr/bin/bash

for directory in */; do
  echo Processing $directory
  cd $directory
  if [ ! -f a.out ]; then
    g++ -O3 main.cpp
  fi
  ./a.out
  cd ..
done
