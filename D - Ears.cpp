#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
int l, a;
int dp[5]={0};
int even, odd;
signed main(){
    starburst;
    cin >> l;
    for (int i=0;i<l;i++){
        cin >> a;
        if (a==0) even=2;
        else even=(a%2);
        if (a%2) odd=0;
        else odd=1;
        dp[0]+=a; dp[1]+=even; dp[2]+=odd; dp[3]+=even; dp[4]+=a;
        for (int j=1;j<=4;j++) dp[j]=min(dp[j], dp[j-1]);
    }
    cout << dp[4];
    return 0;
}
