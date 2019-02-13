struct Matr{
    bool isT = false;
    int width, height;
    vector< vector<int> > D;
    Matr (){}
    Matr (int n, int m):width(n), height(m){D.assign(m, vector<int>(n, 0));}
    Matr(vector< vector<int> > &a)/*O(n^2)*/{
        height = a.size();
        width = a[0].size();
        D = a;
    }
    int& get(int i, int j)/*O(1)*/{
        if(isT)
            return D[j][i];
        else
            return D[i][j];
    }
    void T90()/*O(1)*/{
        isT = !isT;
        swap(height, width);
    }
};
Matr operator +(Matr A, Matr B)/*O(n^2)*/{
    vector< vector<int> > a (A.height, vector<int>(0, A.width));
    for(int i = 0; i < A.height; i++)
        for(int j = 0; j < A.width; j++)
            a[i][j] = A.get(i, j) + B.get(i, j);
    return Matr(a);
}
Matr operator *(Matr A, Matr B)/*O(n^3)*/{
    vector< vector<int> > a (A.height, vector<int>(0, A.width));
    for(int i = 0; i < A.height; i++)
        for(int j = 0; j < B.width; j++)
            for(int k = 0; k < A.width; k++)
                a[i][j] += A.get(i, k) + B.get(k, j);
    return Matr(a);
}
