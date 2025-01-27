#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5, inf=1e9;
int n;
int w[N], parent[N];
vector<int> adj[N];
int d[N], dc[N], dp[N];
// d: choose it / dc: choose its child / dp: choose its parent?
bool visited[N]={0};
void dfs(int v){
    d[v]=w[v]; dc[v]=inf; dp[v]=0;
    for (auto u:adj[v]){
        if (!visited[u]){
            visited[u]=1;
            parent[u]=v;
            dfs(u);
            d[v]+=min(d[u], dp[u]);
            dc[v]=min(dc[v], d[u]-dc[u]);
            dp[v]+=min(d[u], dc[u]);
        }
    }
    dc[v]=max(0LL, dc[v]);
    dc[v]+=dp[v];
}
signed main(){
    starburst;
    #ifdef judge
    freopen("/Users/Eric/Desktop/input.txt","r",stdin);
    #endif // judge
    cin >> n;
    for (int i=1;i<=n;i++) cin >> w[i];
    int u, v;
    for (int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    parent[1]=1;
    visited[1]=1;
    dfs(1);
    cout << min(d[1], dc[1]);
    return 0;
}
