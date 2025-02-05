#ifndef _STRING_STACK_HPP_
#define _STRING_STACK_HPP_

#include <list>
#include <string>

class StringStack: private std::list<std::string>
{
public:
  StringStack(); // automatically calls list<String> constructor

  void push(const std::string &s);
  std::string pop();
  const std::string& top() const;
  bool isEmpty() const;
};


#endif
