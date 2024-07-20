#include<iostream>

using namespace std;

int extract_min(int key[], bool mstSet[], int v) {
	int min = INT_MAX;
	int index;

	for (int i = 0; i < v; i++) {
		if (mstSet[i] == false && key[i] < min) {
			min = key[i];
			index = i;
		}
	}

	return index; //minimum key vertex index
}

void primsMST(int graph[][10], int v) {
	int parent[20], key[20];
	bool mstSet[20];

	/*intialize all keys as infinite*/
	for (int i = 0; i < v; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	/*inserting first vertex*/
	key[0] = 0;
	parent[0] = -1; //first node is root therefore, parent=-1

	for (int j = 0; j < v - 1; j++) {
		int min = extract_min(key, mstSet, v); //extracts minimum key vertex

		mstSet[min] = true;

		for (int k = 0; k < v; k++) {
			if ((graph[min][k]!=0) && (mstSet[k] == false) && (graph[min][k] < key[k])) {
				parent[k] = min;
				key[k] = graph[min][k];
			}
		}
	}

	/*printing MST*/
	cout << "\nEdge\tWeight\n";
	for (int i = 1; i < v; i++) {
		cout << parent[i] << "-" << i << "\t" << graph[i][parent[i]];
		cout << "\n";
	}
}

void title() {
	for (int i = 0; i < 60; i++)
		cout << "=";
	cout << "\n\tPRIMS ALGORITHM FOR MINIMUM SPANNING TREE\n";
	for (int i = 0; i < 60; i++)
		cout << "=";
}
int main() {
	int graph[10][10], V;
	title();
	cout << "\nEnter number of vertices: ";
	cin >> V;

	cout << "Enter adjacency matrix for the graph:-\n";
	for(int i=0; i<V; i++)
		for (int j = 0; j < V; j++) {
			cin >> graph[i][j];
		}

	cout << "\nEntered graph has adjacency matrix as follows:-\n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << graph[i][j] << "\t";
		cout << "\n";
	}

	primsMST(graph, V);
	return 0;
}