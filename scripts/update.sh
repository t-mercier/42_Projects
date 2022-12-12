#!/bin/bash

# USAGE : ./submit <local project name> <url repo>

cd ~/42/vogsphere
make fclean -C lib42
make fclean -C $1_repo
if  [ ! -f .gitignore ]; then cp ~/42/.gitignore .; fi
TMP_DIR="$1_repo"
cd ~/42/scripts
./remove_dsstore.sh
./check.sh $1_repo
cd ~/42/vogsphere/$1_repo
sh ~/42/scripts/push.sh "submit $1"