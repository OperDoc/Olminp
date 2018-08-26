int n;
vector<vector<int>> D;
vector<int> a, log(1);
void st()/*O(n * log(n))*/{
    D.assign(n, vector<int>(log2(2*n)));
    for(int i = 1; i < n + 1; i++)
        log.push_back((int)log2(i));
    for(int i = 0; i < n; i++)
        D[i][0] = a[i];
    for(int i = 1; (1<<i) < n; i++)
        for(int j = 0; (j + (1<<i) - 1) < n; j++)
            D[j][i] = min(D[j][i - 1], D[j + (1<<(i - 1))][i]);
}
int q(int l, int r)/*O(1)*/{
    int j = log[r - l + 1];
    return min(D[l][j], D[r - (1<<j) + 1][j]);
}
