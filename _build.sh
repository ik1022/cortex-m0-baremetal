#!/bin/sh

rm -Rf .build
# cmake -S. -B.build -GNinja -DCMAKE_BUILD_TYPE=Release
cmake -S. -B.build -GNinja -DCMAKE_BUILD_TYPE=Debug
cmake --build .build --clean-first -v
# #mkdir .bin
# arm-none-eabi-objcopy -Oihex .build/baremetal .bin/mcu.hex
# arm-none-eabi-size --format=berkeley .build/baremetal

exit 0
