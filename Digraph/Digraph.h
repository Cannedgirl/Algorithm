#pragma once
#include "Structure.h"

class Digraph
{
private:
	int numV;
	int numE;
	int **adjMatrix; //ÁÚ½Ó¾ØÕó
	adjList *AdjList;  //ÁÚ½Ó±í
	DepthFirstPaths dfp;
	BreadthFirstPaths bfp;
	ConnectedComponents cc;
	DepthFirstOrder dfo;
	KosarajuSharirSCC scc;
public:
	Digraph(int V, int E);
	~Digraph();
	void buildAdjList();
	void addEdge(int v, int w);
	int V();
	int E();
	int *adjMatrix_V(int v);  //vertex V's adjacent vertices
	void showGraph();
	void showAdjList();
	void DFS(int v);
	void buildDepthFirstPaths(int s);
	void showDFPath();
	void buildBreadFirstPaths(int s);
	void showBFPath();
	void DFSCC(int v); //DFS for ConnectedComponents
	void CC();
	int Count();
	int ID(int v);
	void getDepthFirstOrder();
	void DFSDFO(int v); //DFS for DepthFirstOrder
	void getReversePost();
	void Reverse(Digraph &rdigraph);// v->w change to w->v
	void getSCC();
	void DFSSCC(int v);//DFS for StronglyConnectedComponents
	
};