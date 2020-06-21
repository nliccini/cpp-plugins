# cpp-plugins
A basic example of creating a C++ plugin and dynamically loading it into a client application using boost::dll

## Requirements

Your system must have `boost` and `cmake` installed.

    sudo apt-get install build-essential cmake libboost-all-dev

## Usage

### Building the dynamically linked library

The `logger` project is an implementation of the `i::logger` interface located in `app/inc/ilogger.h`

To build the plugin, use CMake:

    cd cpp-plugins/logger
    mkdir build && cd build
    cmake .. -DINTERFACE_INCLUDE_DIR=path/to/cpp-plugins/app/inc
    cmake --build .

The liblogger.dll (or liblogger.so if using gcc) will be located in the `cpp-plugins/logger/build/bin` directory

### Building the client application

The `app` project is a simple client application that will load the plugin using `boost::dll`

To build the application, use CMake:

    cd cpp-plugins/app
    mkdir build && cd build
    cmake .. -DBOOST_ROOT=path/to/boost -DINTERFACE_INCLUDE_DIR=path/to/cpp-plugins/app/inc
    cmake --build .

The plugins-app.exe (or plugins-app if using gcc) will be locaated in the `cpp-plugins/app/build/bin` directory

### Running the client application

To run the application, you must pass in the path to the plugin as an argument:

    plugin-app.exe path/to/cpp-plugins/logger/build/bin/liblogger.dll
    
## The Concept

Motivation: You have an application that has some requirements, so you define an interface. Someone else says they know how to fulfill your requirements by implementing your interface, but they want their code to be protected/private, so they want to implement your interface and provide you with a dynamically linked library which has all the functionality but doesn't expose any source code or implementation details. This is easy if you follow our example here!

First we define an abstract interface: `i::logger`. This allows the client application to understand what functionality is expected by any concrete implementations that may come from loading a plugin. This also allows any developer who wants to create a plugin to have a strict set of requirements for their plugin.

In the implementation of the plugin, the `logger` project, we subclass the `i::logger` interface and define our own concrete class called `logger`. We provide custom logic by implementing the `i::logger::log` function. In order to expose our implementation to a user of our plugin, we must define a factory method in the `logger.h` file, here we are expected to define the function as `create_logger` which returns a pointer to our subclass. We are also expected to provide a version of our plugin by implementing the `version` function. The modifiers `extern "C" EXPORT` allow the compiler to expose these functions externally when building it as a shared library which is seen in the `CMakeLists.txt` file. `EXPORT` is a macro defined differently depending on the build architecture (Windows vs Linux) that is necessary to expose the functions we want to export.

In our client application, we use `boost::dll::import` to look up the exported functions from the input library (a .dll or a .so). If we successfully load the plugin and get the exported functions, we are able to get all the functionality of the concrete `i::logger` implementation without ever exposing that class or its logic since we have defined an abstract interface. When we use the interface functions, we see the output from the plugin's implementation. Voila!
