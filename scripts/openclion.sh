#!/bin/bash

if [ $1 ]; then open -a CLion $1; else open -a CLion .; fi

