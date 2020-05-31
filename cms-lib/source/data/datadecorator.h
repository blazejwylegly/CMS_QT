#ifndef DATADECORATOR_H
#define DATADECORATOR_H

#include <QObject>
#include <QScopedPointer>

#include <cms-lib_global.h>



namespace cms {
namespace data {
class Entity;

class CMSLIBSHARED_EXPORT DataDecorator : public QObject
{
    Q_OBJECT
    Q_PROPERTY (QString ui_label READ label CONSTANT)
public:
    explicit DataDecorator(Entity *parent = nullptr,
                           const QString& label = "");
    virtual ~DataDecorator();

    virtual const QString& label() const = 0;
    Entity* parentEntity();
private:
    class Implementation;
    QScopedPointer<Implementation> implementation;

};

}
}



#endif // DATADECORATOR_H
