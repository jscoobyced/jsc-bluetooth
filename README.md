# JSC Bluetooth Library

This bluetooth library contains a few C libraries to scan, register or communicate with bluetooth devices.

Currently supported features:
- Register a bluetooth profile using a custom service UUID
- Scan for bluetooth devices
- Scan for bluetooth devices that have a particular service UUID
- Pair/Unpair a device
- Open a RFCOMM serial port communication with a device

## Building

Currently, this has been tested only on Ubuntu 21.04, 64-bit and arm architectures.

### Dependencies

You will need to install the following dependencies to build from sources:
- build-essential
- libtool
- bluez
- glib-2.0
- libglib2.0-dev
- libdbus-glib-1-dev
- libdbus-1-dev
- libgio3.0-cil-dev

You can easily install them via the `APT` command:
```
sudo apt install -y build-essential libtool libbluetooth-dev \
    libglib2.0-dev libdbus-glib-1-dev libdbus-1-dev libgio3.0-cil-dev
```

### Compilation

I have included 2 scripts: `autogen.sh` and `buildme.sh`.

#### autogen.sh

This will clean-up all the build intermediary files and initiate the build configuration.  
Internally it will call the `cleanup.sh` script.

#### buildme.sh

This will run the `configure` command, and if successful, run the `make` command.  
If you run this script with the `install` argument it will also run `make install`.  
By default the installation goes to `src/build/release/` folder.