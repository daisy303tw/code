#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5, inf=0x3f3f3f3f;
int n, k, p;
int dp[N][105][2];
signed main(){
    starburst;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        dp[i][0][0]=0;
        dp[i][0][1]=-inf;
    }
    cin >> p;
    for (int j=1;j<=k;j++){
        dp[1][j][0]=0;
        dp[1][j][1]=-p;
    }
    for (int i=2;i<=n;i++){
        cin >> p;
        for (int j=1;j<=k;j++){
            dp[i][j][0]=max(dp[i-1][j][0], dp[i-1][j][1]+p);
            dp[i][j][1]=max(dp[i-1][j][1], dp[i-1][j-1][0]-p);
        }
    }
    cout << dp[n][k][0];
    return 0;
}
