#include "Classroom.hpp"
#include "Interval.hpp"

#include "GenericHeap.tpp"

#include <fstream>
#include <list>

using namespace std;


#define MAX_CLASSROOMS 500
int main(int argc, char *argv[])
{
  GenericHeap<Classroom> classrooms(MAX_CLASSROOMS);
  list<Interval> classes;

  ifstream ifile(argv[1]);

  Interval lecture;
  ifile >> lecture;

  while(ifile)
    {
      classes.push_back(lecture);
      
      ifile >> lecture;
    }

  for(Interval c:classes)
    cout << c << endl;
  
  return 0;
}
