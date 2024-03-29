/*
Articulation points are those nodes in the graph which when 
removed increase the number of connected components in the graph.
*/.
vector<int> graph[N];
set<int> ans;
int n, time_in[N], mn[N], timer, m;
bool vis[N];
void articulation_point(int node){ ans.insert(node); }
void dfs(int source, int par = -1){
	vis[source] = true;
	time_in[source] = mn[source] = timer++;
	int child = 0;
	for(auto nxt : graph[source]){
		if(nxt == par) continue;
		if(vis[nxt])
			mn[source] = min(mn[source], time_in[nxt]);
		else{
			dfs(nxt, source);
			mn[source] = min(mn[source], mn[nxt]);
			if(mn[nxt] >= time_in[source] && par != -1)
				articulation_point(source);
			++child;
		}
	}
	if(par == -1 && child > 1)
		articulation_point(source);
}
void find_articulationpoints(){
	timer = 0;
	memset(mn, -1, sizeof(mn));
	memset(time_in, -1, sizeof(time_in));
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			dfs(i);
}
