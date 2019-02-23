#pragma once
#include<vector>
#include "Structure.h"
using namespace std;

class Graph
{
private:
	int numV; 
	int numE;
	int **adjMatrix; //ÁÚ½Ó¾ØÕó
	adjList *AdjList;  //ÁÚ½Ó±í
	DepthFirstPaths dfp;
	BreadthFirstPaths bfp;
	ConnectedComponents cc;
public:
	Graph(int V,int E);
	~Graph();
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
	void DFSCC(int v);
	void CC();
	int Count();
	int ID(int v);

};

