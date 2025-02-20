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
const int N=1e5+5;
int n, k;
int w[N], sub[N]={0}, subcnt[N]={0};
vector<pii> adj[N];
int ans=0;
void dfs(int v, int fa){
    sub[v]=w[v];
    subcnt[v]=1;
    int ed=0;
    for (auto it:adj[v]){
        int u=it.F, d=it.S;
        if (u==fa){
            ed=d; continue;
        }
        dfs(u, v);
        sub[v]+=sub[u];
        subcnt[v]+=subcnt[u];
    }
    ans+=ed*abs(sub[v]-k*subcnt[v]);
}
signed main(){
    starburst;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> w[i];
    int u, v, d;
    for (int i=1;i<=n-1;i++){
        cin >> u >> v >> d;
        adj[u].pb(pii(v, d)); adj[v].pb(pii(u, d));
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}
