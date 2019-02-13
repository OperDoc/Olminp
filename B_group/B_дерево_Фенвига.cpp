vector <vector <int> > t;
int n, m;

int sum (int x, int y)
{
	int result = ie9+7;
	for (int i = x; i >= 0; i = (i & (i+1)) - 1)
		for (int j = y; j >= 0; j = (j & (j+1)) - 1)
			res = min(res, t[i][j]);
	return res;
}

void inc (int x, int y, int delta)
{
	for (int i = x; i < n; i = (i | (i+1)))
		for (int j = y; j < m; j = (j | (j+1)))
			t[i][j] += delta;
}
