int n;
vector<int> a, D(1);
void st()/*O(n)*/{
    for(int i = 1; i < n + 1; i++)
        D.push_back(D[i - 1] + a[i]);
}
int q(int l, int r)/*O(1)*/{
    return D[r] - D[l - 1];
}
