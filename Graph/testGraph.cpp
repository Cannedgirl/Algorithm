#include "Graph.h"
using namespace std;

int main()
{
  int V,E;
  cin>>V>>E;
  Graph graph(V,E);   
  
  //build up adjacency-matrix
  int i,v,w;
  for (i = 0; i < E; i++)
	{
		cin >> v >> w;
		graph.addEdge(v, w);
	}
  graph.showGraph();
  cin>>i;
  graph.adjMatrix_V(i);
  
  
  //build up adjacency-lists
  graph.buildAdjList();
  graph.showAdjList();
  
  //test DFS
  int s;
  cin>>s;
  graph.buildDepthFirstPaths(s);
  graph.showDFPath();
  
  //test BFS
  graph.buildDepthFirstPaths(s);
  graph.showBFPath();
  
  //test CC
  graph.CC();
  for (int i = 0; i < graph.V(); i++)
    cout << i << " " << graph.ID(i) << endl;
}
