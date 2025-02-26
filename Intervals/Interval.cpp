/**************************************************
 * File: Interval.cpp                             *
 * Author: S. Blythe                              *
 * Date: 2/2024                                   *
 * Purpose: Implements an interval as use in      *
 *    greedy algorithm examples from CSC36000     *
 **************************************************/
#include "Interval.hpp"

using namespace std;

// output Interval by showing instance variables
ostream&
Interval::print(ostream &os) const
{
  os << _name;
  os << " [" << _start << ":" << _finish << "]";
  return os;
}

// output Interval by showing id and a "bar" 
ostream&
Interval::display(ostream &os) const
{
  // print ID (aligned to 4 spaces)
  os.width(4);
  os << _name << ":";

  // don't print bar until it starts
  for (int t=0; t<_start; t++) os << ' ';
  // print out bar, one '#' per unit of time
  for (int t=_start; t<_finish; t++) os << 'X';
  return os;
}

// overload << to print instance variables
ostream& operator<<(ostream &os, const Interval &job)
{
  job.print(os);
  return os;
}

// read an Interval from specified stream.
istream& operator>>(istream &is, Interval &job)
{
  is >> job._name;
  is >> job._start;
  is >> job._finish;

  return is;
}
