struct eve{
    int x, type;
    event (int a = 0, int b = 0):x(a),type(b){}
};
bool operator < (const event & a, const event & b){
    return a.x < b.x || (a.x == b.x && a.type > b.type);
}
int f(eve a){return a.type;}
vector<eve> D;
int st(){
    int c = 0
    sort(events.begin(), events.end());
    for(auto & e: D){
        c = c + f(e);
    }
    return c;
}