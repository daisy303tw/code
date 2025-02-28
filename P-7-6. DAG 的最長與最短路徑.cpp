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
const int N=1e4+5, inf=1e10;
int n, m, s, t;
vector<pii> adj[N];
int mx[N], mn[N];
int indeg[N]={0};
queue<int> q;
signed main(){
    starburst;
    cin >> n >> m >> s >> t;
    fill(mx, mx+n, -inf);
    fill(mn, mn+n, inf);
    int u, v, w;
    for (int i=0;i<m;i++){
        cin >> u >> v >> w;
        adj[u].pb(pii(v, w));
        indeg[v]++;
    }
    for (int i=0;i<n;i++){
        if (indeg[i]==0) q.push(i);
    }
    mx[s]=mn[s]=0;
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (auto it:adj[v]){
            int u=it.F, w=it.S;
            if (mn[v]<inf){
                mn[u]=min(mn[u], mn[v]+w);
                mx[u]=max(mx[u], mx[v]+w);
            }
            if (--indeg[u]==0) q.push(u);
        }
    }
    if (mn[t]==inf){
        cout << "No path" << endl;
        cout << "No path" << endl;
    }
    else {
        cout << mn[t] << endl;
        cout << mx[t] << endl;
    }
    return 0;
}

