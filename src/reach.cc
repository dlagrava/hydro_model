#include <hydro_model/reach.h>

#include <iostream>
#include <stdexcept>

namespace hydro_model
{
/**
 * Default constructor
 * Used to create an empty reach and fill it later
 */
Reach::Reach() :
    latitude_{ 0.0 },
    longitude_{ 0.0 },
    properties_{ ReachProperties() }
{}


const std::string Reach::ToString(){
    return std::string("Reach");
}

ReachProperties& Reach::GetReachProperties(){
    return properties_;
}

/**
 * Get a reach property from ReachProperties
 * This method will throw an out of range exception
 */

float ReachProperties::GetProperty(std::string property_name)
{
    float property_value = 0.;
    property_value = properties_.at(property_name);
    return property_value;
}

bool ReachProperties::HasProperty(std::string property_name){
    return properties_.find(property_name) != properties_.end();
}

} // namespace hydro_model

