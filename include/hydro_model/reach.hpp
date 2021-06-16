#ifndef REACH_
#define REACH_

#include <map>
/**
 * Internal representation of properties of a reach.
 *
 */ 
class ReachProperties {
    public:
        ReachProperties();

        // Setters
        void addProperty(std::string propertyName, float value);

        // Getters
        float getProperty(std::string propertyName);
        

    private:
        std::map<std::string, float> properties;

                
        
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
        float getLatitude();
        float getLongitude();
        const Reach* getUpstreams();
        const Reach* getDownstreams();

        // Setters
        void setLatitude(float lat);
        void setLongitude(float lon);
        void addUpstream(Reach& upstreamReach);
        void addDownstream(Reach& downstreamReach);
        void setProperties(ReachProperties const& properties);
        
    private:
        float latitude; /*! Latitude of the reach */
        float longitude; /*! Longitude of the reach*/
        long int reach_id; /*! Reach ID (usually 8 numbers in NZ */
        ReachProperties properties;        
        Reach* upstream;
        Reach* downstream;        
};


#endif // REACH_
