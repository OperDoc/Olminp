int V;
vector< vector<int> > Lg, Lgr;
vector<int> u;
vector<bool> o, c;
void dfs1(int v)/*O(E)*/{
    u[v] = true;
    for(auto i:Lg[v])
        if(!u[i])dfs1(i);
    o.push_back(v);
}
void dfs2(int v)/*O(E)*/{
    c.push_back(v);
    u[v] = true;
    for(auto i:Lgr[v])
        if(!u[i])dfs2(i);
}
void P_comp(vector<vector <int> > &ans)/*O(E)*/{
    u.assign(V, false);
    for(int i = 0; i < V; i++)
        if(!u[i])dfs1(i);
    reverse(o.begin(), o.end());
    u.assign(V, false);
    for(auto i:o)
        if(!u[i]){
            dfs2(i);
            ans.push_back(c);
            c.clear();
        }
}
