# cpp-plugins
A basic example of creating a C++ plugin and dynamically loading it into a client application using boost::dll

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
