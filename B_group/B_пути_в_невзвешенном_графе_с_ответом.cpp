int V, INF;
vector<vector<int> > Lg;
vector<int> D, p;
void bfs(int s)/*O(E)*/{
    D.assign(V, INF);
    p.assign(V, -1);
    queue<int> q;
    D[s] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto i:Lg[v])
            if (D[i] == INF) {
                D[i] = D[v] + 1;
                p[i] = v; 
                q.push(i);
            }
    }
}
void path/*O(V)*/(int v, vector<int> &ans){
    while (v != -1){
        ans.push_back(v);
        v = p[v];
    }
    reverse(ans.begin(), ans.end());
}
