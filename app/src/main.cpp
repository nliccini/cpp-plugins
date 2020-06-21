#include <iostream>
#include <string>

#include <boost/dll/import.hpp>

#include <ilogger.h>

int main(int argc, char* argv[])
{
    if(argc < 2){
        std::cout << "Please provide the path to the .dll or .so containing a logger implementation." << std::endl;
        return -1;
    }
    
    std::string lib(argv[1]);
    std::cout << "Attempting to import " << lib << std::endl;

    std::function<i::logger*()> create_logger = [](){ return nullptr; };
    try{
        std::function<std::string()> version = boost::dll::import<std::string()>(lib, "version");
        std::cout << "Found version " << version() << std::endl;
        create_logger = boost::dll::import<i::logger*()>(lib, "create_logger"); 
    }catch(boost::system::system_error const&){
        std::cout << "Error: Could not load from " << lib << std::endl;
    }
    
    i::logger *l = create_logger();
    if(l){
        for(int i = 0; i < 10; ++i){
            l->log();
        }
        delete l;
    }

    return 0;
}