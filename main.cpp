//  main.cpp
//  BONUSass
//  Created by Aya Shabrawi on 12/5/18.
//  Copyright © 2018 Aya Shabrawi. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Graphs.h"
#include "Edge.h"
using namespace std;

int main()
{

    string fname;
    cout<<"Paving Problem"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"Enter the File of Cities"<<endl;
    cin>>fname;
    Graphs G;
    G.getGraph(fname);
    cout<<endl;
    int v=G.NoofVerices();
    cout<<"Number of Vertices is: "<<v<<endl;
    cout<<endl;
    int e=G.NoofEdges();
    cout<<"Number of Edges is: "<<e<<endl;
    cout<<endl;
    G.dispEdges();
    cout<<endl;
    cout<<"DFS Traversal Order starting from  node (A):"<<endl;
    G.DFS();
    cout<<endl;
    cout<<"Shortest Path from node (A):"<<endl;
    G.shortPath();
}


