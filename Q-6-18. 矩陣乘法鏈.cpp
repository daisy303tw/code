#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=205, inf=1e18;
int n;
int p[N];
int dp[N][N];
int solve(int l, int r){
    if (l==r) return dp[l][l]=0;
    if (dp[l][r]>=0) return dp[l][r];
    int mn=inf;
    for (int k=l;k<r;k++){
        mn=min(mn, solve(l, k)+solve(k+1, r)+p[l]*p[k+1]*p[r+1]);
    }
    return dp[l][r]=mn;
}
signed main(){
    starburst;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i=0;i<=n;i++) cin >> p[i];
    cout << solve(0, n-1);
    return 0;
}
