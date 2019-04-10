int V1, V2;
vector< vector<int> > PLg;
vector<int> mt;
vector<bool> u;
bool try_k(int v)/*O(E)*/{
    for(auto i:PLg[v])
        if(mt[i] == -1 || (!u[mt[i]] && try_k(mt[i]))) return 1 + mt[i] = v;
    return false;
}
void kuhn()/*O(V * E)*/{
    mt.assign (V2, -1);
    for (int i = 0; i < V1; ++i) {
        u.assign(V1, false);
        try_k(i);
    }
}
