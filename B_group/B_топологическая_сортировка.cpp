int V;
vector< vector<int> > Lg;
vector<bool> u;
void dfs(int v, vector<int> &ans){
    u[v] = true;
    for(auto i:Lg[v])
        if(!u[i])dfs(i);
    ans.push_back(v);
}
void T_s(vector<int> &ans){
    u.assign(V, false);
    for(int i = 0; i < V; i++)
        if(!u[i])dfs(i, ans);
    reverse(ans.begin(), ans.end());
}
