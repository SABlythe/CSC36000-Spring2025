/**************************************************
 * File: Classrooom.hpp                           *
 * Author: S. Blythe                              *
 * Date: 2/2024                                   *
 * Purpose: Implements an classroom as used in    *
 *    greedy algorithm examples from CSC36000     *
 **************************************************/
#ifndef _CLASSROOM_HPP_
#define _CLASSROOM_HPP_

#include <iostream>

extern int __id; // if for next available classroom

class Classroom
{
private:
  int _id;      // unique id (number) for a classroom
  int _finish;  // current finish time of last lecture in this classroom
public:
  // constructors
  Classroom(): _id(-1), _finish(-1) {} 
  Classroom(int endTime)
    : _id(__id++), _finish(endTime){}
  Classroom(int id, int endTime)
    : _id(id), _finish(endTime){}

  // accessors
  int finish() const {return _finish;}
  int id() const {return _id;}

  // modifier
  int& finish() {return _finish;}
  
  // overloaded < - usefull for heap ... 
  bool operator<(const Classroom &cr) const {return _finish<cr._finish;}

  std::ostream &print(std::ostream &os) const;

  friend std::ostream&  operator<< (std::ostream &os, const Classroom &cr);
  friend std::istream&  operator>> (std::istream &os, Classroom &cr); 
};

#endif
