#!/bin/bash


printf '\nProject parent directory\n\n[1] projects\n[2] vogsphere\n\n'
read answer
if [ $answer="1" ]
then
   DIR='github'
else
   DIR='vogsphere'
fi

NAME=`pwd`
cd ~/42/scripts/c_formatter_42/
python3 -m c_formatter_42 ~/42/$DIR/$NAME/_**/_**/{*.c,*.h}
python3 -m c_formatter_42 ~/42/$DIR/$NAME/_**/{*.c,*.h}
