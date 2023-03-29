bool vis[N];
vector<int> order, scc, component(N), siz(N);
void dfs(int node){
    vis[node] = true;
    for(auto k : graph[node])
        if(!vis[k])
            dfs(k);
    order.push_back(node);
}
void dfs1(int node){
    vis[node] = true;
    scc.push_back(node);
    for(auto k : transpose[node])
        if(!vis[k])
            dfs1(k);
}
int main(){
  for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        transpose[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof vis);
    for(auto k : order){
        if(vis[k]) continue;
        dfs1(k);
        // from here we are actually building condensation graph.
        for(int i = 0; i < scc.size(); ++i)
            component[scc[i]] = scc[0];
        siz[scc[0]] = scc.size();
        scc.clear();
    }
    for(int i = 1; i <= n; ++i){
        for(auto k : graph[i]){
            int par = component[i], par1 = component[k];
            if(par != par1)
                condensation[par].push_back(par1);
        }
    }
}
