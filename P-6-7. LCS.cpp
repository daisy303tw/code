#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
string a, b;
int dp[2][505];
signed main(){
    starburst;
    cin >> a >> b;
    dp[0][0]=0;
    int from=0, to=1;
    for (int i=1;i<=a.size();i++){
        for (int j=1;j<=b.size();j++){
            dp[to][j]=(a[i-1]==b[j-1])?(dp[from][j-1]+1):(max(dp[to][j-1], dp[from][j]));
        }
        swap(from, to);
    }
    cout << dp[from][b.size()];
    return 0;
}
