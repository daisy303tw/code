#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5;
int n, k, x;
int dp[N];
signed main(){
    starburst;
    cin >> n >> k;
    k++;
    dp[0]=0;
    for (int i=1;i<=n;i++){
        cin >> x;
        if (i-k>=0) dp[i]=max(dp[i-1], dp[i-k]+x);
        else dp[i]=max(dp[i-1], x);
    }
    cout << dp[n];
    return 0;
}
