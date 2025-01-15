#include <iostream>

using namespace std;

string addArgs(char *arr[], int nels)
{
  string sum="";
  
  for (int index=1; index < nels; index++)
    sum += arr[index];

  return sum;
}

int addArgs(int nels, char *arr[])
{
  int sum=0;
  
  for (int index=1; index < nels; index++)
    sum += stoi(arr[index]);

  return sum;
}



int main(int argc, char* argv[])
{
  cout << "Hello World" << endl;

  /*
  for (int index=1; index < argc; index++)
    sum += stoi(argv[index]);
    //cout << argv[index] << endl;
    */
  
  cout << "Total string sum is:" << addArgs(argv, argc) << endl;
  cout << "Total int sum is:" << addArgs(argc, argv) << endl;
  
  return 0;
}
