#include <bits/stdc++.h>

using namespace std;

const int N = 100007; //1e5
const int inf = 0x3f3f3f3f; //1061109567 ~ 1e9

int lev[N];
int seen[N];
int dp[N][44];
// int mini[N][44];
vector<pair<int, int> > adj[N];

void dfs(int u, int p, int l) {
	lev[u] = l;
	dp[u][0] = p;
	seen[u] = true;

	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].fi;
		int w = adj[u][i].se;
		if (!seen[v]) {
			maxi[v][0] = w;
			mini[v][0] = w;
			dfs(v, u, l + 1);
		}
	}
}

void build(int n) {
	maxi[0][0] = 0;
	mini[0][0] = inf;
	dfs(0, 0, 0);

	for (int j = 1; j < 30; j++) {
		for (int i = 0; i < n; i++) {
			dp[i][j] = dp[dp[i][j-1]][j-1];
			maxi[i][j] = max(maxi[i][j-1], maxi[dp[i][j-1]][j-1]);
			mini[i][j] = min(mini[i][j-1], mini[dp[i][j-1]][j-1]);
		}
	}
}

int lca(int x, int y) {
	if (lev[x] < lev[y]) swap(x, y);

	// int ans = inf;
	int l = lev[x] - lev[y];

	//nivelando x com y
	for (int i = 30; i >= 0; i--) {
		if (l & (1 << i)) {
			// ans = min(ans, mini[x][i]);
			x = dp[x][i];
		}
	}

	//se eles ja tao iguais tem que parar
	if (x == y) return x;

	for (int i = 30; i >= 0; i--) {
		if (dp[x][i] != dp[y][i]) {
			// ans = min(ans, min(mini[x][i], mini[y][i]));
			x = dp[x][i]; y = dp[y][i];
		}
	}

	// ans = min(ans, min(mini[x][0], mini[y][0]));

	return dp[x][0];
}

int main() {
	ios::sync_with_stdio(false);

	// memset(mini, 0x3f, sizeof mini);
	build(n); //raiz é o 0
	// cout << lca(x, y);
	
	return 0;
}