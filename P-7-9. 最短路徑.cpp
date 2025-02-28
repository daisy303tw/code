#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define F first
#define S second
const int N=1e5+5, inf=1e18;
int n, m;
vector<pii> adj[N];
int d[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
signed main(){
    starburst;
    cin >> n >> m;
    fill(d, d+n, inf);
    int u, v, w;
    for (int i=0;i<m;i++){
        cin >> u >> v >> w;
        adj[u].pb(pii(v, w)); adj[v].pb(pii(u, w));
    }
    d[0]=0;
    pq.push(pii(0, 0));
    while (!pq.empty()){
        auto it=pq.top(); pq.pop();
        int now=it.F, v=it.S;
        if (now!=d[v]) continue;
        for (auto t:adj[v]){
            int u=t.F, w=t.S;
            if (d[u]>d[v]+w){
                d[u]=d[v]+w;
                pq.push(pii(d[u], u));
            }
        }
    }
    int mx=0, cnt=0;
    for (int i=0;i<n;i++){
        if (d[i]==inf) cnt++;
        else mx=max(mx, d[i]);
    }
    cout << mx << endl;
    cout << cnt << endl;
    return 0;
}

