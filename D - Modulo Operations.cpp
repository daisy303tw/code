#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=205, X=1e5+5, MOD=1e9+7;
int n, x;
int s[N];
int dp[N][X];
signed main(){
    starburst;
    cin >> n >> x;
    for (int i=1;i<=n;i++) cin >> s[i];
    sort(s+1, s+n+1);
    for (int i=0;i<=x;i++) dp[0][i]=i;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=x;j++){
            dp[i][j]=dp[i-1][j%s[i]]; // next: s[i]
            dp[i][j]+=(dp[i-1][j]*(i-1))%MOD; // next: not s[i]
            dp[i][j]%=MOD;
        }
    }
    cout << dp[n][x];
    return 0;
}
