#!/bin/bash

## output dir
mkdir -p out

## binary
mkdir -p out/bin
cp ./submodules/flexric/build/examples/ric/nearRT-RIC out/bin

## service models
mkdir -p out/serviceModels

cp ./submodules/flexric/build/src/sm/kpm_sm/kpm_sm_v03.00/libkpm_sm.so out/serviceModels 
cp ./submodules/flexric/build/src/sm/rc_sm/librc_sm.so out/serviceModels
cp ./submodules/flexric/build/src/sm/mac_sm/libmac_sm.so out/serviceModels
cp ./submodules/flexric/build/src/sm/slice_sm/libslice_sm.so out/serviceModels
cp ./submodules/flexric/build/src/sm/pdcp_sm/libpdcp_sm.so out/serviceModels
cp ./submodules/flexric/build/src/sm/gtp_sm/libgtp_sm.so out/serviceModels
cp ./submodules/flexric/build/src/sm/tc_sm/libtc_sm.so out/serviceModels
cp ./submodules/flexric/build/src/sm/rlc_sm/librlc_sm.so out/serviceModels