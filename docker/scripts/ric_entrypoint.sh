#!/bin/bash

ip_check="^[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+$"

## Check for interface environment
if [[ -n ${BIND_INTERFACE} ]]; then
    export RIC_IP=$(ip -4 addr show dev ${BIND_INTERFACE} | grep inet | awk '{print $2}' | cut -d / -f1)

    if [[ ${RIC_IP} =~ ${ip_check} ]]; then
        sed -i "s/NEAR_RIC_IP = 127.0.0.1/NEAR_RIC_IP = ${RIC_IP}/g" /usr/local/etc/flexric/flexric.conf
    fi
fi

## Run near-RT RIC
stdbuf -o0 nearRT-RIC