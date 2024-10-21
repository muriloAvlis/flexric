#!/bin/bash

ip_check="^[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+$"

## Check for interface environment
if [[ -n ${BIND_INTERFACE} ]]; then
    export RIC_IP=$(ip -4 addr show dev ${BIND_INTERFACE} 2>/dev/null | grep inet | awk '{print $2}' | cut -d / -f1)

    # If interface doesn't exist, exit
    if [[ -z "${RIC_IP}" ]]; then
        echo "[Error] Device \"${BIND_INTERFACE}\" does not exist"
        exit 1
    fi

    if [[ ${RIC_IP} =~ ${ip_check} ]]; then
        sed -i "s/NEAR_RIC_IP = 127.0.0.1/NEAR_RIC_IP = ${RIC_IP}/g" /usr/local/etc/flexric/flexric.conf
    else
        echo "[Error] Invalid IP address obtained from ${BIND_INTERFACE}"
        exit 1
    fi
fi

## Run near-RT RIC
stdbuf -o0 nearRT-RIC