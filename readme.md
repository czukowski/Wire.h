Arduino Wire library fork
-------------------------

See http://code.google.com/p/arduino/, http://www.arduino.cc/en/Reference/Wire

This repo is actually a Solution directory for the Atmel Studio 6.

Note that the included `*.cppproj` files have some Arduino and other dependencies in it. These include
some absolute paths that will unlikely match yours. See C++ Project properties -> Toolchain and update
Directories in AVR/GNU C Compiler, AVR/GNU C++ Compiler and Libraries in AVR/GNU Linker.

The main difference to the original library is that the `TwoWire` class inherits from the `IWire`
interface and the object pre-instantiation (`Wire`) has been removed. The application should initialize
it as needed.

Also, the `Wire.cpp` and `Wire.h` files has been renamed respectively to `TwoWire.cpp` and `TwoWire.h`
because that is those files' class name.