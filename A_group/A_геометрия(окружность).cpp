struct S{
    P O;
    long double R;
    S(P a, long double b):O(a),R(b){}
    void line(L a, vector<P>& ans)/*O(1)*/{
        if(eq(abs(a.PLlen(O)), R)){
            ans.push_back(a.near(O));
            return;
        }
        if(abs(a.PLlen(O)) > R)return;
        P p = a.near(O);
        d = sqrt(R*R - a.PLlen(O)*a.PLlen(O)) * P({-a.B, a.A}) /abs(d);
        ans.push_back(p + d);
        ans.push_back(p + (-1) * d);
    }
    void point(P a, vector<P> &ans)/*O(1)*/{
        P AO = P(O - a);
        if(eq(len(AO), R)){
            ans.push_back(a);
            return;
        }
        if (len(AO) < R)return;
        long double sina = R / abs(AO);
        long double cosa = sqrt(1 - sina * sina);
        P PB = turn(P({0,0}), AO, sina, cosa);
        ans.push_back(a + sqrt(abs(AO)*abs(AO) - R*R) * PB / abs(PB));
        P PA = turn(P({0,0}), AO, -sina, cosa);
        ans.push_back(a + sqrt(abs(AO)*abs(AO) - R*R) * PA / abs(PA));
    }
};
void dS(S a, S b, vector<P> &ans)/*O(1)*/{
    P OO = b.O - a.O;
    if (eq(abs(OO), 0) && eq(a.R, b.R))return;
    if  (abs(OO) < abs(a.R - b.R) || abs(OO) > a.R + b.R)return;
    P OP = a.R * OO / abs(OO);
    if (eq(abs(OO), abs(a.R - b.R)) || eq(abs(OO), a.R + b.R)){
        ans.push_back(a.O + OP);
        return;
    }
    long double cosa=(abs(OO)*abs(OO) + a.R*a.R - b.R*b.R)/(2*abs(OO)*a.R);
    long double sina = sqrt(1 - cosa * cosa);
    ans.push_back(a.O +turn(P({0,0}), OP, sina, cosa));
    ans.push_back(a.O +turn(P({0,0}), OP, -sina, cosa));
}
