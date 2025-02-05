#include "StringStack.hpp"

using namespace std;

void
StringStack::push(const string &s)
{
  push_front(s);
}

string
StringStack::pop()
{
  string hold = top();
  pop_front();
  return hold;
}

const string&
StringStack::top() const
{
  return front();
}

bool
StringStack::isEmpty() const
{
  return empty();
}
