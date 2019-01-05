#define p_l 2 * v + 1
#define p_r 2 * v + 2
const int SIZE = 100228, inf = 1e9 + 7;
int n, l;
int vd[SIZE], f[SIZE], d[SIZE] lcat[8 * SIZE], st[SIZE], up[SIZE], len[SIZE], w[SIZE];
vector<int> Lg[SIZE], t[SIZE], vert[SIZE] euler;
int dfs(int v, int p) {
    d[v] = (p == -1 ? 0 : d[p] + 1);
    f[v] = euler.size();
    euler.push_back(v);
    w[v] = 1;
    for (auto i:Lg[v]) 
        if (i != p) { w[v] += dfs(i, v);  euler.push_back(v); }
    st[v] = v; up[v] = p; len[v] = 1;
    vert[v].push_back(v);
    for (auto i : Lg[v]) 
        if (i != p && w[i] * 2 >= w[v]) {
            st[v] = st[i];
            up[st[v]] = p;
            len[st[v]]++;
            vert[st[v]].push_back(v);
            break;
        }
    return w[v];
}
int Min(int u, int v) {return d[u] < d[v] ? u : v;}
int buildlca(int v, int l, int r) {
    if (l == r - 1) {lcat[v] = euler[l]; return lcat[v];}
    int m = (l + r) / 2;
    lcat[v] = Min(buildlca(p_l, l, m), buildlca(p_r, m, r));
    return lcat[v];
}
int minlca(int v, int l, int r, int askl, int askr) {
    if (askl >= r || l >= askr) return n;
    if (l >= askl && r <= askr) return lcat[v];
    int m = (l + r) / 2;
    return Min(minlca(p_l, l, m, askl, askr), minlca(p_r, m, r, askl, askr));
}
int lca(int u, int v) {
    u = first[u]; v = first[v];
    if (u > v) swap(u, v);
    return minlca(0, 0, l, u, v + 1);
}
int buildhld(int v, int l, int r, int i) {
    if (l == r - 1) {t[i][v] = vd[vert[i][l]]; return t[i][v];}
    int m = (l + r) / 2;
    t[i][v] = max(buildhld(p_l, l, m, i), buildhld(p_r, m, r, i));
    return t[i][v];
}






int maxhld(int v, int l, int r, int askl, int askr, int i) {
    if (l >= askr || r <= askl) return -inf;
    if (l >= askl && r <= askr) return t[i][v];
    int m = (l + r) / 2;
    return max(maxhld(p_l, l, m, askl, askr, i), maxhld(p_r, m, r, askl, askr, i));
}
void addhld(int v, int l, int r, int pos, int val, int i) {
    if (l == r - 1) {t[i][v] += val; return;    }
    int m = (l + r) / 2;
    if (pos < m) addhld(p_l, l, m, pos, val, i);
    else addhld(p_r, m, r, pos, val, i);
    t[i][v] = max(t[i][2 * v + 1], t[i][2 * v + 2]);
}
void addvertex(int v, int val) {
    addhld(0, 0, len[st[v]], d[st[v]] - d[v], val, st[v]);
}
int maxway(int u, int v) {
    int ans = -inf;
    while (st[u] != st[v]) {
        ans = max(ans, maxhld(0, 0, len[st[u]], d[st[u]] - d[u], len[st[u]], st[u]));
        u = up[st[u]];
    }
    ans = max(ans, maxhld(0, 0, len[st[u]], d[st[u]] - d[u], d[st[v]] - d[v] + 1, st[u]));
    return ans;
}
int max_q(int u, int v)
{int uvlca = lca(u, v); return max(maxway(u, uvlca), maxway(v, uvlca));}
void start() {
    euler.reserve(2 * n - 1);
    dfs(0, -1);
    d[n] = n + 1;
    l = 2 * n - 1;
    buildlca(0, 0, l);
    for (int i = 0; i < n; ++i)
        if (down[i] == i) {
            t[i].resize(4 * len[i]);
            buildhld(0, 0, len[i], i);
        }
}
