int V, E, INF;
vector<vector<int>> Es;
vector<int> F, P;
void ford(int s){
    F.assign(V, INF);
    P.assign(V, -1);
    F[s] = 0;
    bool sr = true;
    for(int i = 1; i < V && st; i++){
        st = false;
        for(auto &e:Es)
            if(F[e[0]] + e[2] < F[e[1]]){
                F[e[1]] = F[e[0]] + e[2];
                P[e[1] = e[0];
                st = true;
            }
    }
}
void path(int v, vector<int> &ans){
    while(v != -1){
        ans.push_back(v);
        v = P[v];
    }
    reverse(ans.begin(), ans.end());
}
