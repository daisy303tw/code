#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e18+5;
string s;
int siz, ans=0;
int dp[20][10];
// dp[i][j] = number of stair numbers
// which has i digits and start with j
bool is_stair=1;
void pre(){
    dp[1][0]=0;
    for (int j=1;j<=9;j++) dp[1][j]=1;
    for (int i=2;i<=siz;i++){
        dp[i][9]=dp[i-1][9];
        for (int j=8;j>=0;j--){
            dp[i][j]=dp[i][j+1]+dp[i-1][j];
        }
    }
}
signed main(){
    starburst;
    cin >> s;
    siz=s.size();
    for (int i=0;i<siz;i++) s[i]-='0';
    pre();
    for (int j=0;j<s[0];j++) ans+=dp[siz][j];
    for (int i=1;i<siz;i++){
        if (s[i]<s[i-1]){ is_stair=0; break; }
        for (int j=s[i-1];j<s[i];j++) ans+=dp[siz-i][j];
    }
    if (is_stair) ans++;
    cout << ans;
    return 0;
}
