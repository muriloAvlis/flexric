#!/bin/bash

if [ -n "${NEAR_RIC_IP}" ]; then
if [ "${FLEXRIC_VERSION}" = "br-flexric" ]; then
sed -i "s/NearRT_RIC_IP = \"127.0.0.1\"/NearRT_RIC_IP = \"${NEAR_RIC_IP}\"/g" /usr/local/etc/flexric/gnb-du.conf
else
sed -i "s/NEAR_RIC_IP = 127.0.0.1/NEAR_RIC_IP = ${NEAR_RIC_IP}/g" /usr/local/etc/flexric/gnb-du.conf
fi
fi

stdbuf -o0 emu_agent_gnb_du -c /usr/local/etc/flexric/gnb-du.conf