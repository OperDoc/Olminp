#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <cstdlib>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <cstdint>

#define loop(i, n) for(int i=0; i<n; i++)
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
#define mp make_pair
#define fr first
#define sc second
#define SIZE 500100
#define Q 250005
#define U 50000
#define sq 6300

using namespace std;

typedef pair<pair<int,int>,pair<int, int>> mstr;
typedef unsigned long long ull;

int n, qq;
bool used[Q];
vector<mstr> query;
ull m_sort[SIZE / 64];
pair<int, int> update_no[SIZE];
int arrr[SIZE], cnt[SIZE], anss[Q];

inline int mex(){
    int ans = 0, ans2 = 0;
    while (m_sort[ans] == ((ull)18446744073709551615)) {ans++;}
    while ((m_sort[ans]>>ans2) % 2 == 1){ans2++;}
    return ans * 64 + ans2;
}

bool comp(mstr x, mstr y){
    int p = x.fr.fr / sq;
    int q = y.fr.fr / sq;
    if (p == q){
        int pp = x.fr.sc / sq;
        int qq = y.fr.sc / sq;
        if (pp == qq)
            return x.sc.fr < y.sc.fr;
        return x.fr.sc < y.fr.sc;
    }
    return x.fr.fr < y.fr.fr;
}

inline void update(int i, int x, int y){
    int index = update_no[i].fr;
    int vv = update_no[i].sc;
    int old = arrr[index];
    arrr[index] = vv;
    update_no[i].sc = old;
    if (index >= x && index <= y){
        cnt[old]--;
        if (cnt[old] == 0)
            m_sort[old / 64] -= (ull)1 << (old % 64);
        cnt[vv]++;
        if (cnt[vv] == 1)
            m_sort[vv/64] |= (ull)1 << (vv % 64);
    }
}

inline void Add(int i){
    int vv = arrr[i];
    cnt[vv]++;
    if (cnt[vv] == 1)
        m_sort[vv / 64] |= (ull)1 << (vv % 64);
}

inline void Remove(int i){
    int vv = arrr[i];
    cnt[vv]--;
    if (cnt[vv] == 0)
        m_sort[vv / 64] -= (ull)1 << (vv % 64);
}

void Mo(){
    sort(all(query), comp);
    int lef = 1, rt = 0, update_tim = 0;
    loop(i, qq){
        int x = query[i].fr.fr;
        int y = query[i].fr.sc;
        int tt = query[i].sc.fr;
        while (update_tim < tt){
            update_tim++;
            update(update_tim, lef, rt);
        }
        while (update_tim > tt){
            update(update_tim, lef, rt);
            update_tim--;
        }
        while (lef < x){
            Remove(lef);
            lef++;
        }
        while (lef > x){
            lef--;
            Add(lef);
        }
        while (rt < y){
            rt++;
            Add(rt);
        }
        while (rt > y){
            Remove(rt);
            rt--;
        }
        anss[query[i].sc.sc] = mex() + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    query.reserve(q);
    loop(i, n)
        cin >> arrr[i + 1];
    int cntt = 0;
    loop(i, q){
        int x, y;
        char c;
        cin >> c >> x >> y;
        if (c == '!')
            update_no[++cntt] = mp(x, y);
        else
            query.pb(mp(mp(x, y), mp(cntt, i)));
    }
    qq = query.size();
    Mo();
    loop(i, q)
        if (anss[i] != 0)
            cout << anss[i] - 1 << '\n';
    //system("pause");
    return  0;
}
