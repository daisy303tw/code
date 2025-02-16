#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5;
int n, p;
int dp[2][N];
vector<int> child[N];
void dfs(int v, int fa){
    dp[0][v]=0; dp[1][v]=1;
    for (auto u:child[v]){
        dfs(u, v);
        dp[1][v]+=dp[0][u];
        dp[0][v]+=max(dp[0][u], dp[1][u]);
    }
}
signed main(){
    starburst;
    cin >> n;
    for (int i=1;i<=n-1;i++){
        cin >> p;
        child[p].pb(i);
    }
    dfs(0, 0);
    cout << max(dp[0][0], dp[1][0]);
    return 0;
}
