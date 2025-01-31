#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=2e5+5;
int n, k;
int v[N], w[N];
bool flagw=0, flagv=0;
int sumw=0, sumv=0;
int ans=0;
int dp[N];
void dfs(int id, int now, int nov){
    if (now>k) return;
    if (id==n+1){ ans=max(ans, nov); return; }
    dfs(id+1, now, nov); dfs(id+1, now+w[id], nov+v[id]);
}
void solve1(){
    if (k>sumw){
        cout << sumv << endl;
        return;
    }
    dfs(1, 0, 0);
    cout << ans << endl;
}
void solve2(){
    memset(dp, 0, sizeof(dp));
    int K=min(sumw, k);
    for (int i=1;i<=n;i++){
        for (int j=K;j>=w[i];j--){
            dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout << dp[K] << endl;
}
void solve3(){
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    for (int i=1;i<=n;i++){
        for (int j=sumv;j>=v[i];j--){
            dp[j]=min(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    for (int i=sumv;i>=0;i--){
        if (dp[i]<=k){
            cout << i << endl;
            break;
        }
    }
}
signed main(){
    starburst;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> v[i] >> w[i];
        sumw+=w[i]; sumv+=v[i];
        if (w[i]>1000) flagw=1;
        if (v[i]>1000) flagv=1;
    }
    if (n<=30 && flagw==1 && flagv==1) solve1();
    else if (flagw==0) solve2();
    else if (flagv==0) solve3();
    return 0;
}
