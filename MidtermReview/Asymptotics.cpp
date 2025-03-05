#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int n = stoi(argv[1]);

  int count =0;
  int x = rand();

  if ( n==x) 
    {
      for (int i=n; i>=1; i/=2)
	{

	  //for (int j=0; j<i; j++)
	  //if ( i==x) 
	  {

	    count ++;
	  }
	}
    }
  cout << count << endl;
}
