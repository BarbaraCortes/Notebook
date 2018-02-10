/* Algorithm to determine if there is a cicle in a directed graph */
int cor[N];
bool ciclo;
vector<int> adj[N];

void dfs(int u) {
	cor[u] = 1;

	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (cor[v] == 1) ciclo = true;
		if (!cor[v]) dfs(v); 
	}

	cor[u] = 2;
}