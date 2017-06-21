#!/bin/sh

# for most convenient use, copy file to somewhere in the path and
# rename it to goyt (or whatever is prefered).

if [ "$1" = "-h" ] || [ "$1" = "-help" ] || [ "$1" = "--help" ]; then
  printf "usage: $0 [-h] [-mnt mountdir]"
  printf "\n\n"
  printf "Use this script to call yotta build, mount the microbit, and "
  printf "automtically copy the resulting file to the microbit. "
  printf "Use -h to display this help message.\n"
  exit 0
fi

# set mount directory
if [ "$1" = "-mnt" ]; then
  MOUNT_DIR="$2"
else
  # local mount folder
  MOUNT_DIR="/media/$USER/MICROBIT"
fi

# create local directory for mounting if it doesn't exist
if [ -d "$MOUNT_DIR" ]; then
  printf "Mount directory exists.\n"
else
  printf "Creating mount directory...\n"
  sudo mkdir "$MOUNT_DIR"
fi

# mount MICROBIT to local directory
if mount | grep "$MOUNT_DIR" > /dev/null; then
  printf "Already mounted.\n"
else
  printf "Mounting microbit...\n"
  sudo mount /dev/disk/by-label/MICROBIT "$MOUNT_DIR"
fi

# build project
if yt build; then
  # copy hex file (source: https://lancaster-university.github.io/microbit-docs/offline-toolchains/#installation-on-linux)
  sudo cp build/$(yt --plain target | head -n 1 | cut -f 1 -d' ')/source/$(yt --plain ls | head -n 1 | cut -f 1 -d' ')-combined.hex $MOUNT_DIR
else
  exit 1
fi
