//
//  Sets.hpp
//  BONUSass
//
//  Created by Aya Shabrawi on 12/13/18.
//  Copyright © 2018 Aya Shabrawi. All rights reserved.
//

#ifndef Sets_hpp
#define Sets_hpp

#include <stdio.h>

class Sets
{
private:
    int *p;
    int *c;
    int n;
public:
    Sets(int Size)     // Constructor
    {
        n = Size;
        p=new int[n-1];
        c=new int[n-1];
    
        for (int i = 0; i <n; i++)
        {
            p[i] = -1;
            c[i] = 1; }
    }
    
    ~Sets()
    {
        delete []p;
        delete []c;
    }
    
    void SimpleUnion(int i, int j);
    int SimpleFind(int i);
};


#endif /* Sets_hpp */
