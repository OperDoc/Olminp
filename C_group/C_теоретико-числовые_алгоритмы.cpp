tuple<int, int, int> gcd(int a, int b)//O(log(min(a, b))){
    if(b == 0)return {1, 0, a};
    tuple<int, int, int> t = gcd(b, a%b);
    return {t.second, t.first - (a / b) * t.second, t.third}
}
int phi (int n){
    int res = n;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            while (n % i == 0) n /= i;
	    res -= res / i;
	}
    if (n > 1)res -= res / n;
    return res;
}
int b_pow (int a, int n)/*O(log(n))*/{
    if (n == 0)return 1;
    if (n % 2 == 1)return binpow (a, n-1) * a;
    int b = pow (a, n/2);
    return b * b;
}
bool isp(int n){
    int d = 2;
    while (n % d != 0 && d * d <= n) ++d;
    return d * d > n;
}
void factor(int n, map<int, int> ans) {
    for(int i = 2; i * i < n; i++){
        while(n % i == 0){
            ans[i]++;
            n /= i;
        }
    }
    if(n != 1) ans[n]++;
}
void ero(int n, vector<bool> &ans){
    ans.assign(n + 1, true);
    for (int i = 2; i * i <= n; ++i)
        if (ans[i])
            for (int j = i * i; j <= n; j += i)
                ans[j] = false;
}
void f_ero(int n, vector<int> & ans){
    vector<int> lp(n, 0);
    for (int i=2; i<=n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            ans.push_back (i);
        }
        for (int j=0; j< ans.size() && ans[j]<=lp[i] && i*ans[j]<=n; ++j)
            lp[i * ans[j]] = ans[j];
    }
}
void divs(int n, vector<int> &ans){
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0) ans.push_back(i);
        if(n % i == 0 && i * i != n) ans.push_back(n / i);
    }
    sort(ans.begin(), ans.end());
}
