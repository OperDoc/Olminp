vector<long long> h, pow;
string s;
long long mod = 1e9 + 7, p = 53, n;
long long get_h(int l, int r){
    long long _l = l == 0 ? 0 : h[l - 1] * pow[r - l + 1] % mod;
    return (h[r] + mod - _l) % mod;
}
void st(){
    for (int i = 1; i < n + 100; ++i) 
        pow.push_back(st[i - 1] * p % mod);
    for (int i = 1; i < n; ++i) 
        h.push_back((p * h[i - 1] + s[i]) % mod);
}
void pf (string &a, vector<int> &ans){
    int m = (int) a.length();
    ans.assign(m);
    for (int i = 1; i < m; i++){
        int j = ans[i - 1];
        while (j > 0 && s[i] != a[j])
            j = pi[j-1];
        if (a[i] == a[j])  j++;
        ans[i] = j;
    }
}
void zf (string &a, vector<int> &ans){
    int m = (int) a.length();
    ans.assign(m);
    for (int i=1, l=0, r=0; i < n; i++) {
        if (i <= r)ans[i] = min (r-i+1, ans[i-l]);
	while (i + ans[i] < n && s[ans[i]] == s[i + ans[i]])
            ans[i]++;
	if (i + ans[i]-1 > r)l = i,  r = i+ans[i]-1;
    }
}
