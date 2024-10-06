#include "TimeSpan.h"
#include <cmath>

using namespace std;

// Overloading
ostream &operator<<(ostream &outStream, const TimeSpan &ts)
{
  outStream << "Hours: " << ts.getHours() << ", Minutes: " << ts.getMinutes() << ", Seconds:  " << ts.getSeconds() << endl;
  return outStream;
}

istream &operator>>(istream &inStream, TimeSpan &ts)
{
  inStream >> ts.hours >> ts.minutes >> ts.seconds;
  ts.normalize(static_cast<double>(ts.hours), static_cast<double>(ts.minutes), static_cast<double>(ts.seconds));
  return inStream;
}

TimeSpan TimeSpan::operator+(const TimeSpan &ts) const
{
  TimeSpan temp = *this;
  temp += ts;
  return temp;
}

TimeSpan &TimeSpan::operator+=(const TimeSpan &ts)
{
  setTime(0, 0, (timeInSeconds() + ts.timeInSeconds()));
  return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan &ts) const
{
  TimeSpan temp = *this;
  temp -= ts;
  return temp;
}

TimeSpan &TimeSpan::operator-=(const TimeSpan &ts)
{
  setTime(0, 0, (timeInSeconds() - ts.timeInSeconds()));
  return *this;
}

TimeSpan TimeSpan::operator-() const
{
  TimeSpan temp;
  temp.setTime(-getHours(), -getMinutes(), -getSeconds());
  return temp;
}

bool TimeSpan::operator==(const TimeSpan &ts) const
{
  return timeInSeconds() == ts.timeInSeconds();
}
bool TimeSpan::operator!=(const TimeSpan &ts) const
{
  return timeInSeconds() != ts.timeInSeconds();
}

// Accessors
int TimeSpan::getHours() const
{
  return hours;
}

int TimeSpan::getMinutes() const
{
  return minutes;
}

int TimeSpan::getSeconds() const
{
  return seconds;
}

int TimeSpan::timeInSeconds() const
{
  return ((hours * 60 * 60) + (minutes * 60) + seconds);
}

// Fulfilling setTime requirement
bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
  normalize(static_cast<double>(hours), static_cast<double>(minutes), static_cast<double>(seconds));
  return true;
}

// Makes all numbers either positive or negative and keeps them between -60 and 60
void TimeSpan::normalize(double hours, double minutes, double seconds)
{
  int secondsPile = round((hours * 60 * 60) + (minutes * 60) + seconds);

  int remainingMinutes = secondsPile / 60;
  int finalSeconds = secondsPile % 60;
  int finalHours = remainingMinutes / 60;
  int finalMinutes = remainingMinutes % 60;

  this->hours = finalHours;
  this->minutes = finalMinutes;
  this->seconds = finalSeconds;
}

// Destructor
TimeSpan::~TimeSpan()
{
}

// Constructors
TimeSpan::TimeSpan()
{
  normalize(0, 0, 0);
}

TimeSpan::TimeSpan(double seconds)
{
  normalize(0, 0, static_cast<double>(seconds));
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
  normalize(0, static_cast<double>(minutes), static_cast<double>(seconds));
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
  normalize(static_cast<double>(hours), static_cast<double>(minutes), static_cast<double>(seconds));
}
