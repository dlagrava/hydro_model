#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include <hydro_model/reach.h>
#include <hydro_model/river_network.h>
#include <vector>
#include <string>

namespace hydro_model {

class AbstractOperation {
/**
 * Abstraction for an operation that changes the internal states of
 * a Reach.
 */
public:
    AbstractOperation();
    virtual ~AbstractOperation();
    virtual bool ApplyOperation(Reach &reach) = 0;
    virtual bool CanApplyOperation(Reach &reach) = 0;

private:
    std::string name;

};

class IdentityOperation : AbstractOperation {
/**
 * Simple operation that doesn't do anything to a Reach. It is
 * used to test things.
 */
    virtual bool ApplyOperation(Reach &reach);
    virtual bool CanApplyOperation(Reach &reach);

};


class TopNetOperation : AbstractOperation {
public:
    virtual bool ApplyOperation(Reach &reach) = 0;
    virtual bool CanApplyOperation(Reach &reach);
private:
    std::vector<std::string> topnet_min_properties_;

};


class AbstractModel
{
/**
* Abstraction for a model, which modifies a whole RiverNetwork
* by applying a list of AbstractOperations.
*/
public:
    AbstractModel();
    virtual ~AbstractModel();
    virtual bool ApplyOperations(RiverNetwork &network) = 0;
    auto AddOperation(AbstractOperation *operation);
protected:

private:
    std::vector<AbstractOperation*> operations_;

};

} // namespace hydro_model
#endif // ABSTRACTMODEL_H
