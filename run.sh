#!/bin/bash

JSC_CMD="echo Usage $0 client|server"

if [ "$1" == "server" ];
then
  JSC_CMD="./bin/server"
elif  [ "$1" == "client" ];
then
  JSC_CMD="./bin/client"
fi

pushd src/build/release > /dev/null
LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH ${JSC_CMD}
popd > /dev/null