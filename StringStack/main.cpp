#include "StringStack.hpp"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  StringStack st;

  for (int index=1; index<argc; index++)
    {
      st.push(argv[index]);
    }

  while(!st.isEmpty())
    {
      cout << st.pop() << endl;
    }
  
  return 0;
}
