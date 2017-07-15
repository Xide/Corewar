#!/bin/sh

function process {
    if [ -f $1 ]; then
	uncrustify -c .uncrustify.cfg --replace --no-backup $1
    fi
}

for file in */{sources,includes}/*.{cpp,hpp,h};
do
    if grep -q '*' <<< $file; then continue; fi
    process $file
done
