#!/bin/bash


# get current branch and push
current_branch=$(git branch | sed -n -e 's/^\* \(.*\)/\1/p')

# get the argument message
message="$1"

# If no commit message is passed, use current date time in the commit message
if [[ -z "${message// }" ]]
    then
        message=$(date '+%Y-%m-%d %H:%M:%S')
fi

# stage all changes
git add .
echo "\033[0;32m-> staged all git files\033[0m"

# add commit
git commit -m "$message"
echo "\033[0;32m-> added the commit with message: \033[42m \033[1;30m'$message' \033[0m"

# git push
git push
echo "\033[0;32m-> all changes pushed to \033[42m \033[1;30m'$current_branch' \033[0;36m \033[0;32mbranch"
