int n;
vector<int> p, d;
int get(int x){
    if(x == p[x])return x;
    p[x] = get(p[x]);
    return p[x];
}
void unin(int x, int y){
    x = get(x);
    y = get(y);
    if(x != y){
        if(d[x] > d[y])swap(x,y);
        p[y] = x;
        if(d[x] == d[y])d[x]++;
    }
}
void st(){
    p.assign(n, 0);
    d.assign(n, 1);
    for(int i = 0; i < n; i++)
        p[i] = i;
}
