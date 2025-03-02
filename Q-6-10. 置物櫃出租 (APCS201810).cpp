#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=105, M=2e5+5;
int n, m, s;
int sum, rest;
int f[N], dp[M];
signed main(){
    starburst;
    cin >> n >> m >> s;
    for (int i=1;i<=n;i++){
        cin >> f[i];
        sum+=f[i];
    }
    rest=m-s;
    for (int i=1;i<=n;i++){
        for (int j=rest;j>=f[i];j--){
            dp[j]=max(dp[j], dp[j-f[i]]+f[i]);
        }
    }
    cout << sum-dp[rest];
    return 0;
}
