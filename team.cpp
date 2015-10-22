#include "team.h"
#include <algorithm>

Team::Team(std::string name) : name_(name), points_(0)
{
}

Team::~Team()
{

}

bool Team::operator ==(const Team &other) const
{
    return getName() == other.getName();
}

bool Team::operator < (const Team & other) const
{
    if(points_ == other.getPoints()) // Alphabetical sort necessary
        return name_.compare(other.getName()) < 0;

    return points_ > other.getPoints();
}

bool Team::operator > (const Team & other) const
{
    if(points_ == other.getPoints()) // Alphabetical sort necessary
        return name_.compare(other.getName()) > 0;

    return points_ < other.getPoints();
}

std::string Team::getName() const
{
    return name_;
}

int Team::getPoints() const
{
    return points_;
}

void Team::addPoints(int points)
{
    points_ += points;
}
