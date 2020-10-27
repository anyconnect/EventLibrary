The AnyConnect Event Plugin Library creates a junction between AnyConnect's Smarter Camera Platform Libraries and your smarter camera’s event library.
The steps to build and deploy your Event Library are:

# Procedure

1. Complete the stub functions in Event.cpp.
2. Compile your libevent.so.
3. Copy the libevent.so in the lib directory of your smart camera application.


# What’s Included

- README		Instructions to complete the libevent.cpp stub functions and compile and use libevent.so.
- Event.h		Event library header file.  This derived class overrides EventService base class member functions.
- Event.cpp		Event library source file.  You must complete the stub functions.
- EventService.h	These base class member functions are overridden by Event derived class.
- Makefile		Compiles libevent.so.
- test/Test.h		Test application for libevent.so.
- test/Test.cpp		Test application for libevent.so.
- test/Makefile		Compiles the test application.


# What’s Required

### Software packages
- Linux
- dl library
- pthreads library 
- gcc/g++ version 7.x or higher


# How to complete the Event.cpp stub functions

- setEventReceiveCallback() // Set the callback function from the AnyConnect smarter camera platform library to receive events from the camera's event library.
- eventReceiveThread() // Read data from the camera’s event library and writes it to the callback function.


# How to compile your Event Library.

Compile your libevent.so by typing “make all”.


# How to test your Event Library.

Compile the test application by typing “test/make all”.  This will generate a test application called “eventtest”. Run the test application by typing “test/eventtest”.  

If successful, the test application will print “Your AnyConnect Event Library loads!”.  If not successful, the test application will print “Your AnyConnect Event Library does not load.”.
