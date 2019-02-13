#define N 100000
#define ull unsigned long long;

ull arr[N];

void st()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 8; j++)
            arr[i] += ( (rand() % 256) << (j * 8));
}

ull hesh(vector<int> &q)
{
    ull res = 0;
    for(auto i : q)
    {
        res = res ^ arr[i];
    }
    return res;
}

ull insdel(ull a, int i)
{
    return a ^ arr[i];
}
