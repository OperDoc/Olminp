int V, INF;
vector<vector < int > > Mg, p;
void flo(){
    p.assign(V, vector<int>(V,-1));
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (Mg[i][k]<INF && Mg[k][j]<INF && Mg[i][k]+Mg[k][j]<Mg[i][j]){
                    Mg[i][j] = Mg[i][k] + Mg[k][j];
                    p[i][j] = p[k][j];
                }
}
void path(int s, int f, vector<int> &ans){
    while(f != -1){
        ans.push_back(v);
        f = p[s][f];
    }
    reverse(ans.begin(), ans.end());
}
