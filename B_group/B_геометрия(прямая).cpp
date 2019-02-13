struct L{
    long double A, B, C;
    L(long double a, long double b, long double c):A(a),B(b),C(c){}
    L(P a, P b)/*O(1)*/{
        P n = T90(a - b);
        A = n.x; B = n.y;
        C = -(a.x * A + a.y * B);
    }
    P Point(int v)/*O(1)*/{
        return P({-(A*C)/(A*A + B*B) + B*v, -(B*C)/(A*A + B*B) - A*v});
    }
    long double PLlen(P a)/*O(1)*/{
        return (A * a.X + B * a.Y + C)/abs(P({A, B}));
    }
    P near(P a)/*O(1)*/{
        long double d = this->PLlen(a);
        return P({a.X - (A * d)/abs(P({A, B})), a.Y - (B * d)/abs(P({A, B}))});
    }
};
L n_L(L a, int v)/*O(1)*/{
    return L(a.A, a.B, a.C + v * abs(P({a.A,a.B})));
}
P cros(L a, L b)/*O(1)*/{
    long double h = a.A * b.B - b.A * a.B;
    return P({(b.C*a.B - a.C*b.B)/h, (a.C*b.A - b.C*a.A)/h});
}
int iscr(L a, L b)/*O(1)*/{
    if(!eq(a.A * b.B, b.A * a.B))return 1;
    if(eq(a.B * b.C, b.B * a.C) && eq(a.A * b.C, b.A * a.C))return 2;
    return 0;
}
