int sp[30][500010], arr[500010], m_log[500010], n;
void st(){
    for(int i = 0; i < 30; i++)
        m_log[i] = log2(i);
    for(int i = 0; i < n; i++)
        sp[0][i] = arr[i];
    for(int i = 1; (1<<i) < n; i++)
        for(int j = 0; j + (1<<i) - 1 < n; j++)
            sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1<<(i - 1))]);
}
int q(int l, int r)/*O(1)*/{
    int i = m_log[r - l + 1];
    return min(sp[i][l], sp[i][r - (1<<j) + 1]);
}
