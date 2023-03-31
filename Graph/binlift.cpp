int dp[N][22], n, lvl[N];

void dfs(int source, int par, int level){
	dp[source][0] = par;
	lvl[source] = level;
	for(auto k : graph[source])
		if(k != par)
			dfs(k, source, level + 1);
}

void init(){
	dfs(1, -1, 0);
	for(int i = 1; i <= 21; ++i)
		for(int j = 1; j <= n; ++j)
			if(dp[j][i - 1] != -1)
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
}

int LCA(int u, int v){
	if(lvl[u] > lvl[v]) swap(u, v);
	int d = lvl[v] - lvl[u];
	while(d){
		int jump = log2(d);
		v = dp[v][jump];
		d -= pow(2, jump);
	}
	if(v == u) 
		return v;
	for(int i = 21; i >= 0; --i){
		if(dp[v][i] != -1 && dp[v][i] != dp[u][i]){
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[v][0];
}
