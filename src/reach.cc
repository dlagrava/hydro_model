#include <hydro_model/reach.h>

#include <iostream>
#include <stdexcept>

namespace hydro_model {
    /**
     * Default constructor
     * Used to create an empty reach and fill it later
     */
    Reach::Reach() : 
        latitude_{ 0.0 },
        longitude_{ 0.0 },
        properties_{ ReachProperties() }
    {}


    /**
     * Get a reach property from ReachProperties
     * This method will throw an out of range exception
     */

    float ReachProperties::GetProperty(std::string property_name) {
        float property_value = 0.;
        try {
            property_value = properties_.at(property_name);
        }
        catch (const std::out_of_range& oor) {
            std::cerr << "Non valid property requested: " << oor.what() << std::endl;
            throw oor;
        }
    
        return property_value;
    }

} // namespace hydro_model

