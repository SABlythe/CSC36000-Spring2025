/**************************************************
 * File: Classrooom.cpp                           *
 * Author: S. Blythe                              *
 * Date: 2/2024                                   *
 * Purpose: Implements an classroom as used in    *
 *    greedy algorithm examples from CSC36000     *
 **************************************************/
#include "Classroom.hpp"

using namespace std;

int __id=1; // id for next available classroom

ostream&
Classroom::print(ostream &os) const
{
  os << _id;
  os << " [" << _finish << "]";
  return os;
}

ostream& operator<<(ostream &os, const Classroom &cr)
{
  cr.print(os);
  return os;
}

istream& operator>>(istream &is, Classroom &cr)
{
  is >> cr._id;
  is >> cr._finish;

  return is;
}
