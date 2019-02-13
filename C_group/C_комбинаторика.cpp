void fa(vector<long long> &a, vector<long long> &ans)/*O(n)*/{
    long long s = 1; 
    sort(a.rbegin(), a.rend());
    for(int i = 2; i <= a[0]; i++){
	s = s * i;
	if(i == (*a.back())){
	    a.pop_back();
	    ans.push_bask(s);
	}
    }
}
long long C(int n, int k)/*O(n)*/{
    vector<long long> a = {n, k, n - k}, ans;
    fa(a, ans);
    return ans[2] / ans[1] / ans[0];
}
long long kat(int n)/*O(n)*/{
    return C(2 * n, n) / (n + 1);
}
