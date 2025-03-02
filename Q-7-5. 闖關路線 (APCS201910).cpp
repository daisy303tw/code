#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e6+5, inf=1e18;
int n, p, l, r;
int s[N];
queue<int> q;
int d[N];
bool ok(int x){
    if (x<0 || x>=n) return 0;
    if (s[x]<0 || s[x]>=n) return 0;
    return 1;
}
signed main(){
    starburst;
    cin >> n >> p >> l >> r;
    fill(d, d+n, inf);
    for (int i=0;i<n;i++){
        cin >> s[i];
    }
    d[0]=0;
    q.push(0);
    while (!q.empty()){
        int v=q.front(); q.pop();
        if (!ok(v)) continue;
        if (v==p){
            cout << d[p]; return 0;
        }
        if (ok(v-l) && d[s[v-l]]>d[v]+1){
            d[s[v-l]]=d[v]+1;
            q.push(s[v-l]);
        }
        if (ok(v+r) && d[s[v+r]]>d[v]+1){
            d[s[v+r]]=d[v]+1;
            q.push(s[v+r]);
        }
    }
    cout << -1;
    return 0;
}
