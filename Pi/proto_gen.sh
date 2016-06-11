#!/bin/bash

OUT_DIR=./

for file in ../ArduTank/src/protos/*.proto;
do protoc --python_out=$OUT_DIR --proto_path=$(dirname $file) $file;
done;
