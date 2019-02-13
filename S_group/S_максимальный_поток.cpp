int V, INF = 1e9+ 7;
vector< vector<int> > WMg;
int Maxstram()/*O(V ^ 4)*/{
    vector< vector<int> > f(n, vector<int>(n))
    for (int i=1; i<n; i++){
		f[0][i] = WMg[0][i];
		f[i][0] = -WMg[0][i];
	}
	vector<int> h (n);
	h[0] = n;
	vector<int> e = f[0];
    for(int i, j;;){
        for(i = 1; i < n - 1; i++) if(e[i] > 0) break;
        if(i == n - 1) break;
        for(j = 0; j < n; j++)if(WMg[i][j] - f[i][j] > 0 && h[i] == h[j]+1)break;
        if (j < n){
            int d = min (e[i], WMg[i][j] - f[i][j]);
            f[i][j] += d;
            f[j][i] = - f[i][j];
            e[i] -= d;
            e[j] += d;  
        }else{
            int d = INF;
            for (int k = 0; k < f.size(); k++)
                if (c[i][k] - f[i][k] > 0) {d = min (d, h[k]);}
            if (d != INF) {h[i] = d + 1;}
        }
    }
    int flow = 0;
    for (int i = 0; i < n; i++)
	if(WMg[i][n - 1]) flow += f[i][n - 1];
    return max(flow,0);
}
