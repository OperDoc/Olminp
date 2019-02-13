const int SIZE = 100228, LOG = 20;
vector<vector<int>> Lg;
vector<int> euler;
int first[SIZE], d[SIZE], Log[2 * SIZE], sparse[LOG + 1][2 * SIZE];
int n = 0;
int Min(int a, int b) { return d[a] < d[b] ? a : b; }
void dfs(int v, int p = -1) {
    d[v] = (p == -1 ? 0 : d[p] + 1);
    first[v] = euler.size();
    euler.push_back(v);
    for (auto i : Lg[v])
        if (i != p) { dfs(i, v); euler.push_back(v);}
}
void build() {
    int l = 2 * n - 1;
    for (int i = 0; i < 2 * SIZE; i++)
        Log[i] = (int)log2(i);
    for (int i = 0; i < l; ++i)
        sparse[0][i] = euler[i];
    for (int i = 1; (1 << i) <= l; ++i)
        for (int j = 0; j <= l - (1 << i); ++j)
            sparse[i][j] = Min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
}
int getmin(int L, int R) {
    int level = Log[R - L + 1];
    return Min(sparse[level][L], sparse[level][R - (1 << level) + 1]);
}
int lca(int u, int v) {
    u = first[u]; v = first[v];
    if (u > v) swap(u, v);
    return getmin(u, v);
}
void start(int s = 0) {
    dfs(s);
    build();
}
