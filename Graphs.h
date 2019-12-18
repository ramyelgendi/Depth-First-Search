// File: Graphs.h
// Graph library header file for use with Asn#5
/*
______________________________________________________________________________________________

  This file describes a structure for a weighted undirected graph with a maximum of Vmax = 50 
  vertices and Emax = Vmax(Vmax-1)/2 edges. The verices are numbered 0,1,...V-1. The graph is
  assumed to be on a text file in the form of an adjacency matrix. The weights on the edges are
  assumed to be positive integers with zero weight indicating the absence of an edge. 
  An edge (u,v,w) existing between nodes (u) and (v) with weight (w) is modeled as a class
  (Edge). When loaded from the text file, the weights are stored in a  2-D 
  array (AdjMatrix) representing the adjacency matrix. Another  array (edges) stores 
  the non-zero edges in the graph. The functions declared here are needed to implement:

  (1) Depth First Search (DFS) algorithm for graph traversal.
  (2) Dijkstra's Algorithm to compute the shortest paths from a given source node to all other
      nodes in the graph.
_______________________________________________________________________________________________	
*/

#ifndef GRAPHS_H
#define GRAPHS_H
#include <string>
#include "Edge.h"
using namespace std;

const int Vmax = 50;					// Maximum number of vertices
const int Emax = Vmax*(Vmax-1)/2;		// Maximum number of edges

class Graphs
{
   public:
	
//_____________________________________
	// Member Functions
	// Class Constructor & Destructor
	Graphs();
	~Graphs();

// Function Prototypes___________________

    void getGraph(string fname);
	int  NoofVerices() const;		// Get number of vertices (V)
    int  NoofEdges();		// Get Number of Non-zero edges (E)
	void dispEdges() const;			// Display Graph edges
	void DFS();				// Depth First Search Traversal (DFS)
	void shortPath();			// Shortest paths from node (s)
//______________________________________________________________________________________________


   private:
	   
	   int V, E;				// No.of vertices (V) and edges (E)
    void printPath(int);
	   Edge edges[Emax];			// Array of non-zero edges
       int **AdjMatrix;
	   int order;				// Order of Visit of a node in the DFS
	   int val[Vmax];			// Array holding order of traversal of nodes in DFS
	   void getEdges();			// Get Non-Zero edges from adjacency matrix  
	   void printEdge(Edge e) const;	// Output an edge (e)
	   void visit(int k);			// Node Visit Function (needed for DFS)
};
#endif // GRAPHS_H
  
