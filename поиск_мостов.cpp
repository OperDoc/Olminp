int V;
vector< vector<int> > Lg;
vector< pair<int, int> > B;
vector<bool> u;
vector<int> f, h;
void dfs(int v, int p = -1, int cur = 0)/*O(E)*/{
    f[v] = h[v] = cur++;
    u[v] = true;
    for (auto i : Lg[v]){
        if (i == p)continue;
        if (!u[i]){
            dfs(i, v, cur);
            f[v] = min(f[v], f[i]);
            if (f[i] > h[v]) B.push_back({i,v});
        }
        else f[v] = min(f[v], h[i]);
    }
}
