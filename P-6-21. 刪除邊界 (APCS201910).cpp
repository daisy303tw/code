#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=30, inf=1e9;
int m, n;
int a[N][N];
int dp[N][N][N][N];
int solve(int u, int d, int l, int r){
    if (dp[u][d][l][r]>=0) return dp[u][d][l][r];
    if (u==d || l==r) return dp[u][d][l][r]=0;
    int cnt, mn=inf;
    // top
    cnt=0;
    for (int j=l;j<=r;j++) cnt+=a[u][j];
    cnt=min(cnt, r-l+1-cnt);
    mn=min(mn, solve(u+1, d, l, r)+cnt);
    // down
    cnt=0;
    for (int j=l;j<=r;j++) cnt+=a[d][j];
    cnt=min(cnt, r-l+1-cnt);
    mn=min(mn, solve(u, d-1, l, r)+cnt);
    // left
    cnt=0;
    for (int i=u;i<=d;i++) cnt+=a[i][l];
    cnt=min(cnt, d-u+1-cnt);
    mn=min(mn, solve(u, d, l+1, r)+cnt);
    // right
    cnt=0;
    for (int i=u;i<=d;i++) cnt+=a[i][r];
    cnt=min(cnt, d-u+1-cnt);
    mn=min(mn, solve(u, d, l, r-1)+cnt);
    return dp[u][d][l][r]=mn;
}
signed main(){
    starburst;
    cin >> m >> n;
    memset(dp, -1, sizeof(dp));
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    cout << solve(1, m, 1, n);
    return 0;
}
