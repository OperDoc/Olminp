int V;
vector< vector<int> > Lg;
vector<bool> u;
vector<int> f, h, P;
void dfs(int v, int p = -1, int cur = 0)/*O(E)*/{
    f[v] = h[v] = cur++;
    u[v] = true;
    int ch = 0;
    for (auto i : Lg[v]){
        if (i == p)continue;
        if (!u[i]){
            dfs(i, v, cur);
            f[v] = min(f[v], f[i]);
            if (f[i] >= h[v] && p != -1) P.push_back(v);
            ch++;
        }
        else f[v] = min(f[v], h[i]);
    }
    if(p == -1 && ch > 1)P.push_back(v);
}