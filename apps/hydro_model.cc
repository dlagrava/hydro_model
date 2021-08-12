#include <iostream>
#include <string>

#include <hydro_model/input_utils.h>
#include <hydro_model/abstract_model.h>

int main(int argc, char* argv[])
{

    if (argc == 2 && std::string{ argv[1] } == "--version")
    {
        std::cout << "Copyright \n";
        return 0;
    }

    // Do something

}
