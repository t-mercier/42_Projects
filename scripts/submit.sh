#!/bin/bash

BLACK_GREEN="\033[42m \033[1;30m"
BLACK_CYAN="\033[46m \033[1;30m"
RESET='\033[0m'

echo $1
if [ $1 ]
then

DIR=`pwd`
NAME=${PWD##*/}
VOG=~/42/vogsphere/$NAME
NAME=${NAME:-/}
_DIR=$(dirname `pwd`)

echo -e "Project name = $NAME"
echo -e "Project folder = $DIR"

if [ $1 ] && [ $_DIR='github' ]; then
    URL=$1
    echo -e "- clone to vogosphere"
    git clone $URL $VOG
    echo -e "- copy project folder $NAME to $VOG"
    cp -r ~/42/github/$NAME/ $VOG
    echo -e "- copy .gitignore"
    cp ~/42/.gitignore .
    echo -e "- copy Makefile"
    cp ~/42/github/$NAME/Makefile $VOG
    printf '\nInclude MLX ?\n\n[y] yes\n[n] no\n\n'
    read answer
    if [ $answer='y' ]; then
        cp -r ~/42/github/lib42/ $VOG
        echo -e "cloning MLX submodule"
        git submodule add git@github.com:codam-coding-college/MLX42.git _lib42/MLX42
    elif [ $answer='n' ]; then
        echo -e "copy lib42" && rsync -av ~/42/github/lib42/ $VOG --exclude MLX42;
    fi
fi
    echo -e "make fclean"
    make fclean
    echo -e "clean libs"
    make cleanlib
    echo -e "norminette check"
    norminette $VOG/_**/_**/{*.c,*.h}
    norminette $VOG/_**/{*.c,*.h}
    bash ~/42/scripts/push.sh "submit";
