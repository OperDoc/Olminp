int V, E;
vector<vector<bool>> Mg;
vector<int> P;
vector<bool> U;
bool g_c(int v)/*O(2^n)*/{
    P.push_back(v);
    if(P.size()==V)
        if(Mg[P[0]][v]==1) return true;
        else {P.pop_back(); return false;}
    U[v] = true;
    for(int i = 0; i < v; i++)
        if(Mg[v][i] && !U[i] && g_c(i)) return true;
    U[v] = false;
    P.pop_back();
    return false;
}
    
