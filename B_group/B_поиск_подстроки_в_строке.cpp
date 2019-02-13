vector<long long> h, _pow;
string s, t;
long long mod = 1e9 + 7, p = 53, n;
void st()/*O(n)*/{
    for (int i = 1; i < n + 100; ++i)
        _pow.push_back(_pow[i - 1] * p % mod);
    for (int i = 1; i < n; ++i)
        h.push_back((p * h[i - 1] + s[i]) % mod);
}
void fnd(vector<int> &ans)O(n){
    n = s.length();
    st();
    long long h_t = 0;
    for (int i = 0; i < t.length(); i++)
        h_t += (t[i] - 'a' + 1) * _pow[i];
    for (int i = 0; i < s.length() - t.length() + 1; i++)
    {
        long long cur_h = h[i+t.length()-1];
        if (i)  cur_h -= h[i-1];
        if (cur_h == h_t * _pow[i])ans.push_back(i);
    }
}
