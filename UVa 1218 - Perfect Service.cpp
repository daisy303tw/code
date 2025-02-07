#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e4+5, inf=1e9;
int n, a, b;
vector<int> adj[N];
int dp[N][3];
void init(){
    for (int i=1;i<=10000;i++){
        adj[i].clear();
    }
}
void dfs(int v, int p){
    dp[v][0]=dp[v][2]=0;
    dp[v][1]=1;
    int delta=inf, sum=0;
    for (auto u:adj[v]){
        if (u==p) continue;
        dfs(u, v);
        dp[v][0]+=dp[u][2];
        dp[v][1]+=min(dp[u][0], dp[u][1]);
        delta=min(delta, dp[u][1]-dp[u][2]);
        sum+=dp[u][2];
    }
    dp[v][2]=sum+delta;
}
signed main(){
    starburst;
    while (cin >> n){
        if (n==-1) return 0;
        if (n==0) continue;
        init();
        for (int i=0;i<n-1;i++){
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }
        dfs(1, 0);
        cout << min(dp[1][1], dp[1][2]) << endl;
//        for (int i=1;i<=n;i++){
//            cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
//        }
    }
    return 0;
}
