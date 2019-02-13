int V;
vector<vector<int> > Lg;
vector<bool> u;
void bfs(int s)/*O(E)*/{
    u.assign(V, false);
    queue<int> q;
    q.push(s);
    used[s] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i:Lg[v])
            if (!u[i]) {
                u[i] = true;
                q.push(i);
            }
    }
}
void dfs(int v)/*O(E)*/{
    u[v] = true;
    for(auto i:Lg[v])
        if(!u[i])dfs(i);
}
