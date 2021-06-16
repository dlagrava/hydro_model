#include "doctest.h"

#include <hydro_model/input_utils.hpp>

#include <iostream> // Needed in OSX builds for some weird reason.
                    // See https://github.com/onqtam/doctest/issues/126#issuecomment-381742003
#include <string> // This isn't needed but it clarifies intent.

TEST_CASE("example")
{
    
    SUBCASE("function hello()")
    {
        CHECK("Hello" == "Hello");
    }
}
