#include "Stack.hpp"

using namespace std;

template <class T>
void
Stack<T>::push(const T &s)
{
  list<T>::push_front(s);
}

template <class T>
T
Stack<T>::pop()
{
  T hold = top();
  list<T>::pop_front();
  return hold;
}

template <class T>
const T
Stack<T>::top() const
{
  return list<T>::front();
}

template <class T>
bool
Stack<T>::isEmpty() const
{
  return list<T>::empty();
}
