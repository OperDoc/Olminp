long double s(int n, vector<P> & d)/*O(n)*/{
    long double sq = 0;
    for(int i = 0; i < n; ++i)
        sq = sq + cp(d[i], d[(i + 1)%n]);
    sq = sq / 2;
    return sq;
}
bool icon(int n, vector<P> & A)/*O(n)*/{
    long double B;
    bool count1 = true, count2 = true;
    for(int i = 0; i < n; ++i){
        B = cp(A[(i + 1)%n] - A[i], A[(i + 2)%n] - A[i]);
        if(B != 0)
            if(B > 0) count1 = false;
            else count2 = false;
    }
    return count1 ^ count2;
}
bool isin(int n, vector<P> & A, P s)/*O(n)*/{
    long double sq = 0, pi2 = 6.283185;
     for(int i = 0; i < n; ++i)
        sq += atan2(cp(A[(i+1)%n] - s, A[i] - s), dp(A[i] - s, A[(i+1)%n] - s));
    for(int i = 0; i < n; ++i)
        if(inr(A[i], A[(i + 1)%n], s))
            return true;
    return eq(abs(sq),pi2);
}
P ps;
bool cmp(P a, P b)/*O(1)*/{
    return cp(a-ps, b-ps)>0||(eq(cp(a-ps, b-ps),0)&&abs(a-ps)<abs(b-ps));
}
void conwa(vector<P> & A, vector<P> & ans)/*O(n * log(n))*/{
    int m = 0, sz, s1;
    for(int i = 0; i < A.size(); ++i){
        if(A[i].Y < A[m].Y || (A[i].Y == A[m].Y && A[i].X < A[m].X))
        m = i;
    }
    swap(A[0], A[m]); ps = A[0];
    sort(A.begin() + 1, A.end(), cmp);
    ans.push_back(A[0]); ans.push_back(A[1]);
    s1 = A.size(); sz = 2;
    for(int i = 2; i < s1; ++i){
        while(sz > 2 && ((A[i] - ans[sz - 1])^(ans[sz - 1] - ans[sz - 2])) >= 0){
            ans.pop_back();
            sz--;
        }
        ans.push_back(A[i]);
        sz++;
    }
}
