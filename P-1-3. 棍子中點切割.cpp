//#define judge
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=5e4+5, L=1e9+5;
int n, len;
int p[N];
int sum=0;
void solve(int l, int r){
    if (r-l<=1) return;
    int mid=(p[l]+p[r])/2;
    int t=lower_bound(p+l, p+r, mid)-p;
    if (p[t-1]-p[l]>=p[r]-p[t]) t--;
    sum+=(p[r]-p[l]);
    solve(l, t); solve(t, r);
}
signed main(){
    starburst;
    #ifdef judge
    freopen("/Users/Eric/Desktop/input.txt","r",stdin);
    #endif // judge
    cin >> n >> len;
    p[0]=0; p[n+1]=len;
    for (int i=1;i<=n;i++) cin >> p[i];
    solve(0, n+1);
    cout << sum;
    return 0;
}
