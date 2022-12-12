#!/bin/bash

NAME=`pwd`

printf '\nProject parent directory\n\n[1] projects\n[2] vogsphere\n\n'
read answer
if [ $answer="1" ]
then
   DIR='github'
else
   DIR='vogsphere'
fi

make fclean -C ~/42/$DIR/$NAME
make cleanlib -C ~/42/$DIR/$NAME
