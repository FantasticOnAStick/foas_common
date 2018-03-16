#!/bin/bash

git submodule update --init --recursive
cd 3rdparty/json-c
./autogen.sh
cd -
