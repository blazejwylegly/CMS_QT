#include "datadecorator.h"

namespace cms {
namespace data {

class DataDecorator::Implementation{

public:
    Entity* parentEntity {nullptr};
    QString label;
    Implementation(Entity* _parent, const QString& _label) : parentEntity(_parent), label(_label){  };
};


DataDecorator::DataDecorator(Entity* parent, const QString& label) : QObject((QObject*) parent){
    implementation.reset(new Implementation(parent,label));
}

DataDecorator::~DataDecorator(){

}

const QString& DataDecorator::label() const {
    return implementation->label;
}

Entity* DataDecorator::parentEntity(){
    return implementation->parentEntity;
}
}
}
