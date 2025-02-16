#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5;
int n;
int w[N];
vector<int> adj[N];
int dp[N];
int ans=0;
void dfs(int v, int fa){
    dp[v]=w[v];
    for (auto u:adj[v]){
        if (u==fa) continue;
        dfs(u, v);
        if (dp[u]>0) dp[v]+=dp[u];
    }
}
signed main(){
    starburst;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> w[i];
    int u, v;
    for (int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1, 0);
    cout << *max_element(dp+1, dp+n+1);
    return 0;
}
