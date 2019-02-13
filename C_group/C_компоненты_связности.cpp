int V;
vector< vector<int> > Lg;
vector<int> u;
void dfs(int v, int c)/*O(E)*/{
    u[v] = c;
    for(auto i:Lg[v])
        if(u[i] == 0)dfs(i, c);
}
void comps()/*O(E)*/{
    int c = 0;
    u.assign(V, 0);
    for(int i = 0; i < V; i++)
        if(u[i] == 0)dfs(i, ++c);
}
