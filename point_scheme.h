/**
  Author: @Harry Long

  A point scheme outlines the points granted/removed for individual wins and losses.
  To implement your own, simply subclass PointScheme (see BasePointScheme for example)
  */

#ifndef POINT_SCHEME_H
#define POINT_SCHEME_H


class PointScheme
{
public:
    PointScheme(int win, int tie, int lose);
    virtual ~PointScheme();

    virtual int win() const;
    virtual int lose() const;
    virtual int tie() const;

private:
    const int win_;
    const int lose_;
    const int tie_;
};


#define WIN 3
#define TIE 1
#define LOSE 0
class BasePointScheme : public PointScheme
{
public:
    BasePointScheme() : PointScheme(3,1,0) {}
};

#endif
