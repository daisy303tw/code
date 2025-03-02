#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=105, K=1e5+5;
int n, k;
int w[N], p[N];
int dp[K];
signed main(){
    starburst;
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> w[i];
    for (int i=0;i<n;i++) cin >> p[i];
    for (int i=0;i<n;i++){
        for (int j=k;j>=w[i];j--){
            dp[j]=max(dp[j], dp[j-w[i]]+p[i]);
        }
    }
    cout << dp[k];
    return 0;
}
