/**************************************************
 * File: Interval.hpp                             *
 * Author: S. Blythe                              *
 * Date: 2/2024                                   *
 * Purpose: Implements an interval as use in      *
 *    greedy algorithm examples from CSC36000     *
 **************************************************/
#ifndef _INTERVAL_HPP_
#define _INTERVAL_HPP_

#include <iostream>

class Interval
{
private:
  std::string _name;  // identifier for an interval
  int _start;         // interval start time
  int _finish;        // interval finish(end) time
public:
  // constructors. 
  Interval(): _name(), _start(0), _finish(0) {} 
  Interval(const std::string &name, int startTime, int endTime)
    : _name(name), _start(startTime), _finish(endTime){}

  // accessors 
  int start() const {return _start;}
  int finish() const {return _finish;}
  const std::string& name() const {return _name;}

  // two options for oututting a stream
  //   print - outputs the actual privtae field values
  std::ostream &print(std::ostream &os=std::cout) const;
  //   dispaly - outputs name and then dispplays interval as a bar
  std::ostream &display(std::ostream &os=std::cout) const;

  // overloaded I/O operators
  friend std::ostream&  operator<< (std::ostream &os, const Interval &iv);
  friend std::istream&  operator>> (std::istream &os, Interval &iv); 
};

#endif
