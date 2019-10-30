@echo off
clang -include ./c/wasm.h --include-directory include --target=wasm32 -O3 -flto -nostdlib -Wl,--no-gc-sections -Wl,--import-memory -Wl,--no-entry -Wl,--export-all -Wl,--lto-O3 -o qrcode.wasm c/FinderPattern.c c/Qrcode.c c/FinderPatternFinder.c