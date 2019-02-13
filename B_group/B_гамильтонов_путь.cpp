int V, E;
vector<vector<int>> Lg;
vector<int> P;
vector<bool> U;
bool g_c(int v)/*O(2^n)*/{
    P.push_back(v);
    if(P.size()==V) return true;
    U[v] = true;
    for(auto i:Lg[v])
        if(!U[i] && g_c(i)) return true;
    U[v] = false;
    P.pop_back();
    return false;
}
    
