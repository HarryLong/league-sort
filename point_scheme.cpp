#include "point_scheme.h"

PointScheme::PointScheme(int win, int tie, int lose) : win_(win), tie_(tie), lose_(lose)
{

}

PointScheme::~PointScheme()
{

}

int PointScheme::win() const
{
    return win_;
}

int PointScheme::tie() const
{
    return tie_;
}

int PointScheme::lose() const
{
    return lose_;
}
