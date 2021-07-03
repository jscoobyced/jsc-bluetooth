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