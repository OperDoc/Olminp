int none = 1e9 + 7;
int mr(){return (rand() << 15) + rand();}
struct nd{
    int x, y, sz = 0, v = none;
    nd *l, *r;
    nd(int x):x(x),y(mr()),l(nullptr),r(nullptr),sz(1), v(x){}
};
typedef nd* pn;
pn x1, x2 ,x3, M_rt;
int g_s(pn rt){return rt ? rt->sz : 0;}
int g_v(pn rt){return rt ? rt->v : none;}
void upd(pn rt){if(rt){rt->sz = g_s(rt->l) + g_s(rt->r) + 1; rt->v = min(rt->x,min(g_v(rt->l), g_v(rt->r)));}}
void spl(pn rt, pn& l, pn& r, int x){
    if(!rt) return void(l = r = nullptr);
    if(g_s(rt->l) < x){spl(rt->r, rt->r, r, x - g_s(rt->l) - 1); l = rt; upd(l);}
    else                               {spl(rt->l, l, rt->l, x); r = rt; upd(r);}
}
void mer(pn& rt, pn l, pn r){
    if(!l || !r) return void(rt = l ? l : r);
    if(l->y < r->y) {mer(l->r, l->r, r); rt = l;}
    else            {mer(r->l, l, r->l); rt = r;}
    upd(rt);
}
void era(pn& rt, int x){
    spl(rt, x1, x3, x + 1); spl(x1, x1, x2, x);
    mer(rt, x1, x3);
}
void ins(pn& rt, int x, int i){
    spl(rt, x1, x2, i);
    mer(rt, x1, new nd(x)); mer(rt, rt, x2);
}
void p_b(pn& rt, int x){mer(rt, rt, new nd(x));}
int q(pn rt, int a_l, int a_r, int l = 0){
    if(!rt)return none;
    int r = l + rt->sz;
    if(l >= a_r || r <= a_l) return none;
    if(l >= a_l && r <= a_r) return rt->v;
    int x = min(q(rt->l, a_l, a_r, l), q(rt->r, a_l, a_r, l + g_s(rt->l) + 1));
    int pos = l + g_s(rt->l);
    int rt_v = (pos >= a_l && pos < a_r) ? rt->x : none;
    return min(rt_v, x);
}
void pnt(pn& rt, int i = 0)
{if(!rt) return; pnt(rt->l, i); cout << rt->x << ':' << i + g_s(rt->l) << ' '; pnt(rt->r, i + g_s(rt->l) + 1);}
int* g_i(pn rt, int i)
{return !rt?0:(g_s(rt->l)>i?g_i(rt->l,i):(g_s(rt->l)==i?&(rt->x):g_i(rt->r,i-g_s(rt->l)-1)));}

