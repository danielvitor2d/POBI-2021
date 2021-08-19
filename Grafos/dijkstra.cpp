#include <bits/stdc++.h>
using namespace std;

int n, m; // Nós, arestas
vector<vector<pair<int, int>>> gr;  // Lista de adjacência
vector<bool> visited;    // Vetor que indica se já foi visitado
vector<int> dist;        // Vetor de distâncias

void dijkstra(int s) {
	visited.assign(n, false);

	dist.assign(n, 1e9);
	dist[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});

	while (!pq.empty()) {
		pair<int, int> topo = pq.top();
		pq.pop();

		int u = topo.second;

		if (visited[u] == true) {
			continue;
		}
		visited[u] = true;

		for (pair<int, int> pr : gr[u]) {
			int to = pr.first;
			int w = pr.second;

			if (dist[u] + w < dist[to]) {
				dist[to] = dist[u] + w;
				pq.push({dist[to], to});
			}

		}

	}
}

int main() {
	cin >> n >> m;

	gr.assign(n, vector<pair<int, int>>());

	for (int i = 0, u, v, c; i < m; ++i) {
		cin >> u >> v >> c;
		gr[u].push_back({v, c});
		//gr[v].push_back({u, c});
	}

	dijkstra(0);

	for (int i = 0; i < n; ++i) {
		cout << "Cara: " << i << "; Distancia: " << dist[i] << endl;
	}
}
