int V;
vector< vector<int> > Lg;
vector<int> f, h, P;
void dfs(int v, int p = -1, int cur = 0)/*O(E)*/{
    f[v] = h[v] = cur++;
    int ch = 0;
    for (auto i : Lg[v]){
        if (h[i] != -1){
            dfs(i, v, cur);
            f[v] = min(f[v], f[i]);
            if (f[i] >= h[v]) P.push_back(v);
            ch++;
        }
        else if(p != i) f[v] = min(f[v], h[i]);
    }
    if(p == -1 && ch > 1)P.push_back(v);
}
