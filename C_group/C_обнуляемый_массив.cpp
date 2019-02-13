struct Ez_0_arr
{
    int t = 0, zero = 0;
    vector<int> arr, ts;

    void set_s(int n, int x = 0)
    {
        arr.assign(n, x);
        ts.assign(n, t);
    }

    void p_b(int x)
    {
        arr.push_back(x);
        ts.push_back(t);
    }

    void set(int i, int x)
    {
        arr[i] = x;
        ts[i] = t;
    }

    int get(int i)
    {
        return ts[i] < t ? zero : arr[i];
    }

    void upd()
    {
        t++;
    }
};
