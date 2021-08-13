#ifndef REACH_
#define REACH_

#include <map>

namespace hydro_model {

/**
 * Internal representation of properties of a reach.
 *
 */
class ReachProperties {
    public:
        ReachProperties();

        // Setters
        void AddProperty(std::string property_name, float value);

        // Getters
        float GetProperty(std::string property_name);

        // Test to see if it contains the property
        bool HasProperty(std::string property_name);


    private:
        std::map<std::string, float> properties_;
};

class ReachState {
public:
    ReachState();
    virtual ~ReachState();

    ReachState Clone();
    void Initialize();
    void AddStorage(std::string storage_name);
    void AddFlux(std::string flux_name);

private:
    std::map<std::string, double> storages_;
    std::map<std::string, double> fluxes_;
};

/**
* Internal representation of a reach.
* A reach is the basic geographical unit for the model.
*
*/
class Reach {
    public:
        Reach();
        Reach(long int reach_id_, float lat, float lon, ReachProperties const& properties);

        // Getters
        float GetLatitude();
        float GetLongitude();
        const Reach* GetUpstreams();
        const Reach* GetDownstreams();
        float GetPropertyValue(std::string property_name);
        ReachProperties& GetReachProperties();
        ReachState& GetReachState();

        // Setters
        void SetLatitude(float lat);
        void SetLongitude(float lon);
        void SetProperties(ReachProperties &properties);
        void SetPropertyValue(std::string property_name, float value);
        void UpdateReachState(ReachState& new_state);

        // Misc.
        const std::string ToString();

    private:
        float latitude_; /*! Latitude of the reach */
        float longitude_; /*! Longitude of the reach*/
        long int reach_id_; /*! Reach ID (usually 8 numbers in NZ) */
        ReachProperties properties_;
        ReachState state;
};

} // namespace hydro_model
#endif // REACH_

