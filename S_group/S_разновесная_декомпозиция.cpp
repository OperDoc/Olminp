#include <iostream>
#include <vector>
#include <algorithm>
#define p_l 2 * v + 1
#define p_r 2 * v + 2
#define M ((l + r) / 2)
typedef long long ll;
using namespace std;//start
const ll SIZE = 300228, inf = 1e12;//consts
//tree
int n;
int vdata[SIZE];
vector<int> gr[SIZE];
//lca
int first[SIZE];
int d[SIZE];
vector<int> euler;
int lcat[8 * SIZE];
//hld
int down[SIZE];
int up[SIZE];
int len[SIZE];
int w[SIZE];
vector<int> vert[SIZE];
vector<int> c[SIZE];
vector<int> t[SIZE];
vector<bool> is_ch[SIZE];//is_change
//tree
int dfs(int v, int p) {
    d[v] = (p == -1 ? 0 : d[p] + 1);
    first[v] = euler.size();
    euler.push_back(v);
    w[v] = 1;
    for (auto i : gr[v]) {
        if (i != p) {
            w[v] += dfs(i, v);
            euler.push_back(v);
        }
    }
    down[v] = v;
    up[v] = p;
    len[v] = 1;
    vert[v].push_back(v);
    for (auto i : gr[v]) {
        if (i != p && w[i] * 2 >= w[v]) {
            down[v] = down[i];
            up[down[v]] = p;
            len[down[v]]++;
            vert[down[v]].push_back(v);
            break;
        }
    }
    return w[v];
}
//lca
inline int Min(int u, int v) {return d[u] < d[v] ? u : v;}
int buildlca(int v, int l, int r) {
    if (l == r - 1) return lcat[v] = euler[l];
    return lcat[v] = Min(buildlca(p_l, l, M), buildlca(p_r, M, r));
}
int minlca(int v, int l, int r, int a_l, int a_r) {
    if (a_r <= l || r <= a_l) return n;
    if (a_l <= l && r <= a_r) return lcat[v];
    return Min(minlca(p_l, l, M, a_l, a_r), minlca(p_r, M, r, a_l, a_r));
}
inline int lca(int u, int v) {
    u = first[u]; v = first[v];
    if (u > v) swap(u, v);
    return minlca(0, 0, euler.size(), u, v + 1);
}
//hld
void push(int v, int i) {
    if (is_ch[i][v]) {
        is_ch[i][v] = false;
        is_ch[i][p_l] = is_ch[i][p_r] = true;
        c[i][p_l] = c[i][p_r] = c[i][v];
    }
}
int buildhld(int v, int l, int r, int i){
    if(r - l == 1) return t[i][v] = vert[i][l];
    return t[i][v] = buildhld(p_l, l, M, i) + buildhld(p_r, M, r, i);
}
int chhld(int v, int l, int r, int a_l, int a_r, int i, int data) {
    if (a_r <= l || r <= a_l) return is_ch[i][v] ? (r - l) * c[i][v] : t[i][v];
    if (a_l <= l && r <= a_r) {
        is_ch[i][v] = true;
        return (r - l) * (c[i][v] = data);
    }
    push(v, i);
    return t[i][v] = chhld(p_l, l, M, a_l, a_r, i, data) + chhld(p_r, M, r, a_l, a_r, i, data);
}
int sumhld(int v, int l, int r, int a_l, int a_r, int i){
    if (a_r <= l || r <= a_l) return 0;
    if (a_l <= l && r <= a_r) return is_ch[i][v] ? (r - l) * c[i][v] : t[i][v];
    push(v, i);
    int ans = sumhld(p_l, l, M, a_l, a_r, i) + sumhld(p_r, M, r, a_l, a_r, i);
    t[i][v] = (is_ch[i][p_l] ? (M - l) * c[i][p_l]:t[i][p_l]) + (is_ch[i][p_l] ? (r - M) * c[i][p_r]:t[i][p_r]);
    return ans;
}
inline ll ask_way(int u, int v) {
    ll res = 0;
    for(;down[u] != down[v]; u = up[down[u]]) res += sumhld(0, 0, len[down[u]], d[down[u]] - d[u], len[down[u]], down[u]);
    res += sumhld(0, 0, len[down[u]], d[down[u]] - d[u], d[down[v]] - d[v] + 1, down[u]);
    return res;
}
inline void ch_way(int u, int v, int data) {
    for(;down[u] != down[v];u = up[down[u]]) chhld(0, 0, len[down[u]], d[down[u]] - d[u], len[down[u]], down[u], data);
    chhld(0, 0, len[down[u]], d[down[u]] - d[u], d[down[v]] - d[v] + 1, down[u], data);
}
//final functs
void hld_build(){
    euler.reserve(2 * n - 1);
    dfs(0, -1);
    d[n] = n + 1;
    buildlca(0, 0, euler.size());
    for (int i = 0; i < n; ++i) {
        if (down[i] == i) {
            t[i].resize(4 * len[i], 0);
            c[i].resize(4 * len[i], 0);
            is_ch[i].resize(4 * len[i], false);
            buildhld(0, 0, len[i], i);
        }
    }
}
int hld_qwery(int u, int v){
    int uvlca = lca(u, v);
    return ask_way(u, uvlca) + ask_way(v, uvlca) - vdata[uvlca];
}
void hld_change(int u, int v, int  data){
    int uvlca = lca(u, v);
    ch_way(u, uvlca, data);
    ch_way(v, uvlca, data);
}
//program
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        gr[u - 1].push_back(v - 1);
        gr[v - 1].push_back(u - 1);
    }
    hld_build();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v, data;
        char type;
        cin >> type >> v >> u;
        if (type == '?') {
           cout << hld_qwery(u - 1, v - 1) << '\n';
        } else {
            cin >> data;
            hld_change(u - 1, v - 1, data);
        }
    }
    return 0;
}
