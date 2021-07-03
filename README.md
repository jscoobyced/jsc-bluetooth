# JSC Bluetooth Library

[![jsc-bluetooth](bluetooh.png)]


This bluetooth library contains a few C libraries to scan, register or communicate with bluetooth devices.

Currently supported features:
- Register a bluetooth profile using a custom service UUID
- Scan for bluetooth devices
- Scan for bluetooth devices that have a particular service UUID
- Pair/Unpair a device
- Receive data over an RFCOMM serial port communication with a device

Work in progress:
- Send data over an RFCOMM serial port communication with a device

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

## Sample programs

### Server

You can start a server using the default service UUID (located in `src/main/main.h`) by launching from the root folder:
```
./run.sh server
```
Then you need a Bluetooth Serial communication client that can connect to it. There is a sample python client. You can run it (from a different machine):
```
python3 btclient.py
```

### Client

You can start a scan of the default service UUID (located in `src/main/main.h`) by launching from the root folder:
```
./run.sh client
```
It doesn't do much, just scan and if it finds the device exposing the service UUID, it will print its name and MAC address.