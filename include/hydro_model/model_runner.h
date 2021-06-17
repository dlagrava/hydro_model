#ifndef MODEL_RUNNER_H_
#define MODEL_RUNNER_H_

#include <ctime>

namespace hydro_model {

    enum ModelConfiguration {
        double delta_t; //! Time in seconds
        time_t start_time; //! starting time for model
        time_t end_time; //! ending time for model
        double time_steps //! intermediate time steps
        

    };


    class ModelRunner {
        public:
            ModelRunner(const ModelConfiguration *model_configuration);
            
            void Run();
            void RunSingleIteration();
            
    };




} // namespace hydro_model

#endif // MODEL_RUNNER_H_
