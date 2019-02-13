int V;
vector< vector<int> > Lg;
vector<int> u;
void dfs(int v, bool &c){
    u[v] = 1;
    for(auto i:Lg[v]){
        if(c)return;
        if(u[i] == 2)c = false;
        if(u[i] == 0)dfs(i, c);
    }
    u[v] = 2;
}
bool isc(){
    u.assign(V, 0);
    bool ok = false;
    for(int i = 0; i < V; i++)
        if(u[i] == 0)dfs(i, ok);
    return ok;
}
