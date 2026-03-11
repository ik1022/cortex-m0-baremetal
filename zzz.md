setup

```
npm install --global xpm@0.23.2

xpm install @xpack-dev-tools/cmake@3.31.9-1.1 --verbose
xpm install @xpack-dev-tools/arm-none-eabi-gcc@15.2.1-1.1.1 --verbose
xpm install @xpack-dev-tools/ninja-build@1.13.1-1.1 --verbose

xpm run prepare --config debug
xpm run build --config debug

pyocd erase --mass -t a31g123

pyocd flash ./build/debug/baremetal.hex
pyocd flash ./build/release/baremetal.hex
```
