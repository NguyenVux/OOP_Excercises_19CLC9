#include "Square.h"

double Square::getEdge()
{
    return this->e[0];
}

void Square::setEdge(double f)
{
    this->e[0] = f;
    this->e[1] = f;
}
