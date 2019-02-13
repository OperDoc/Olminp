bool isop(char a){return a == '(' || a == '[' || a == '{';}
bool isp(char a, char b){return a - b == 1 || a - b == 2;}
bool isok(string &str){
    stack<char> s;
    for(auto i:str){
        if(isop(i))s.push(i);
        else if(s.empty() || isp(s.top(),i)) return false;
            else s.pop();
    }
    return s.empty();
}
vector< vector<int> > D;
void F(int l, int b){
    D.assign(b + 2, vector<int>(l + 1));
    for(int i = 0 ; i <= l; i+=2)
        D[0][i] = c[i/2];
    for(int i = 1; i <= l; i+= 2)
        for(int j = 0; (i + j <= l)&&(j <= b); j++)
            D[j][i + j] = D[j - 1][i + j - 1] + D[j + 1][i + j - 1];
}
vector<string> ans;
void posl(int op, int cl, string &po){
    if(op == 0 && cl == 0)ans.push_back(po);
    else{
        if(op > 0){
            po.push_back('(');
            posl(op - 1, cl, po);
            po.pop_back();
        }
        if(op > cl){
            po.push_back(')');
            posl(op, cl - 1, po);
            po.pop_back();
        }
    }
}
bool nxt(string & S){
    int op = 0, cl = 0, i;
    for (i = S.size() - 1; i >= 0; --i){
        if (S[i] == '(')++op;
        else ++cl;
        if (S[i] == '(' && op < cl)break;
    }
    if (i == -1)return false;
    S[i] = ')'; ++i;
    while (op > 0)
	{S[i] = '('; ++i; --op;}
    while (i < S.size())
	{S[i] = ')'; ++i;}
    return true;
}





bool prev (string & S){
    int op = 0, cl = 0, i;
    for (i = S.size() - 1; i >= 0; --i){
        if (S[i] == '(') ++op;
        else ++cl;
        if (S[i] == '(') break;
    }
    --i;
    for (; i >= 0; --i){
        if (S[i] == '(') ++op;
        else ++cl;
        if (S[i] == ')') break;
    }
    if (i < 0) return false;
    S[i] = '('; --op; ++i;
    while (op != cl)
	{S[i] = ')'; --cl; ++i;}
    while (i < S.size())
	{S[i] = '('; S[i + 1] = ')'; i += 2;}
    return true;
}
