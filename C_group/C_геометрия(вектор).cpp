#define X real()
#define Y imag()
typedef complex<long double> P;
istream & operator >> (istream & in, P & a)/*O(1)*/{
    long double b, c;
    in >> b >> c;
    a = {b, c};
    return in;
}
bool eq(long double a, long double b)/*O(1)*/{
    long double eps = 1e-6;
    return abs(a - b) < eps;
}
long double dp(P a, P b)/*O(1)*/{return (a * conj(b)).X;}
long double cp(P a, P b)/*O(1)*/{return (conj(a) * b).Y;}
P T90(P a)/*O(1)*/{return P({a.Y, -a.X});}
P turn(P a, P b, long double anj)/*O(1)*/{return a + (b - a) * polar(1.0, anj);}
P turn(P a, P b, long double cosa, long double sina)/*O(1)*/{
    long double x = b.X - a.X, y = b.Y - a.Y;
    return P({a.X + x * cosa - y * sina, a.Y + x * sina + y * cosa})
}
bool inr(P A, P B, P C)/*O(1)*/{
    bool a = (dp(C - A, B - A) >= 0) && eq(cp(C - A, B - A), 0);
    bool b = (dp(C - B, A - B) >= 0) && eq(cp(C - B, A - B), 0);
    return a && b;
}
long double otrlen(P A, P B, P C)/*O(1)*/{
    if(dp(C - A, B - A) < 0) return abs(C - A);
    if(dp(C - B, A - B) < 0) return abs(C - B);
    return abs(cp(A - C, B - C)) / abs(A - B);
}
bool help (long double a, long double b, long double c, long double d)/*O(1)*/{
	return max(min(a, b),min(c, d)) <= min(max(a, b),max(c, d));
}
bool otrc (P a, P b, P c, P d)/*O(1)*/{
	return help(a.X, b.X, c.X, d.X) && help(a.Y, b.Y, c.Y, d.Y)
		&& (cp(b - a, c - a)) * (cp(b - a, d - a)) <= 0
		&& (cp(d - c, a - c)) * (cp(d - c, b - c)) <= 0;
}
