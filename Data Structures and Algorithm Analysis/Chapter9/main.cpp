#include <iostream>
#include <vector>
#include <queue>
#include <limits>  
#include "Binaryheap.h"
#include <algorithm>
#include <list>

using namespace std;


//class Vertex
//{
//public:
//	int indegree;
//	int topNum;
//	std::vector<Vertex*> adj;
//	Vertex(): indegree(0), topNum(0) {}
//	void addAdj(Vertex& v) { 
//		adj.push_back(&v); 
//	}
//};
//
//class Graph
//{
//public:
//	int numVertex;
//	Vertex* begin;
//	Graph(int num = 0) : numVertex(num), begin(new Vertex[num]) {}
//	~Graph() { delete [] begin; }
//	Vertex& operator[](int n) {
//		return *(begin + n);
//	}
//	const Vertex& operator[](int n) const {
//		return *(begin + n);
//	}
//	void addAdj(int v1, int v2) {
//		(begin + v1)->addAdj(*(begin + v2));
//		++((begin + v2)->indegree);
//	}
//	int size() const { return numVertex; }
//};
//
//void topSort(Graph& graph)
//{
//	queue<Vertex*> q;
//	int counter = 0;
//
//	for (int i = 0; i < graph.size(); ++i) {
//		if (graph[i].indegree == 0)
//			q.push(&graph[i]);
//	}
//
//	while (!q.empty()) {
//		Vertex* v = q.front();
//		q.pop();
//		v->topNum = ++counter;
//		cout << (v - graph.begin) + 1 << " ";
//		
//		for (auto &c : v->adj) {
//			if (--(c->indegree) == 0)
//				q.push(c);
//		}
//	}
//}
//
//int main()
//{
//	Graph graph(7);
//	graph.addAdj(0, 1);
//	graph.addAdj(0, 2);
//	graph.addAdj(0, 3);
//	graph.addAdj(1, 3);
//	graph.addAdj(1, 4);
//	graph.addAdj(2, 5);
//	graph.addAdj(3, 2);
//	graph.addAdj(3, 5);
//	graph.addAdj(3, 6);
//	graph.addAdj(4, 3);
//	graph.addAdj(4, 6);
//	graph.addAdj(6, 5);
//	topSort(graph);
//	return 0;
//}
 
//class Vertex
//{
//public:
//	bool known;
//	bool in;
//	int dist;
//	std::vector<Vertex*> adj;
//	std::vector<int> cvw;
//	Vertex* path;
//	Vertex() : known(false), in(false), dist((numeric_limits<int>::max)()) {}
//	bool operator<(const Vertex & v) { return this->dist < v.dist; }
//	void addAdj(Vertex& v, int d) { 
//		adj.push_back(&v); 
//		cvw.push_back(d);
//	}
//};
//
//class Graph
//{
//public:
//	int numVertex;
//	Vertex* begin;
//	Graph(int num = 0) : numVertex(num), begin(new Vertex[num]) {}
//	~Graph() { delete [] begin; }
//	Vertex& operator[](int n) {
//		return *(begin + n);
//	}
//	const Vertex& operator[](int n) const {
//		return *(begin + n);
//	}
//	void addAdj(int v1, int v2, int d) {
//		(begin + v1)->addAdj(*(begin + v2), d);
//	}
//};
//
//void sort(vector<Vertex*> &heap, Vertex* v)
//{
//	size_t i = 0;
//	for (; i < heap.size(); ++i) {
//		if (heap[i] == v)
//			break;
//	}
//	size_t j = i;
//	for (; j < heap.size() - 1; ++j) {
//		if (heap[j + 1]->dist > v->dist)
//			heap[j] = heap[j + 1];
//		else {
//			heap[j] = v;
//			break;
//		}
//	}
//	if (j == heap.size() - 1) heap[heap.size() - 1] = v;
//}
//
//void sort(vector<Vertex*> &heap)
//{
//	size_t j = heap.size() - 1;
//	Vertex* tmp = heap[heap.size() - 1];
//	for (; j > 0; --j) {
//		if (heap[j - 1]->dist < tmp->dist)
//			heap[j] = heap[j - 1];
//		else {
//			heap[j] = tmp;
//			break;
//		}
//	}
//	if (j == 0) heap[0] = tmp;
//}
//
//void dijkstra(Graph &graph, int vertex)
//{
//	graph[vertex].dist = 0;
//	graph[vertex].known = true;
//	vector<Vertex*> heap;
//	heap.push_back(&graph[vertex]);
//
//	while (true) {
//		if (heap.empty()) break; 
//		Vertex& v = *heap.back();
//		v.known = true;
//		v.in = false;
//		heap.pop_back();
//		for (size_t i = 0; i < v.adj.size(); ++i) {
//			if (!(v.adj[i]->known)) {
//				if (v.dist + v.cvw[i] < v.adj[i]->dist) {
//					v.adj[i]->dist = v.dist + v.cvw[i];
//					v.adj[i]->path = &v;
//					if (!(v.adj[i]->in)) {
//						v.adj[i]->in = true;
//						heap.push_back(v.adj[i]);
//						sort(heap);
//					} else 
//						sort(heap, v.adj[i]);
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	Graph graph(7);
//	graph.addAdj(0, 1, 2);
//	graph.addAdj(0, 3, 1);
//	graph.addAdj(1, 3, 3);
//	graph.addAdj(1, 4, 10);
//	graph.addAdj(2, 0, 4);
//	graph.addAdj(2, 5, 5);
//	graph.addAdj(3, 2, 2);
//	graph.addAdj(3, 4, 2);
//	graph.addAdj(3, 5, 8);
//	graph.addAdj(3, 6, 4);
//	graph.addAdj(4, 6, 6);
//	graph.addAdj(6, 5, 1);
//	dijkstra(graph, 0);
//	for (int i = 0; i < graph.numVertex; ++i) {
//		cout << i + 1 << ":" << graph[i].dist << ends;
//	}
//	return 0;
//}


// 9.27
//class Vertex
//{
//public:
//	bool known;
//	int num;
//	std::vector<Vertex*> adj;
//	Vertex* path;
//	Vertex() : known(false), num(0), path(nullptr) {}
//	bool operator<(const Vertex & v) { return this->num < v.num; }
//	void addAdj(Vertex& v) { adj.push_back(&v); }
//};
//
//class Graph
//{
//public:
//	int numVertex;
//	Vertex* begin;
//	Graph(int num = 0) : numVertex(num), begin(new Vertex[num]) {}
//	~Graph() { delete [] begin; }
//	Vertex& operator[](int n) {
//		return *(begin + n);
//	}
//	const Vertex& operator[](int n) const {
//		return *(begin + n);
//	}
//	void addAdj(int v1, int v2) {
//		(begin + v1)->addAdj(*(begin + v2));
//	}
//};
//
//void dfs1(Vertex &vertex)
//{
//	static int counter = 0;
//	vertex.known = true;
//	for (auto &c : vertex.adj) {
//		if (!c->known)
//			dfs1(*c);
//	}
//	vertex.num = ++counter;
//}
//
//void dfs1(Graph & graph)
//{
//	for (int i = 1; i < graph.numVertex; ++i) {
//		if (!graph[i].known)
//			dfs1(graph[i]);
//	}
//}
//
//void dfs2(Vertex &vertex, Vertex* begin)
//{
//	cout << &vertex - begin << ends;
//	vertex.known = true;
//	for (auto &c : vertex.adj) {
//		if (!c->known)
//			dfs2(*c, begin);
//	}
//}
//void dfs2(Graph &graph)
//{
//	vector<Vertex*> rank(graph.numVertex);
//	for (int i = 0; i < graph.numVertex; ++i) {
//		rank[graph.numVertex - graph[i].num] = &graph[i];
//	}
//	for (auto &c: rank) {
//		if (!c->known) {
//			dfs2(*c, &graph[0]);
//			cout << endl;
//		}
//	}
//}
//
//void findSroCom(Graph &graph)
//{
//	dfs1(graph);
//	Graph rgraph(graph.numVertex);
//	for (int i = 0; i < graph.numVertex; ++i) {
//		for (size_t j = 0; j < graph[i].adj.size(); ++j) {
//			rgraph.addAdj(graph[i].adj[j] - &graph[0], i);
//		}
//	}
//	for (int i = 0; i < rgraph.numVertex; ++i) 
//		rgraph[i].num = graph[i].num;
//	dfs2(rgraph);
//}
//
//int main()
//{
//	Graph graph(10);
//	graph.addAdj(0, 1);
//	graph.addAdj(0, 3);
//	graph.addAdj(1, 2);
//	graph.addAdj(1, 5);
//	graph.addAdj(2, 0);
//	graph.addAdj(2, 3);
//	graph.addAdj(2, 4);
//	graph.addAdj(3, 4);
//	graph.addAdj(5, 2);
//	graph.addAdj(6, 5);
//	graph.addAdj(6, 7);
//	graph.addAdj(7, 5);
//	graph.addAdj(7, 9);
//	graph.addAdj(8, 7);
//	graph.addAdj(9, 8);
//	findSroCom(graph);
//	return 0;
//}

// 9.32
class Vertex
{
public:
	int degree;
	std::vector<int> adj;
	Vertex() : degree(0) {}
	void addAdj(int v) { 
		adj.push_back(v); 
		++degree;
	}
};

class Graph
{
public:
	int numVertex;
	Vertex* begin;
	vector<vector<bool>> mark;
	Graph(int num = 0) : numVertex(num), begin(new Vertex[num]), mark(vector<vector<bool>>(num,vector<bool>(num, false))) {}
	~Graph() { delete[] begin; }
	Vertex& operator[](int n) {
		return *(begin + n);
	}
	const Vertex& operator[](int n) const {
		return *(begin + n);
	}
	void addAdj(int v1, int v2) {
		--v1;
		--v2;
		(begin + v1)->addAdj(v2);
		(begin + v2)->addAdj(v1);
	}
};

void next(Graph& graph, int v, list<int>& p, list<int>::iterator itr)
{
	for (size_t i = 0; i < graph[v].adj.size(); ++i) {
		if (graph.mark[graph[v].adj[i]][v] != true) {
			graph.mark[graph[v].adj[i]][v] = graph.mark[v][graph[v].adj[i]] = true;
			itr = p.insert(itr,graph[v].adj[i]);
			next(graph, graph[v].adj[i], p, ++itr);
			break;
		}
	}
}


bool Euler(Graph& graph)
{
	for (auto i = 0; i < graph.numVertex; ++i) {
		if (graph[i].degree % 2 != 0)
			return false;
	}
	list<int> path;
	path.push_back(0);
	list<int>::iterator itr = path.begin();
	while (itr != path.end()) {
		auto tmp = itr++;
		next(graph, *tmp, path, itr);
		itr = ++tmp;
	}
	for (auto &c : path)
		cout << c + 1 << ends;
	cout << endl;
	return true;
}

int main()
{
	Graph graph(12);
	graph.addAdj(1, 3);
	graph.addAdj(1, 4);
	graph.addAdj(2, 3);
	graph.addAdj(2, 8);
	graph.addAdj(3, 4);
	graph.addAdj(3, 6);
	graph.addAdj(3, 7);
	graph.addAdj(3, 9);
	graph.addAdj(4, 5);
	graph.addAdj(4, 7);
	graph.addAdj(4, 10);
	graph.addAdj(4, 11);
	graph.addAdj(5, 10);
	graph.addAdj(6, 9);
	graph.addAdj(7, 9);
	graph.addAdj(7, 10);
	graph.addAdj(8, 9);
	graph.addAdj(9, 10);
	graph.addAdj(9, 12);
	graph.addAdj(10, 11);
	graph.addAdj(10, 12);
	Euler(graph);
	return 0;
}
