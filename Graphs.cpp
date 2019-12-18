// FILE: graphs.cpp
// Graph Library Implementation File
// You should complete the implementation for some of the functions

#include <fstream>		// For reading file from disk
#include <iostream>
#include <string>		// For file name
#include <iomanip>
#include "Edge.h"		// Deinition of an Edge
#include "Graphs.h"
#include "PQ.hpp"
#include "Sets.hpp"

using namespace std;
int order=0;
Edge MST[20];
int val[100];
int E;

// Constructor
Graphs::Graphs()
{
	E = V = order = 0;
}

// Destructor
Graphs::~Graphs()
{
}

void Graphs::getGraph(string fname)
{

ifstream in;
in.open("/Users/shabrawi/Desktop/Gam3aa /BONUSass/BONUSass/TestG.txt");
if (in.fail())
cout << "Error, Cannot Read File" << endl;

    if(in.is_open())
    {  in >> V;
        AdjMatrix = new int*[V];
        for (int i = 0; i < V; i++)
            AdjMatrix[i] = new int[V];
        
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                in >> AdjMatrix[i][j];
    }
      in.close();
    int i,j;
    cout<<"Adjacency Matrix\n";
    
    for(i=0; i<V; i++)
    {
        for(j=0; j<V; j++)
            cout<<AdjMatrix[i][j]<<" ";
        cout<< endl;
    }

}

// Get Non-Zero edges from adjacency matrix
//store in array Edges which is of the class edge
void Graphs::getEdges()			
{
	int i = 0;
	for (int r = 0; r <= V-2; r++)
		for (int c = r+1; c <= V-1; c++)
		{
			int w = AdjMatrix[r][c];
			if (w > 0)
            {
               //Save both vertices and weight in Edge of [i]
                edges[i].u = r;
                edges[i].v = c;
                edges[i].w = w;
                i++;
            }
		}

	E = i; //Number of Weighted Edges
	
}

// Get number of vertices (V)	
int Graphs::NoofVerices() const
{
	return V;
}

// Get Number of Non-zero edges (E)
int Graphs::NoofEdges()
{
    getEdges();
    return E;
}

// Output an edge (e): Vertex names and weight
void Graphs::printEdge(Edge e) const 			
{
        char v= static_cast<char>('A' + e.v);
        char u= static_cast<char>('A' + e.u);
        cout << v << " " << u << " " << e.w << endl;
}

// Display Graph Edges
void Graphs::dispEdges() const
{
	cout<<"Graph Edges";
	for (int i = 0; i < E; i++) 
		printEdge(edges[i]);
}

// Shortest paths between nodes
void Graphs::shortPath()
{
    PQ H(E);
    for(int i=0;i<E;i++)
    {
        Edge v=edges[i];
        H.insert(v);
    }
   int k = 0 ;
   Sets s(E);
   while ((k < E) && (!H.ISEMPTY()))
   {
      Edge R= H.remove();
       int i=s.SimpleFind(R.u);
       int j=s.SimpleFind(R.v);

       if(j!=i)
        {
            s.SimpleUnion(i,j);
            k++;
            MST[k].u = R.u;
            MST[k].v = R.v;
            MST[k].w = R.w;
         
        }
       
    }
    printPath(k);
}

// Print shortest edges (vertex names) and weight
void Graphs::printPath(int k)
{
    cout<<"Shortest Path\n";
    int cost=0;
    for(int i=0;i<=k;i++)
    {
        char v= static_cast<char>('A' + MST[i].v);
        char u= static_cast<char>('A' + MST[i].u);
        cout<<MST[i].w<<" "<<u<<","<<v<<endl;
        cost+=MST[i].w;
    }
    cout<<"Minimum cost is"<<cost<<endl;
}

// Node Visit Function
void Graphs::visit(int j)
{
    val[j] = ++order;
    char l= static_cast<char>('A' + j);
    cout<<l<<",";
    for (int t = 1; t <= V; t++)
        if (AdjMatrix[j][t] != 0)
            if (val[t] == -1)
            {
                visit(t);
            }
}

// Depth First Search Traversal
void Graphs::DFS()									
{
    // Initialize all to unseen
    for(int i=0;i<V;i++)
        val[i] = -1;
    // Follow Nodes in Depth
    for( int j=0;j<V;j++)
        if (val[j] == -1)
            visit(j);
            
}


