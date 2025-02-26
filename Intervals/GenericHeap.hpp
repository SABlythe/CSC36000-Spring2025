/**************************************************
 * File: GenericHeap.hpp                          *
 * Author: S. Blythe                              *
 * Date: 2/2024                                   *
 * Purpose: Implements a templated heap           *
 *                                                *
 * NOTE: Since this is a templated class you      *
 *      likely want to #include "GenericHeap.tpp" *
 **************************************************/
#ifndef _GENERIC_HEAP_HPP_
#define _GENERIC_HEAP_HPP_

template <class T> class GenericHeap
{
private:
  T *_values;     // actual data stored in heap
  int _lastIndex; // index of last item in heap
  int _size;      // largest number of values heap can hold
public:
  // constructor. 
  GenericHeap(int size) : _values(new T[size+1]), _lastIndex(0), _size(size) {}

  // add element to heap. 
  bool add(const T &newVal);

  // remove minimum element from heap
  T removeMin();

  // look at, but do NOT remove minimum element from heap
  T& peekMin() {return _values[1];}

  // gives unerlying array found in heap. nto likely to be useful.
  T* contents() const {return _values;}

  // how many elements are in the heap? 
  int numValues() const {return _lastIndex;}
  int lastIndex() const {return _lastIndex;}

  // haw many elements can the heap hold (maximum)
  int size() const {return _size;}

  // is the heap empty? 
  bool isEmpty() const {return _lastIndex==0;}

  // move a value as far up the heap as it can go. 
  //   note that the parameter is the *index* of the value to upheap
  void upHeap(int fromIndex);

  //move a value down the heap. Again the parameter is the INDEX. 
  void downHeap(int fromIndex=1); // if not specified, downHeap from "root"

private: // you should likely never need to call these!!!

  int parent(int index) {return index/2;}    //give parent index of node
  int left(int index) {return 2*index;}      // give left child index of node
  int right(int index) {return 2*index + 1;} // give right child index of node
  
};
#endif
