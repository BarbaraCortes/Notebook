/* Tarjans algorithm to find bridges in an undirected connected graph */
int cnt;
int low[N];
int entrada[N];
vector<int> adj[N];

void dfs(int u, int p = -1) {
	entrada[u] = ++cnt;
	low[u] = entrada[u];

	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
	
		if (entrada[v]) low[u] = min(low[u], entrada[v]);
		else {
      			dfs(v, u);
			low[u] = min(low[u], low[v]);
			
			if (entrada[u] < low[v]) //it's a bridge
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	
	//for (int i = 1; i <= n; i++) {
		//if (!entrada[i]) dfs(i);
	//}
  
	return 0;
}
