#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 100000;

long t[8 * SIZE];
typedef long long ll;

ll query(int v, int l, int r, int vL, int vR)
{
	if (r <= vL || vR <= l)
	{
		return 0;
	}
	if (l <= vL && vR <= r)
	{
		return (ll)t[v];
	}
	int vC = (vL + vR) / 2;
	return query(2 * v + 1, l, r, vL, vC) + query(2 * v + 2, l, r, vC, vR);
}

void add(int v, int i, int vL, int vR)
{
	if (i < vL || i >= vR)
		return;
	t[v] += 1;
	if (vR - vL <= 1)
	{
		return;
	}
	int vC = (vR + vL) / 2;
	add(2 * v + 1, i, vL, vC);
	add(2 * v + 2, i, vC, vR);
}

struct TC
{
	int xG;
	int xX;
	int yG;
	int yX;
	TC()
	{
		xG = 0;
		xX = 0;
		yG = 0;
		yX = 0;
	}
	TC(int xG, int xX, int yG, int yX): xG(xG), xX(xX), yG(yG), yX(yX){}
};

struct Event {
    int x;
    int y1, y2;
    int type;
    int num;
    Event(){}
    Event(int x, int y1, int y2, int type, int num):x(x), y1(y1), y2(y2), type(type), num(num){}
};

bool operator <(const Event& a, const Event& b) {
    return a.x < b.x || (a.x == b.x && a.type < b.type);
}

vector<vector<int>> G;
vector<vector<int>> X;
vector<Event> ev;
vector<TC> T;
vector<bool> vG, vX;
vector<ll> pref;
vector<pair<int, int>> ansV;
int timer = 0;

void dfsG(int v)
{
	T[v].xG = timer++;
	vG[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (!vG[G[v][i]])
			dfsG(G[v][i]);
	}
	T[v].yG = timer++;
}

void dfsX(int v)
{
	T[v].xX = timer++;
	vX[v] = true;
	for (int i = 0; i < X[v].size(); i++)
	{
		if (!vX[X[v][i]])
			dfsX(X[v][i]);
	}
	T[v].yX = timer++;
}

signed main()
{
	int n, tmp, sG, sX;
	ll ans = 0;
	cin >> n;
	G.resize(n);
	X.resize(n);
	T.resize(n, TC());
	vG.resize(n);
	vX.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp != 0)
		{
			G[tmp - 1].push_back(i);
		}
		else
		{
			sG = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp != 0)
		{
			X[tmp - 1].push_back(i);
		}
		else
		{
			sX = i;
		}
	}
	timer = 0;
	dfsG(sG);
	timer = 0;
	dfsX(sX);
	int tick = 0;
	for (int i = 0; i < T.size(); i++)
	{
		ev.push_back(Event(T[i].xG, T[i].xX, T[i].xX, 1, i));
		ev.push_back(Event(T[i].yG, T[i].yX, T[i].yX, 1, i));
		ev.push_back(Event(T[i].xG, T[i].xX, T[i].yX, 0, i));
		ev.push_back(Event(T[i].yG, T[i].xX, T[i].yX, 2, i));
	}
	pref.resize(T.size());
	sort(ev.begin(), ev.end());
	for (int i = 0; i < ev.size(); i++)
	{
		if (ev[i].type == 1)
		{
			add(0, ev[i].y1, 0, 2 * SIZE);
		}
		else if (ev[i].type == 0)
		{
			pref[ev[i].num] = query(0, ev[i].y1, ev[i].y2, 0, 2 * SIZE);
		}
		else
		{
			ans += query(0, ev[i].y1, ev[i].y2, 0, 2 * SIZE) - pref[ev[i].num] - 1;
		}
	}
	cout << ans / 2;
	//system("pause");
	return 0;
}
