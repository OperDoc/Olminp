#include <algorithm>
#include <iostream>
#define M (r + l) / 2
#define SIZE 500010
using namespace std;
struct Nd{
    Nd *cr = nullptr, *cl = nullptr;
    int val;
    node(){}
    node(int v):val(v){}
};
int arr[SIZE];
void build(Nd *rt, int l = 0, int r = SIZE){
    if(r - l == 1)
        return void(rt->val = arr[l]);
    rt->cr = new Nd();   rt->cl = new Nd();
    build(rt->cl, l, M); build(rt->cr, M, r);
    rt->val = min(rt->cl->val, rt->cr->val);
}
int q(Nd *rt, int a_l, int a_r, int l = 0, int r = SIZE){
    if(a_r <= l || r <= a_l) return 1e9 + 7;
    if(a_l <= l && r <= a_r) return rt->val;
    return min(q(rt->cl, a_l, a_r, l, M), q(rt->cr, a_l, a_r, M, r));
}
Nd* ch(Nd *old_rt, int x, int i, int l = 0, int r = SIZE){
    Nd* res = new Nd();
    if(r - l == 1) res->val = x;
    else if(i < M){
        res->cl = ch(old_rt->cl, x, i, l, M);
        res->cr = old_rt->cr;
        res->val = min(res->cl->val, res->cr->val);
    } else {
        res->cl = old_rt->cl;
        res->cr = ch(old_rt->cr, x, i, M, r);
        res->val = min(res->cl->val, res->cr->val);
    }
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Nd*> Rts(m, nullptr);
    Rts[0] = new Nd();
    int curr = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(Rts[0]);
    for(int i = 0; i < m; i++)
    {
        cout << curr + 1 << '\n';
        char a;
        int b, c, d;
        cin >> a >> b >> c >> d;
        if(a == '?')
        {
            cout << q(Rts[b - 1], c - 1, d) << '\n';
        }
        else
        {
            Rts[++curr] = ch(Rts[b - 1], c, d - 1);
        }
    }

    return 0;
}
