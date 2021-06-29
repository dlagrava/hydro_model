#include <iostream>
#include <string>

#include <hydro_model/input_utils.h>

int main(int argc, char* argv[])
{

    if (argc == 2 && std::string{ argv[1] } == "--version")
    {
        std::cout << "Copyright \n";
    }
    else
    {
        // Do something
    }
}
