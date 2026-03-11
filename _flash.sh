#!/bin/sh

pyocd flash  -uremote:host.docker.internal:5555 .build/baremetal.hex

exit 0
