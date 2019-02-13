int V;
vector< vector<int> > Lg;
vector< pair<int, int> > B;
vector<int> f, h;
void dfs(int v, int p = -1, int cur = 0)/*O(E)*/{
    f[v] = h[v] = cur++;
    for (auto i : Lg[v]){
        if (h[i] != -1){
            dfs(i, v, cur);
            f[v] = min(f[v], f[i]);
            if (f[i] > h[v]) B.push_back({i,v});
        }
        else if(p != i) f[v] = min(f[v], h[i]);
    }
}
