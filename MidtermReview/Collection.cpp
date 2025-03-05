#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
  set<int> mySet;
  
  for (int i=1; i<argc; i++)
    {
      mySet.insert(stoi(argv[i]));
    }
  
  for (int element: mySet)
    cout << element << endl;

  for (set<int>::iterator derek = mySet.begin();
       derek!=mySet.end();
       derek++)
    {
      cout << *derek << endl;
    }
  
  return 0;
}
