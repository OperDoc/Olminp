int F(int a){return a;}
int ter(int a, int b)/*O(log(n))*/{
    for(int i = 0; i < 100; i++){
        m1 = (2*a + b)/3;
        m2 = (a + 2*b)/3;
        if(f(m1)>f(m2)) a = m1;
        else            b = m2;
    }
    return min(m1, m2);
}
int doub(int r, int l, int e)/*O(log(n))*/{
    for(int i = 0; i < 100; i++){
        m = (a + b)/2;
        if(e <= m) r = m;
        else l = m + 1;
    }
    return r;
}
