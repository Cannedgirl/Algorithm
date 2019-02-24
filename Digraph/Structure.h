#pragma once
#include<stack>
using namespace std;
struct edgeNode
{
	int edge_v;
	edgeNode *next;
};  

struct adjList
{
	int v;
	edgeNode *firstedge;
}; 

struct DepthFirstPaths
{
	bool  *marked; //if v is visited,marked[v]=true;
	int   *edgeTo;
	int   sourse;
};

struct BreadthFirstPaths
{
	bool *marked;
	int *edgeTo;
};

struct ConnectedComponents
{
	int count;
	bool *marked;
	int *id;
};

struct DepthFirstOrder
{
	bool *marked;
	stack<int> reversePost;
};

//strongly connected components
struct KosarajuSharirSCC
{
	bool *marked;
	int * id;
	int count;
};
