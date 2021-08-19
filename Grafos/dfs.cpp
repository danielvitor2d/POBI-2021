#include <bits/stdc++.h>
using namespace std;

int n, m; // Nós, arestas
vector<vector<int>> gr;  // Lista de adjacência
vector<bool> visited;    // Vetor que indica se já foi visitado
vector<int> dist;        // Vetor de distâncias

void dfs(int u) {
	visited[u] = true;
	for (int to : gr[u]) {
		if (visited[to] == false) {
			dist[to] = dist[u] + 1;
			dfs(to);
		}
	}
}

int main() {
	cin >> n >> m;

	gr.assign(n+1, vector<int>());
	visited.assign(n+1, false);
	dist.assign(n+1, false);

	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	dist[1] = 0;
	dfs(1);
	
	for (int i = 1; i <= n; ++i) {
		cout << "Cara: " << i << "; Distancia: " << dist[i] << endl;
	}
}
