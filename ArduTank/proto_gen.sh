#!/bin/bash

OUT_DIR=./

for file in src/protos/*.proto;
do nanopb-0.3.5-linux-x86/generator-bin/protoc --cpp_out=$OUT_DIR --python_out=$OUT_DIR $file;
done;

