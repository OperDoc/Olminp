#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

const int SIZE = 200000;
const int LOG = 21;
vector<vector<int>> Lg;
vector<int> e;
int f[SIZE], d[SIZE], Log[2 * SIZE];
int D[LOG + 1][2 * SIZE];
int n = 0;
void dfs(int v, int p = -1){
	d[v] = (p == -1 ? 0 : d[p] + 1);
	f[v] = e.size(); e.push_back(v);
	for (auto i : Lg[v]) 
		if (i != p) {dfs(i, v); e.push_back(v);}
}
int Min(int a, int b) {return d[a] < d[b] ? a : b;}
void build() {
	int l = 2 * n - 1;
	for (int i = 0; i < 2 * SIZE; i++)
		Log[i] = (int)log2(i);
	for (int i = 0; i < l; ++i) 
		D[0][i] = e[i];
	for (int i = 1; (1 << i) <= l; ++i) 
		for (int j = 0; j <= l - (1 << i); ++j) 
			D[i][j] = Min(D[i - 1][j], D[i - 1][j + (1 << (i - 1))]);
}
int getmin(int L, int R) {
	int level = Log[R - L + 1];
	return Min(D[level][L], D[level][R - (1 << level) + 1]);
}
int lca(int u, int v){
	u = f[u]; v = f[v];
	if (u > v) swap(u, v);
	return getmin(u, v);
}

int main() {
	int n, m;
	cin >> n;
	Lg.assign(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int help1, help2;
		cin >> help1 >> help2;
		Lg[help1].push_back(help2);
	}
	cin >> m;
	//system("pause");
	return 0;
}
