vector<int> p, d;
int get(int x)/*O(1)*/{
    if(x == p[x])return x;
    p[x] = get(p[x]);
    return p[x];
}
void unin(int x, int y)/*O(1)*/{
    x = get(x);
    y = get(y);
    if(x != y)
    {
        if(d[x] > d[y])swap(x,y);
        p[y] = x;
        if(d[x] == d[y])d[x]++;
    }
}
struct edge{
    int a, b, c;
    edge(){}
    edge(int h0, int h1, int h2):a(h0),b(h1),c(h2){}
};
int V;
vector<edge> Eg;
bool cmp(edge a, edge b)/*O(1)*/{
    return a.c < b.c;
}
void mino(int n, int m, vector<edge> &ans)/*O(n * log(n))*/{
    p.assign(V, 0);
    d.resize(V, 1);
    for(int i = 0; i < V; ++i)
        p[i] = i;
    sort(Eg.begin(), Eg.end(), cmp);
    for(auto i:Eg)
        if(get(i.a) != get(i.b)){
            unin(i.a, i.b);
            ans.push_back(i);
        }
}
