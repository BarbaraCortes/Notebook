/* Algorithm to determine maximum matching in a bipartite graph */
int matu[N];
int matv[N];
int seen[N];
vector<int> adj[N];

int dfs(int u) {
	seen[u] = 1;

	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];

		if (!matv[v] || (!seen[matv[v]] && dfs(matv[v]))) {
			matu[u] = v;
			matv[v] = u;
			return 1;
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		while (1) {
			int v;
			cin >> v;
			if (v == 0) break;
			adj[i].pb(v);
		}
	}

	int ans = 0;
	while (1) {
		int aux = 0;
		memset(seen, 0, sizeof seen);
		for (int u = 1; u <= n; u++) {
			if (!matu[u]) {
				aux += dfs(u);
			}
		}
		if (!aux) break;
		ans += aux;
	}

	cout << ans << endl;

	for (int i = 1; i <= n; i++) {
		if (matu[i]) cout << i << " " << matu[i] << endl; 
	}

	return 0;
}
