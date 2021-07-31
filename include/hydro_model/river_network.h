#ifndef RIVER_NETWORK_H_
#define RIVER_NETWORK_H_

#include <hydro_model/reach.h>
#include <map>

namespace hydro_model {

    class RiverNetwork
    {
        public:
            /** Default constructor */
            RiverNetwork();
            /** Default destructor */
            virtual ~RiverNetwork();

            void AddReach(const Reach *reach);
            void BuildNetwork();
        private:
            std::map<std::string, Reach*> river_network_; //! The container for the network
    };
}
#endif // RIVER_NETWORK_H_

