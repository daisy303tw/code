#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=18, MX=(1<<18), inf=1e9;
int n, m;
int d[N][N], dp[MX][N];
signed main(){
    starburst;
    cin >> n >> m;
    memset(dp, 0x3f, sizeof(dp));
    int mx=(1<<n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> d[i][j];
        }
        dp[1<<i][i]=d[i][0];
    }
    int ans=inf;
    for (int s=0;s<mx;s++){
        for (int i=0;i<n;i++){
            if ((s&(1<<i))){
                for (int j=0;j<n;j++){
                    if ((s&(1<<j))){
                        dp[s][i]=min(dp[s][i], dp[s^(1<<i)][j]+d[i][j]);
                    }
                }
            }
        }
    }
    cout << dp[mx-1][0] << endl;
//    for (int i=0;i<n;i++){
//        cout << dp[mx-1][i] << " ";
//    }
    return 0;
}
