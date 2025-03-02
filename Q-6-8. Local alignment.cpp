#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=505;
string a, b;
int dp[N][N];
int mx=0;
signed main(){
    starburst;
    cin >> a >> b;
    memset(dp, 0, sizeof(dp));
    for (int i=1;i<=a.size();i++){
        for (int j=1;j<=b.size();j++){
            if (a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+8;
            dp[i][j]=max({dp[i][j], dp[i-1][j-1]-5, dp[i][j-1]-3, dp[i-1][j]-3});
            mx=max(mx, dp[i][j]);
        }
    }
    cout << mx;
    return 0;
}
