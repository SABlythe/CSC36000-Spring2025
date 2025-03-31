#include <iostream>

using namespace std;

long long int fibo(int seqNum)
{
  if (seqNum<=1)
    return 1;

  return fibo(seqNum-1) + fibo(seqNum-2);
}

int main(int argc, char *argv[])
{
  int snum = stoi(argv[1]);
  cout << fibo(snum) << endl;
  return 0;
}
