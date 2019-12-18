//  PQ.cpp
//  GROUPASS6.cpp
//   Aya Shabrawi, Iman Yehia, Nourhan Mokbel
#include<iostream>
#include "PQ.hpp"
#include <cmath>
#include <iomanip>
using namespace std;

// Member Functions

// Constructor with argument. Max size is mVal elements
// not including a[0] which will receive -32767
// The constructor creates the heap array, initializes
// the end of the heap to N=0,and itmMin
PQ::PQ(int mVal)
{
    MaxSize = mVal;
    a = new Edge[MaxSize + 1];
    N = 0;
    itemMin.u= -1;
    itemMin.v = -1;
    itemMin.w = -1;
    a[0] = itemMin;
}
PQ::~PQ()
{
    delete[] a;
}

bool PQ::ISEMPTY()
{
    if(N==0)
        return true;
    else
        return false;
}

void PQ::upheap(int k)
{
    Edge v = a[k];
    while (a[k / 2].w >= v.w)
    {
        a[k] = a[k / 2];   k = k / 2;
    }
    a[k] = v;
}


void PQ::downheap(int k)
{
    int j = 2 * k;     Edge v = a[k];
    while (j <= N) {
        if ((j < N) && (a[j].w > a[j + 1].w)) j++;
        if (v.w <= a[j].w) break;
        a[j / 2] = a[j];     j *= 2;
    }
    a[j / 2] = v;
}


void PQ::insert(Edge v)
{
    a[++N] = v;    upheap(N);
}


Edge PQ::remove()
{
    Edge v = a[1];
    a[1] = a[N--];
    downheap(1);
    return v;
}


