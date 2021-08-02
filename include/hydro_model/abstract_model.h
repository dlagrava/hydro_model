#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include <hydro_model/reach.h>

namespace hydro_model {

class AbstractOperation {
/**
 * Abstraction for an operation that changes the internal states of
 * a Reach.
 */
public:
    AbstractOperation();
    virtual ApplyOperation(Reach &reach) = 0;
    virtual bool CanApplyOperation(Reach &reach) = 0;
private:
    std::string name;

};

class AbstractModel
{
 /**
 * Abstraction for a model, which modifies each state of a RiverNetwork
 * by applying the AbstractOperations defined.
 */
    public:
        AbstractModel();
        virtual ~AbstractModel();
        virtual ApplyOperations(RiverNetwork &network) = 0;

    protected:

    private:
        std::vector<AbstractOperation*> operations_;

};

} // namespace hydro_model
#endif // ABSTRACTMODEL_H
