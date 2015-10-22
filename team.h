#ifndef TEAM_H
#define TEAM_H

#include <string>

class Team
{
public:
    Team(std::string name);
    ~Team();
    bool operator ==(const Team &other) const;
    bool operator < (const Team &other) const;

    std::string getName() const;
    int getPoints() const;
    void addPoints(int points);

private:
    std::string name_;
    int points_;
};

#endif // TEAM_H
