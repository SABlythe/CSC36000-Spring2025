#include <iostream>

using namespace std;

#define UNKNOWN -1

long long int *M; // "memo-ized" array of already calculated answers

long long int fibo(int seqNum)
{
  if (M[seqNum] == UNKNOWN)
    {
      // fill in M[seqNum] ... 
      if (seqNum<=1)
	M[seqNum] =1 ; //return 1;
      else
	M[seqNum] = fibo(seqNum-1) + fibo(seqNum-2);
    }

  return M[seqNum];
  

}

int main(int argc, char *argv[])
{
  int snum = stoi(argv[1]);

  // make one slot for every answer that will be calculated
  M = new long long int[snum+1];
  for (int s = 0; s<=snum; s++)
    M[s] = UNKNOWN;

  fibo(snum);
  cout << M[snum] << endl; 
  //cout << fibo(snum) << endl;
  return 0;
}
