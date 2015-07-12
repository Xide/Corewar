#!/bin/sh

function process {
if [ -f $1 ] ; then
  uncrustify -c uncrustify.cfg --replace --no-backup $1
fi
}

for dir in includes/* sources/*
do
  if [ -d $dir ] ; then
    for file in $dir/*.cpp $dir/*.h*
    do
      process $file
    done
  else
    process $dir
  fi
done
