#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5;
int n;
int p, r[N];
vector<int> child[N];
int dp[2][N];
void dfs(int v){
    dp[1][v]=r[v]; dp[0][v]=0;
    for (auto u:child[v]){
        dfs(u);
        dp[1][v]+=dp[0][u];
        dp[0][v]+=max(dp[0][u], dp[1][u]);
    }
}
signed main(){
    starburst;
    cin >> n >> r[1];
    for (int i=2;i<=n;i++){
        cin >> p >> r[i];
        child[p].pb(i);
    }
    dfs(1);
    cout << max(dp[0][1], dp[1][1]);
    return 0;
}
