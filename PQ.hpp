//
//  PQ.hpp
//  GROUPASS6.cpp
//   Aya Shabrawi, Iman Yehia, Nourhan Mokbel

#ifndef PQ_hpp
#define PQ_hpp

#include <stdio.h>
#include <string>
#include "Edge.h"

class PQ
{
public:
    
    // Class Constructor with input size parameter
    PQ(int);
    // Class Destructor
    ~PQ();
    // Member Functions
    void insert(Edge e);    // insert element into heap
    Edge remove();            // remove & return the top of the heap
    bool ISEMPTY();
    
private:
    // Pointer to Storage Array
    Edge *a;
    // Maximum Size (not including a[0])
    int MaxSize;
    int N;                    // index of last element in the array
    Edge itemMin;                // itemMin to be stored in a[0]
    // Heap Adjustment Functions
    void upheap(int k);
    void downheap(int k);
};
#endif // PQ_H
