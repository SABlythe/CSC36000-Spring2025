#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <list>

template <class T>
class Stack: private std::list<T>
{
public:
  Stack() {} // automatically calls list<String> constructor

  void push(const T  &s);
  T pop();
  const T top() const;
  bool isEmpty() const;
};


#endif
