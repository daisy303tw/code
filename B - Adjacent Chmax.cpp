#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=5005, MOD=998244353;
int n, a[N], l, r;
int dp[N];
signed main(){
    starburst;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    dp[0]=1;
    for (int i=1;i<=n;i++){
        l=r=i;
        while (l-1>=1 && a[i]>a[l-1]) l--;
        while (r+1<=n && a[i]>a[r+1]) r++;
        for (int j=l;j<=r;j++) (dp[j]+=dp[j-1])%=MOD;
    }
    cout << dp[n];
    return 0;
}
