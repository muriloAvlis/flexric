#!/bin/bash

if [ -n "${NEAR_RIC_IP}" ]; then
sed -i "s/NEAR_RIC_IP = 127.0.0.1/NEAR_RIC_IP = ${NEAR_RIC_IP}/g" /usr/local/etc/flexric/gnb-cu.conf
fi

stdbuf -o0 emu_agent_gnb_cu -c /usr/local/etc/flexric/gnb-cu.conf