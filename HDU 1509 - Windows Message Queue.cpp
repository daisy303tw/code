#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define psi pair<string,int>
#define pp pair<pii,psi>
//#define pp pair<pair<int,int>,pair<string,int>>
#define F first
#define S second
string com;
struct cmp{
    bool operator()(pp x, pp y){
        if (x.F.F!=y.F.F) return x.F.F>y.F.F;
        return x.F.S>y.F.S;
    }
};
priority_queue<pp, vector<pp>, cmp> pq;
string msg;
int para, prior;
signed main(){
    starburst;
    int cnt=0;
    while (cin >> com){
        if (com=="GET"){
            if (pq.empty()) cout << "EMPTY QUEUE!" << endl;
            else {
                cout << pq.top().S.F << " " << pq.top().S.S << endl;
                pq.pop();
            }
        }
        else {
            cnt++;
            cin >> msg >> para >> prior;
            pq.push(make_pair(make_pair(prior, cnt), make_pair(msg, para)));
        }
    }
    return 0;
}
