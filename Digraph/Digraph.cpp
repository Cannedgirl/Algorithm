#include"Digraph.h"
#include<iostream>
#include<queue>
using namespace std;


Digraph::Digraph(int V, int E)
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
Digraph::~Digraph()
{
	for (int i = 0; i < numV; i++)
		delete[] adjMatrix[i];
	delete[] adjMatrix;
	
	delete[]AdjList;

	numE = 0;
	numV = 0;
}
void Digraph::addEdge(int v, int w)
{
	adjMatrix[v][w] = 1;
}
int Digraph::V()
{
	return numV;
}
int Digraph::E()
{
	return numE;
}

void Digraph::showGraph()
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

int* Digraph::adjMatrix_V(int v)
{
	return adjMatrix[v];
}
void Digraph::buildAdjList()
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
			edgeNode *p = AdjList[v].firstedge;
			while (p->next)
				p = p->next;
			e = new edgeNode;
			e->edge_v = w;
			e->next = NULL;
			p->next = e;
		}
		
	}
}

void Digraph::showAdjList()
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
				cout << "----->" << w;
				ptr = ptr->next;
			}
			cout << endl;
		}
	}
}

void Digraph::buildDepthFirstPaths(int s)
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

void Digraph::DFS(int v)
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

void Digraph::showDFPath()
{
	for (int i = 0; i < numV; i++)
		cout << i << " " << dfp.edgeTo[i] << endl;
}

void Digraph::buildBreadFirstPaths(int s)
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

void Digraph::showBFPath()
{
	for (int i = 0; i < numV; i++)
		cout << i << " " << bfp.edgeTo[i] << endl;
}

void Digraph::CC()
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

void Digraph::DFSCC(int v)
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

int Digraph::Count()
{
	return cc.count;
}
int Digraph::ID(int v)
{
	return cc.id[v];
}

void Digraph::getDepthFirstOrder()
{
	dfo.marked = new bool[numV];
	for (int i = 0; i < numV; i++)
		dfo.marked[i] = false;
	for (int i = 0; i < numV; i++)
	{
		if (!dfo.marked[i])
		{
			DFSDFO(i);
		}
	}
}

void Digraph::DFSDFO(int v)
{
	dfo.marked[v] = true;
	edgeNode *ptr = AdjList[v].firstedge;
	while (ptr)
	{
		int w = ptr->edge_v;
		if (!dfo.marked[w])
			DFSDFO(w);
		ptr = ptr->next;
	}
	dfo.reversePost.push(v);
}

void Digraph::getReversePost()
{
	stack<int> temp;
	while (!dfo.reversePost.empty())
	{
		int w = dfo.reversePost.top();
		cout << w << " ";
		temp.push(w);
		dfo.reversePost.pop();
	}
	cout << endl;
	while (!temp.empty())
	{
		dfo.reversePost.push(temp.top());
		temp.pop();
	}
}

void Digraph::Reverse(Digraph &rdigraph)
{
	rdigraph.AdjList = new adjList[numV];
	for (int i = 0; i < numV; i++)
	{
		rdigraph.AdjList[i].v = i;
		rdigraph.AdjList[i].firstedge = NULL;
	}
	for (int i = 0; i < numV; i++)
	{
		for (int j = 0; j < numV; j++)
		{
			if (adjMatrix[i][j] == 1)
			{
				rdigraph.adjMatrix[j][i] = 1;
				if (rdigraph.AdjList[j].firstedge == NULL)
				{
					edgeNode *e = new edgeNode;
					e->edge_v = i;
					e->next = NULL;
					rdigraph.AdjList[j].firstedge = e;
				}
				else
				{
					edgeNode *e = new edgeNode;
					e->edge_v = i;
					e->next = NULL;
					edgeNode *ptr = rdigraph.AdjList[j].firstedge;
					while (ptr->next)
						ptr = ptr->next;
					ptr->next = e;
				}
			}
	    }
	}
	
}

void Digraph::getSCC()
{
	scc.marked = new bool[numV];
	scc.id = new int[numV];
	scc.count = 0;
	Digraph rgraph(numV, numE);
	this->Reverse(rgraph);
	rgraph.showAdjList();
	rgraph.getDepthFirstOrder();
	rgraph.getReversePost();
	for (int i = 0; i < numV; i++)
	{
		scc.marked[i] = false;
		scc.id[i] = -1;
	}
	while (!rgraph.dfo.reversePost.empty())
	{
		int v = rgraph.dfo.reversePost.top();
		rgraph.dfo.reversePost.pop();
		if (!scc.marked[v])
		{
			scc.count++;
			DFSSCC(v);
			
		}
	}
	for (int i = 0; i < numV; i++)
	{
		cout << i << "----" << scc.id[i] << endl;
	}
}
 
void Digraph::DFSSCC( int v)
{
	scc.marked[v] = true;
	scc.id[v] = scc.count;
	edgeNode *ptr =AdjList[v].firstedge;
	while (ptr)
	{
		int w = ptr->edge_v;
		if (!scc.marked[w])
		{
			DFSSCC( w);
		}
		ptr = ptr->next;
	}

}