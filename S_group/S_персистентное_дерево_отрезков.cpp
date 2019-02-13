#define M (r + l) / 2
#define SIZE 500010
struct Nd{
    Nd *cr = nullptr, *cl = nullptr;
    int val, c;
    bool is = false;
    Nd(){}
    Nd(int v):val(v){}
    Nd(Nd *n):cr(n->cr),cl(n->cl),val(n->val),c(n->c),is(n->is){}
    int operator()(){return this->is ? this->c : this->val;}

};
int arr[SIZE];
void build(Nd *rt, int l = 0, int r = SIZE){
    if(r - l == 1)
        return void(rt->val = arr[l]);
    rt->cr = new Nd();   rt->cl = new Nd();
    build(rt->cl, l, M); build(rt->cr, M, r);
    rt->val = min((*rt->cl)(), (*rt->cr)());
}
void push(Nd *rt){
    if(rt->is){
        rt->cl = new Nd(rt->cl);
        rt->cr = new Nd(rt->cr);
        rt->cl->is = true;
        rt->cr->is = true;
        rt->cl->c = rt->c;
        rt->cr->c = rt->c;
        rt->is = false;
        rt->c = 0;
    }
}
Nd* ch(Nd *rt, int v, int a_l, int a_r, int l = 0, int r = SIZE){
    if(a_r <= l || r <= a_l) return rt;
    Nd *res = new Nd(rt);
    if(a_l <= l && r <= a_r){
        res->is = true;
        res->c = v;
        return res;
    }
    push(res);
    res->cl = ch(res->cl, v, a_l, a_r, l, M);
    res->cr = ch(res->cr, v, a_l, a_r, M, r);
    res->val = min((*rt->cl)(), (*rt->cr)());
    return res;
}
int q(Nd *rt, int a_l, int a_r, int l = 0, int r = SIZE){
    if(a_r <= l || r <= a_l) return 1e9 + 7;
    if(a_l <= l && r <= a_r)return rt->is ? rt->c : rt->val;
    push(rt);
    int res = min(q(rt->cl, a_l, a_r, l, M), q(rt->cr, a_l, a_r, M, r));
    rt->val = min((*rt->cl)(), (*rt->cr)());
    return res;
}
