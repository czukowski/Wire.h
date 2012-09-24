Arduino Wire library fork
-------------------------

See http://code.google.com/p/arduino/, http://www.arduino.cc/en/Reference/Wire

Note that the `Wire.cppproj` file is included for Atmel Studio 6, which has some
dependencies in it. See C++ Project properties -> Toolchain and update Directories
in AVR/GNU C Compiler, AVR/GNU C++ Compiler and Libraries in AVR/GNU Linker.

The difference to the original library is that the `TwoWire` class inherits from the
`IWire` interface and the object pre-instantiation has been removed
(see bbca584b6307957b8302e901825223794d5c07da)