#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=1e5+5;
int n;
int dp[N]={0};
struct ss{
    int s, t, e;
}s[N];
bool cmp(ss x, ss y){
    return x.t<y.t;
}
int solve(int i){
    int goal=s[i].s;
    int it=lower_bound(s, s+i, s[i].s,
                       [](const ss& x, int val){ return x.t<val; })-s;
    return dp[it-1];
}
signed main(){
    starburst;
    #ifdef judge
    freopen("/Users/Eric/Desktop/input.txt","r",stdin);
    #endif // judge
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s[i].s >> s[i].t >> s[i].e;
    }
    s[n].s=0; s[n].t=-1; s[n].e=0;
    sort(s, s+n+1, cmp);
    dp[0]=0;
    for (int i=1;i<=n;i++){
        dp[i]=max(dp[i-1], solve(i)+s[i].e);
    }
    cout << dp[n];
    return 0;
}
