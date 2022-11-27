#!/bin/bash

rm -rf $TMPDIR/$1_repo
mkdir $TMPDIR/$1_repo
cd project/$1
cp *.c *h Makefile $TMPDIR/$1_repo/
cd $TMPDIR/$1_repo
python3 -m c_formatter_42 *.c *.h
norminette
git init
git remote add origin $2
git add -A && git commit -m "a"
git push --force --set-upstream origin master