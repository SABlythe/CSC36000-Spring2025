#include "Stack.hpp"

#include "Stack.tpp"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  Stack<string> st;

  for (int index=1; index<argc; index++)
    {
      st.push(argv[index]);
    }

  while(!st.isEmpty())
    {
      cout << st.pop() << endl;
    }

  Stack<int> ints;
  for (int x = 1; x< 100; x+=7)
    ints.push(x);
  
  return 0;
}
