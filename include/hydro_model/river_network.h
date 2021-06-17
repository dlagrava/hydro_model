#ifndef RIVER_NETWORK_H_
#define RIVER_NETWORK_H_

#include <map>

#include <hydro_model/reach.h>



namespace hydro_model {
    
    class RiverNetwork {
        public:
            RiverNetwork();

            void AddReach(const *Reach reach);
            void BuildNetwork();

        private:
            std::map<std::string, *Reach> river_network_;
            
    }



};

#endif // RIVER_NETWORK_H_

