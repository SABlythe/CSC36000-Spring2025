/**************************************************
 * File: GenericHeap.tpp                          *
 * Author: S. Blythe                              *
 * Date: 2/2024                                   *
 * Purpose: Implements a templated heap           *
 *                                                *
 * NOTE: Since this is a templated class you      *
 *      likely want to #include "GenericHeap.tpp" *
 **************************************************/
#include "GenericHeap.hpp"

// add to the heap
template <class T>
bool
GenericHeap<T>::add(const T &newVal)
{
  // if there's no room left, add will fail
  if (_lastIndex==_size)
    return false;

  // one more item
  _lastIndex++;

  // put value in next empty slot
  _values[_lastIndex]=newVal;

  // move new value up the heap as far as it will go. 
  upHeap(_lastIndex);
  return true;
}

// removing min ... 
template <class T>
T
GenericHeap<T>::removeMin()
{
  // min is at top of heap
  T mval = _values[1];

  // put last element in vacated spot ...
  _values[1] = _values[_lastIndex];
  _lastIndex--;

  // ... and push that value down as far is it will go ... 
  downHeap(1);
  return mval;
}

// move value up as far as it will go ....
template <class T>
void
GenericHeap<T>::upHeap(int fromIndex)
{
  // as long as not at root and value should be moved up ...
  while (parent(fromIndex)!=0 && _values[fromIndex]<_values[parent(fromIndex)])
    {
      // swap offending elements
      T temp =_values[fromIndex];
      _values[fromIndex]=_values[parent(fromIndex)];
      _values[parent(fromIndex)] = temp;

      // check next level up ...
      fromIndex = parent(fromIndex);
    }
}

// move value down as far as it will go ....
template <class T>
void
GenericHeap<T>::downHeap(int fromIndex)
{
  bool movedDown;
  
  do{
    // we have not yet succeeded in moving anything down the heap
    movedDown=false;

    // basic idea: find min of yourself and your children ...
    //   ... start by assuming minimum is yourself
    int minIndex=fromIndex;
    
    //   ... then update minimum to be left child if appropriate
    if (left(fromIndex) <= _lastIndex &&  // do I even have a left child?
	_values[left(fromIndex)]< _values[minIndex])
      minIndex = left(fromIndex);

    //   ... then update minimum to be right child if appropriate
    if (right(fromIndex) <= _lastIndex && // do I even have a right child?
	_values[right(fromIndex)]< _values[minIndex])
      minIndex = right(fromIndex);

    // if I am not the minimum index, then we do need a downheap step
    if (minIndex!=fromIndex)
      {
        // perform corresponding swap
	T temp = _values[fromIndex];
	_values[fromIndex]=_values[minIndex];
	_values[minIndex]=temp;

        // move down heap in next pass through loop
        fromIndex=minIndex;
	movedDown=true;
      }
  }
  while(movedDown); // keep going as long as we did actually move down heap
}
