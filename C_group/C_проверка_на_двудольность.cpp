int V;
vector< vector<int> > Lg;
vector<int> u;
void dfs(int v, bool &c, bool b){
    u[v] = 1 + b;
    for(auto i:Lg[v]){
        if(!c)return;
        if(u[i] == u[v])c = false;
        if(u[i] == 0)dfs(i, c, !b);
    }
}
bool isb(){
    u.assign(V, 0);
    bool ok = true;
    for(int i = 0; i < V; i++)
        if(u[i] == 0)dfs(i, ok);
    return ok;
}
