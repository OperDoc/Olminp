#define SIZE_N 5000
#define SIZE_M 5000
#define ul 4 * i + 1
#define ur 4 * i + 2
#define dl 4 * i + 3
#define dr 4 * i + 4
#define none 1e9 + 7

int t[16 * SIZE_N * SIZE_M], c[16 * SIZE_N * SIZE_M] a[SIZE_N][SIZE_M];

void push(int i)
{
    c[ul] += c[i];
    c[ur] += c[i];
    c[dl] += c[i];
    c[dr] += c[i];
    c[i] = 0;
}

void st(int i = 0, int nl = 0, int nr = SIZE_N, int ml = 0, int mr = SIZE_M)
{
    if(nr - nl == 1 && mr - ml == 1)
    {
        t[i] = a[nl][nr];
    }
    int nm = (nl + nr) / 2;
    int mm = (ml + mr) / 2;
    if(nr - nl > 1 && mr - ml == 1)
    {
        st(ul, nl, nm, ml, mr);
        st(ur, nm, nr, ml, mr);
        t[i] = min(t[ul], t[ur]);
    }
    if(mr - ml > 1 && nr - nl == 1)
    {
        st(ul, nl, nr, ml, mm);
        st(dl, nl, nr, mm, mr);
        t[i] = min(t[ul], t[dl]);
    }
    if(nr - nl > 1 && mr - ml > 1)
    {
        st(ul, nl, nm, ml, mm);
        st(ur, nm, nr, ml, mm);
        st(dl, nl, nm, mm, mr);
        st(dr, nm, nr, mm, mr);
        t[i] = min(min(t[ul], t[ur]), min(t[dl], t[dr]));
    }
}

int q(int nal, int nar, int mal, int mar, int i = 0, int nl = 0, int nr = SIZE_N, int ml = 0, int mr = SIZE_M)
{
    if(nar <= nl || nr <= nal || mar <= ml || mr <= mal)
        return none;
    if(nal <= nl && nr <= nar && mal <= ml && mr <= mar)
        return t[i] + c[i];
    int nm = (nl + nr) / 2;
    int mm = (ml + mr) / 2;
    push(i);
    if(nr - nl > 1 && mr - ml == 1)
    {
        q(nal, nar, mal, mar, ul, nl, nm, ml, mr);
        q(nal, nar, mal, mar, ur, nm, nr, ml, mr);
        t[i] = min(t[ul], t[ur]);
    }
    if(mr - ml > 1 && nr - nl == 1)
    {
        q(nal, nar, mal, mar, ul, nl, nr, ml, mm);
        q(nal, nar, mal, mar, dl, nl, nr, mm, mr);
        t[i] = min(t[ul], t[dl]);
    }
    if(nr - nl > 1 && mr - ml > 1)
    {
        q(nal, nar, mal, mar, ul, nl, nm, ml, mm);
        q(nal, nar, mal, mar, ur, nm, nr, ml, mm);
        q(nal, nar, mal, mar, dl, nl, nm, mm, mr);
        q(nal, nar, mal, mar, dr, nm, nr, mm, mr);
        t[i] = min(min(t[ul], t[ur]), min(t[dl], t[dr]));
    }
}

void ch(int v, int nal, int nar, int mal, int mar, int i = 0, int nl = 0, int nr = SIZE_N, int ml = 0, int mr = SIZE_M)
{
    if(nar <= nl || nr <= nal || mar <= ml || mr <= mal)
        return;
    if(nal <= nl && nr <= nar && mal <= ml && mr <= mar)
        c[i] += v;
    int nm = (nl + nr) / 2;
    int mm = (ml + mr) / 2;
    push(i);
    if(nr - nl > 1 && mr - ml == 1)
    {
        q(v, nal, nar, mal, mar, ul, nl, nm, ml, mr);
        q(v, nal, nar, mal, mar, ur, nm, nr, ml, mr);
        t[i] = min(t[ul], t[ur]);
    }
    if(mr - ml > 1 && nr - nl == 1)
    {
        q(v, nal, nar, mal, mar, ul, nl, nr, ml, mm);
        q(v, nal, nar, mal, mar, dl, nl, nr, mm, mr);
        t[i] = min(t[ul], t[dl]);
    }
    if(nr - nl > 1 && mr - ml > 1)
    {
        q(v, nal, nar, mal, mar, ul, nl, nm, ml, mm);
        q(v, nal, nar, mal, mar, ur, nm, nr, ml, mm);
        q(v, nal, nar, mal, mar, dl, nl, nm, mm, mr);
        q(v, nal, nar, mal, mar, dr, nm, nr, mm, mr);
        t[i] = min(min(t[ul], t[ur]), min(t[dl], t[dr]));
    }
}
