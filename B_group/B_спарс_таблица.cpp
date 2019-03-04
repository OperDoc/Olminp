int lg[500010], st[30][100010], a[500010], n;
void start() {
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 0; (1 << i) <= n; i++) {
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = i ? min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]) : a[j];
    }
}
int q(int l, int r) {
    int p = lg[r - l + 1];
    return min(st[p][l], st[p][r - (1 << p) + 1]);
}