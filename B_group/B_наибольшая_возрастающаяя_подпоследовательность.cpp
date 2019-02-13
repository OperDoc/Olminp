void findLIS(vector<int> &a, vector<int> &ans)/*O(log(n))*/{
    int n = a.size(), l = 0;
    vector<int> pos(n + 1), d(n + 1, 1e9 + 7), p(n);
    pos[0] = -1;
    d[0] = -(1e9 + 7);
    for(int i = 0; i < n; i++){
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if(d[j - 1] < a[i] && a[i] < d[j]){
            d[j] = a[i];
            pos[j] = i;
            p[i] = pos[j - 1];
            l = max(l, j);
        }
    }
    l = pos[l];
    while (l != -1){
        ans.push_back(a[l]);
        l = p[l];
    }
    reverse(ans.begin(), ans.end());
}
