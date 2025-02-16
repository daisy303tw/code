#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define ll unsigned long long
const int N=1e5+5;
const ll inf=1e19;
int n, m, c, d;
struct ss{
    ll dis;
    int cost, id, a, b;
}s[N];
bool cmp(ss x, ss y){
    if (x.dis==y.dis && x.cost==y.cost) return x.id<y.id;
    if (x.dis==y.dis) return x.cost<y.cost;
    return x.dis<y.dis;
}
signed main(){
    starburst;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> s[i].a >> s[i].b >> s[i].cost;
        s[i].id=i+1;
        s[i].dis=inf;
    }
    for (int i=0;i<m;i++){
        cin >> c >> d;
        for (int j=0;j<n;j++){
            ll x=(s[j].a-c)*(s[j].a-c)+(s[j].b-d)*(s[j].b-d);
            s[j].dis=min(s[j].dis, x);
        }
    }
    sort(s, s+n, cmp);
    for (int i=0;i<n;i++){
        cout << s[i].id << endl;
    }
    return 0;
}
