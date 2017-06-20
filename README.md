# Requirements and Instructions 

## Compiling for the micro:bit
Compilation requires yotta, for an introduction read [this](https://lancaster-university.github.io/microbit-docs/offline-toolchains/#yotta) article.

Here is a short overview:
- `yt build` build the project
- hex file is placed into `/build/<TARGET_NAME>/source` (flash `microbit-combined.hex` by copying it onto the microbit)

## Troubleshooting

**Error:**
```
...
ERROR: the arm gcc program arm-none-eabi-gcc could not be found

  you can install the ARM GCC embedded compiler tools from:
  https://launchpad.net/gcc-arm-embedded/+download 
...
```

**Solution:** Either install via apt or download from the link.
If necessary add `bin` folder to `PATH`.

**Error:**
```
...
/bin/sh: 1: srec_cat: not found
ninja: build stopped: subcommand failed.
error: command ['ninja'] failed
```

**Solution:** apt install srecord
