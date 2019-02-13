int V, m, ans;
vector< vector<int> > Lg;
void dfs(int v = 0, int u = -1, int d = 0)/*O(V)*/{
    if(d > m) {ans = v; m = d}
    for(auto i:Lg[v])
        if(u != i) dfs(i, v, d + 1);
}
void find_d()/*O(V)*/{
    dfs();dfs(m);
}
