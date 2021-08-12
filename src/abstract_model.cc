#include <hydro_model/abstract_model.h>
#include <hydro_model/reach.h>

#include <iostream>

namespace hydro_model {

AbstractOperation::AbstractOperation()
{}

AbstractOperation::~AbstractOperation()
{}

AbstractModel::AbstractModel()
{}

AbstractModel::~AbstractModel()
{}

bool IdentityOperation::CanApplyOperation(Reach &reach){
    return true;
}

bool IdentityOperation::ApplyOperation(Reach &reach){
    return true;
}

} // namespace hydro_model
