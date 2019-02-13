int V, INF;
vector<vector < pair<int, int> > > Lg;
vector <int> d, p;
void Dij(int s)/*O(E)*/{
    d.assign(V, INF); p.assign(V, -1);
    d[s] = 0;
    set< pair<int, int> > q;
    q.insert({d[s], s})
    while (!q.empty()){
        int v = q.begin()->second;
	q.erase(q.begin());
        for (auto e: Lg[v])
            if (d[v] + e.second < d[e.first]){
	    	q.erase({d[e.first], e.first})
                d[e.first] = d[v] + e.second;
                p[e.first] = v;
                q.insert({d[e.first], e.first})
            }
    }
}
void path(int v, vector<int> &ans)/*O(V)*/{
    while(v != -1){
        ans.push_back(v);
        v= p[v];
    }
    reverse(ans.begin(), ans.end());
}
