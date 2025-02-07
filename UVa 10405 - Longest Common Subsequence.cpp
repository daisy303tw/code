#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
string a, b;
int dp[2][1005];
signed main(){
    starburst;
    while (cin >> a >> b){
        int sa=a.size(), sb=b.size();
        int from=0, to=1;
        memset(dp, 0, sizeof(dp));
        for (int i=1;i<=sa;i++){
            for (int j=1;j<=sb;j++){
                dp[to][j]=max({dp[from][j-1]+(a[i-1]==b[j-1]), dp[to][j-1], dp[from][j]});
            }
            swap(from, to);
        }
        cout << dp[from][sb] << endl;
    }
    return 0;
}
