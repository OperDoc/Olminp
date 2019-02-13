struct eve{
    int x, type;
    eve (int a = 0, int b = 0):x(a),type(b){}
};
bool cmp(eve a, eve b){
    return a.x < b.x || (a.x == b.x && a.type > b.type);
}
int f(eve a){return a.type;}
vector<eve> eves;
int st(){
    int c = 0
    sort(eves.begin(), eves.end(), cmp);
    for(auto & e: eves){
        c = c + f(e);
    }
    return c;
}
