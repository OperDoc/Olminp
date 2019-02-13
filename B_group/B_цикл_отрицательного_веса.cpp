int V, E, INF;
vector<vector<int>> Es;
vector<int> F;
bool ford(int s){
    F.assign(V, INF);
    F[s] = 0;
    bool sr = true;
    for(int i = 0; i < V && st; i++){
        st = false;
        for(auto &e:Es)
            if(F[e[0]] + e[2] < F[e[1]]){
                F[e[1]] = F[e[0]] + e[2];
                st = true;
            }
    }
    return st;
}
