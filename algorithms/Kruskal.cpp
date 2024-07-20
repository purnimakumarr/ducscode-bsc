#include<iostream>

using namespace std;

class Edge {
public:
	int start, finish, weight;
};

class Graph {
public:
	int V, E;
	Edge* edge;
};

Graph* create_graph(int V, int E) {
	Graph* g = new Graph;
	g->V = V;
	g->E = E;
	g->edge = new Edge[E];

	return g;
}

class subset {
public: 
	int parent;
	int rank;
};

int find_set(subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find_set(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void union_set(subset subsets[], int u, int v) {
	int uroot = find_set(subsets, u);
	int vroot = find_set(subsets, v);

	if (subsets[uroot].rank < subsets[vroot].rank)
		subsets[uroot].parent = vroot;

	else if (subsets[uroot].rank > subsets[vroot].rank)
		subsets[vroot].parent = uroot;

	else {
		subsets[vroot].parent = uroot;
		subsets[uroot].rank++;
	}
}

/*used in qsort to sort the edges accoring to their weight*/
int compare_edge(const void* a, const void* b) {
	Edge* m = (Edge*)a;
	Edge* n = (Edge*)b;
	return (m->weight > n->weight);
}

void kruskal(Graph* g) {
	int V = g->V;
	Edge mst[20];
	int e = 0, i=0;

	/* soriting edges according to their weight*/
	qsort(g->edge, g->E, sizeof(g->edge[0]), compare_edge);

	subset* subsets = new subset[(V * sizeof(subset))];

	for (int v = 0; v < V; v++) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

		while (e < V - 1 && i < g->E) {
			Edge next_edge = g->edge[i++];
			
			int x = find_set(subsets, next_edge.start);
			int y = find_set(subsets, next_edge.finish);

			if (x != y) {
				mst[e++] = next_edge;
				union_set(subsets, x, y);
			}
		}

		for (int i = 0; i < 20; i++)
			cout << "=";
		cout << "\nMINIMUM SPANNING TREE\n";
		for (int i = 0; i < 20; i++)
			cout << "=";
		cout << endl;

		cout << "\nFollowing are the edges in the mst:-\n";
		for (int i = 0; i < e; i++) {
			cout << mst[i].start << "--------" << mst[i].finish << ":" << "\tweight = " << mst[i].weight;
			cout << endl;
		}
}

void title() {
	for (int i = 0; i < 60; i++)
		cout << "=";
	cout << "\n\tKRUSKAL ALGORITHM FOR MINIMUM SPANNING TREE\n";
	for (int i = 0; i < 60; i++)
		cout << "=";
}

int main() {
	int v, e, s, f, w;
	title();
	cout << "\nEnter number of vertices: ";
	cin >> v;
	cout << "Enter number of edges: ";
	cin >> e;

	Graph *g = create_graph(v, e);

	for (int i = 0; i < e; i++) {
		cout << "\nFor edge "<<i<<":-\n";
		cout << "Start: ";
		cin >> s;
		cout << "Finish: ";
		cin >> f;
		cout << "Weight: ";
		cin >> w;

		g->edge[i].start = s;
		g->edge[i].finish = f;
		g->edge[i].weight = w;

	}

	kruskal(g);
	return 0;
}