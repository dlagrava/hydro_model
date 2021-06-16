#include <hydro_model/reach.hpp>

#include <iostream>
#include <stdexcept>

/**
 * Default constructor
 * Used to create an empty reach and fill it later
 */
Reach::Reach() : 
    latitude{ 0.0 },
    longitude{ 0.0 },
    properties{ ReachProperties() }
{}


/**
 * Get a reach property from ReachProperties
 * This method will throw an out of range exception
 */

float ReachProperties::getProperty(std::string propertyName) {
    float propertyValue = 0.;
    try {
        propertyValue = properties.at(propertyName);
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Non valid property requested: " << oor.what() << std::endl;
        throw oor;
    }
    
    return propertyValue;
}




