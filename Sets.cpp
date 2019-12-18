//
//  Sets.cpp
//  BONUSass
//  Created by Aya Shabrawi on 12/13/18.
//  Copyright © 2018 Aya Shabrawi. All rights reserved.

#include "Sets.hpp"
#include <iostream>
using namespace std;

// Make a union between set(i) and set(j)
void Sets::SimpleUnion(int i, int j)
{
    int sum = c[i] + c[j];
    if (c[i] > c[j]) { p[j] = i; c[i] = sum; }
    else { p[i] = j; c[j] = sum; }
}


// Find the parent set of subset(i)
int Sets::SimpleFind(int i)
{
    while (p[i] >= 0) i = p[i];
    return i;
}
