#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan
{
  friend ostream &operator<<(ostream &outStream, const TimeSpan &clock);
  friend istream &operator>>(istream &inStream, TimeSpan &clock);

private:
  int hours;
  int minutes;
  int seconds;

  // return the total seconds
  void normalize(double hours, double minutes, double seconds);

public:
  // setters or mutators
  bool setTime(int hours, int minutes, int seconds);

  // getters or accessors
  int getHours() const;
  int getMinutes() const;
  int getSeconds() const;
  int timeInSeconds() const;

  // Overloading
  TimeSpan &operator+=(const TimeSpan &ts);
  TimeSpan operator+(const TimeSpan &ts) const;

  TimeSpan &operator-=(const TimeSpan &ts);
  TimeSpan operator-(const TimeSpan &ts) const;

  
  TimeSpan operator-() const;
  bool operator==(const TimeSpan &ts) const;
  bool operator!=(const TimeSpan &ts) const;

  // Constructors
  TimeSpan(double hours, double minutes, double seconds);
  TimeSpan(double minutes, double seconds);
  TimeSpan(double seconds);
  TimeSpan();

  // Destructor
  ~TimeSpan();
};

#endif
