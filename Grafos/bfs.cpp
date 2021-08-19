#include <bits/stdc++.h>
using namespace std;

int n, m; // Nós, arestas
vector<vector<int>> gr;  // Lista de adjacência
vector<bool> visited;    // Vetor que indica se já foi visitado
vector<int> dist;        // Vetor de distâncias

void bfs(int s) {
	dist.assign(n+1, 1e9);
	dist[s] = 0;
	visited.assign(n+1, false);
	visited[s] = true;

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int to : gr[u]) {
			if (visited[to] == false) {
				visited[to] = true;
				dist[to] = dist[u] + 1;
				q.push(to);
			}
		}
	}

}

int main() {
	cin >> n >> m;

	gr.assign(n+1, vector<int>());

	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	bfs(1);
	
	for (int i = 1; i <= n; ++i) {
		cout << "Cara: " << i << "; Distancia: " << dist[i] << endl;
	}
}
