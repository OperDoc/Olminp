#define N 500000
#define K 30 //log(N)

int ds[N], ps[N], f[K][N], Ws[N];
vector<int> g[N], P[N];

int dfs(int v, int size, int& ans, int p = -1, int sum = 1){
    for(auto &i : g[v]) if(ds[i] == 0 && i != p) sum+=dfs(i, size, ans, v);
    if(ans == -1 && (2 * sum >= size || p == -1)) ans = v;
    return sum;
}

void calc(int v, int d, int p = -1, int mMin = 1e9){
    f[d][v] = mMin = min(Ws[v], mMin);
    for(auto &i : g[v]) if(ds[i] == 0 && i != p) calc(i, d, v, mMin);
}

void build(int v = 0, int n = N, int d = 1, int p = -1, int next = -1){
    dfs(v, n, next);
    ds[next] = d;
    ps[next] = p;
    calc(next, d);
    for(auto &i : g[next]) if(ds[i] == 0) build(i, n / 2, d + 1, next);
    int curr = next;
    while(ps[curr] != -1){P[next].push_back(curr); curr = ps[curr];}
}

int lca(int a, int b){//binserch in path - first different
    while(ds[a] > ds[b]) a = ps[a];
    while(ds[a] < ds[b]) b = ps[b];
    while(a != b) {a = ps[a];b = ps[b];}
    return a;
}

int q(int a, int b) {
    int c = lca(a, b);
    return min(f[ds[c]][a], f[ds[c]][b]);
}
