#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1005;
int t, n, g, x;
int p, w;
int dp[35];
signed main(){
    starburst;
    cin >> t;
    while (t--){
        cin >> n;
        memset(dp, 0, sizeof(dp));
        for (int i=0;i<n;i++){
            cin >> p >> w;
            for (int j=30;j>=w;j--){
                dp[j]=max(dp[j], dp[j-w]+p);
            }
        }
        cin >> g;
        int ans=0;
        while (g--){
            cin >> x;
            ans+=dp[x];
        }
        cout << ans << endl;
    }
    return 0;
}
