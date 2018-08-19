int V1, V2;
vector< vector<int> > PLg;
vector<int> mt;
vector<bool> u1;
bool try_k(int v)/*O(E)*/{
    if(u1[v]) return false;
    for(auto i:PLg[v])
        if(mt[i] == -1 || try_k(mt[i])){
            mt[i] = v;
            return true;
        }
    return false;
}
void kuhn()/*O(V * E)*/{
    mt.assign (V2, -1);
	vector<bool> u2 (V1);
	for (int i = 0; i < V1; ++i)
	    for (auto j:PLg[i])
	        if (mt[j] == -1){
		    mt[j] = i;
		    u2[i] = true;
		    break;
		}
	for (int i = 0; i < V1; ++i) {
	    if (u2[i])  continue;
	    u1.assign(V1, false);
	    try_k(i);
	}
}