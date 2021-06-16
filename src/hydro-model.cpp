#include <hydro_model/config.hpp>
#include <hydro_model/input_utils.hpp>

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{

    if (argc == 2 && std::string{ argv[1] } == "--version")
    {
        std::cout << "Hydro Model version " << VERSION << "\n";
        std::cout << "Copyright \n";
    }
    else
    {
        // Do something
    }
}
