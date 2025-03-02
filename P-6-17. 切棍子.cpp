#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=205, inf=1e18;
int n, L;
int p[N];
int cost[N][N];
int solve(int l, int r){
    if (cost[l][r]>=0) return cost[l][r];
    if (l+1==r) return 0;
    int mn=inf;
    for (int k=l+1;k<r;k++){
        mn=min(mn, solve(l, k)+solve(k, r));
    }
    return cost[l][r]=mn+p[r]-p[l];
}
signed main(){
    starburst;
    cin >> n >> L;
    memset(cost, -1, sizeof(cost));
    for (int i=1;i<=n;i++) cin >> p[i];
    p[0]=0; p[n+1]=L;
    cout << solve(0, n+1);
    return 0;
}
