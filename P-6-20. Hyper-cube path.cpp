#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=(1<<21);
int n;
int w[N], dp[N];
int solve(int x){
    if (dp[x]>0) return dp[x];
    int mx=0;
    for (int i=0;i<n;i++){
        if (x&(1<<i)){
            mx=max(mx, solve(x^(1<<i)));
        }
    }
    return dp[x]=mx+w[x];
}
signed main(){
    starburst;
    cin >> n;
    for (int i=0;i<(1<<n);i++) cin >> w[i];
    memset(dp, 0, sizeof(dp));
    dp[0]=w[0];
    cout << solve((1<<n)-1);
    return 0;
}
