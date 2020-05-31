#ifndef STRINGDECORATOR_H
#define STRINGDECORATOR_H

#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <cms-lib_global.h>
#include <data/datadecorator.h>

namespace cms {
namespace data {
class StringDecorator : public DataDecorator
{
    Q_OBJECT
public:
    StringDecorator();
};

}
}

#endif // STRINGDECORATOR_H
