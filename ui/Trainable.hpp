#ifndef TRAINABLE_HPP
#define TRAINABLE_HPP

#include <QMap>
#include <QPushButton>
#include "entity/unit/Unit.hpp"

class Trainable
{
public:
    Trainable();

protected:
    QQueue<Unit::Type> training;

    static QPair<int, int> costs(Unit::Type type);
};

#endif // TRAINABLE_HPP
