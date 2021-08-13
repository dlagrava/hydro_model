#include <hydro_model/abstract_model.h>
#include <hydro_model/reach.h>

#include <iostream>

namespace hydro_model {

AbstractOperation::AbstractOperation()
{}

AbstractModel::AbstractModel()
{}

AbstractModel::~AbstractModel()
{}

bool IdentityOperation::CanApplyOperation(Reach &reach){
    std::cout << reach.ToString() << std::endl;
    return true;
}

bool IdentityOperation::ApplyOperation(Reach &reach){
    std::cout << reach.ToString() << std::endl;
    return true;
}

TopNetOperation::TopNetOperation(){
    topnet_min_properties_ = {"topmodf", "topmodn", "K0", "v"};
}

bool TopNetOperation::CanApplyOperation(Reach &reach){
    ReachProperties& reach_properties = reach.GetReachProperties();
    for (auto& property : topnet_min_properties_){
        if (! reach_properties.HasProperty(property)){
            return false;
        }
    }
    return true;
}



} // namespace hydro_model
