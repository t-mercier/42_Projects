#!/bin/bash

shopt -s extglob

printf '\nselect folder and press enter\n\n[1] projects\n[2] vogsphere\n\n'
read answer
if [ $answer="1" ]
then
   DIR='github'
else
   DIR='vogsphere'
fi

NAME=`pwd`
norminette ~/42/$DIR/$NAME/_**/_**/{*.c,*.h}
norminette ~/42/$DIR/$NAME/_**/{*.c,*.h}
