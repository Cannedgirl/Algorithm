#include "Graph.h"
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
Graph::Graph(int V,int E)
{
	numV = V;
	numE = E;
	adjMatrix = new int*[numV];
	for (int i = 0; i < numV; i++)
		adjMatrix[i] = new int[numV];
	for (int i = 0; i < numV; i++)
		for (int j = 0; j < numV; j++)
			adjMatrix[i][j] = 0;
}
Graph::~Graph()
{
	for (int i = 0; i < numV; i++)
		delete[] adjMatrix[i];
	delete[] adjMatrix;

	delete[]AdjList;

	numE = 0;
	numV = 0;
}
void Graph::addEdge(int w, int v)
{
	adjMatrix[w][v] = 1;
	adjMatrix[v][w] = 1;
}
int Graph::V()
{
	return numV;
}
int Graph::E()
{
	return numE;
}

void Graph::showGraph()
{
	for (int i = 0; i < numV; i++)
	{
		for (int j = 0; j < numV; j++)
		{
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

int* Graph::adjMatrix_V(int v)
{
	return adjMatrix[v];
}
void Graph::buildAdjList()
{
	AdjList = new adjList[numV];
	for (int i = 0; i < numV; i++)
	{
		AdjList[i].v = i;
		AdjList[i].firstedge = NULL;
	}
	int v, w;
	edgeNode *e;
	
	for (int j = 0; j < numE; j++)
	{
		cin >> v >> w;
		if (AdjList[v].firstedge == NULL)
		{
			e = new edgeNode;
			e->edge_v = w;
			e->next = NULL;
			AdjList[v].firstedge = e;
		}
		else
		{
			edgeNode *p  = AdjList[v].firstedge;
			while (p->next)
				p = p->next;
			e = new edgeNode;
			e->edge_v = w;
			e->next = NULL;
			p->next = e;
		}
		if (AdjList[w].firstedge == NULL)
		{
			e = new edgeNode;
			e->edge_v = v;
			e->next = NULL;
			AdjList[w].firstedge = e;
		}
		else
		{
			edgeNode *p = AdjList[w].firstedge;
			while (p->next)
				p = p->next;
			e = new edgeNode;
			e->edge_v = v;
			e->next = NULL;
			p->next = e;
		}
	}
}

void Graph::showAdjList()
{
	for (int i = 0; i < numV; i++)
	{
		if (AdjList[i].firstedge == NULL)
			cout << AdjList[i].v << endl;
		else
		{
			cout << AdjList[i].v << endl;
			edgeNode *ptr = AdjList[i].firstedge;
			int w;
			while (ptr)
			{
				w = ptr->edge_v;
				cout <<  "----->" << w  ;
				ptr = ptr->next;
			}
			cout << endl;
		}
	}
}

void Graph::buildDepthFirstPaths(int s)
{
	dfp.marked = new bool[numV];
	for (int i = 0; i < numV; i++)
	{
		dfp.marked[i] = false;
	}
	dfp.edgeTo = new int[numV];
	for (int i = 0; i < numV; i++)
	{
		dfp.edgeTo[i] = -2;
	}
	dfp.sourse = s;
	dfp.edgeTo[s] = -1;
	DFS(s);
}

void Graph::DFS(int v)
{
	dfp.marked[v] = true;
	edgeNode *ptr = AdjList[v].firstedge;
	if (!ptr)
	{
		return;
	}
	
	while (ptr)
	{
		int w = ptr->edge_v;
		if (!dfp.marked[w])
		{
			dfp.edgeTo[w] = v;
			DFS(w);
		}
		ptr = ptr->next;
	}
}

void Graph::showDFPath()
{
	for (int i=0; i < numV; i++)
		cout << i << " " << dfp.edgeTo[i] << endl;
}

void Graph::buildBreadFirstPaths(int s)
{
	bfp.marked = new bool[numV];
	for (int i = 0; i < numV; i++)
		bfp.marked[i] = false;
	bfp.edgeTo = new int[numV];
	for (int i = 0; i < numV; i++)
		bfp.edgeTo[i] = -2;
	queue<int> q;
	q.push(s);
	bfp.edgeTo[s] = -1;
	bfp.marked[s] = true;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();
		edgeNode *ptr = AdjList[front].firstedge;
		while (ptr)
		{
			int w = ptr->edge_v;
			if (!bfp.marked[w])
			{
				bfp.marked[w] = true;
				bfp.edgeTo[w] = front;
				q.push(w);
			}
			ptr = ptr->next;
		}
	}
}

void Graph::showBFPath()
{
	for (int i = 0; i < numV; i++)
		cout << i << " " << bfp.edgeTo[i] << endl;
}

void Graph::CC()
{
	cc.marked = new bool[numV];
	for (int i = 0; i < numV; i++)
		cc.marked[i] = false;
	cc.count = 0;
	cc.id = new int[numV];
	for (int i = 0; i < numV; i++)
		cc.id[i] = cc.count;
	for (int i = 0; i < numV; i++)
	{
		if (!cc.marked[i])
		{
			cc.count++;
			DFSCC(i);
		}
	}
}

void Graph::DFSCC(int v)
{
	cc.marked[v] = true;
	cc.id[v] = cc.count;
	edgeNode *ptr = AdjList[v].firstedge;
	while (ptr)
	{
		int w = ptr->edge_v;
		if (!cc.marked[w])
			DFSCC(w);
		ptr = ptr->next; //!!!
	}
}

int Graph::Count()
{
	return cc.count;
}
int Graph::ID(int v)
{
	return cc.id[v];
}
