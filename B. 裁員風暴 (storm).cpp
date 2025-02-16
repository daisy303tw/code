#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=2e5+5, inf=2e9;
int n, k;
int w[N];
vector<int> v;
bool ok(int mid){
    int cnt=0;
    for (int i=1;i<=n;i++){
        int j=lower_bound(w+i, w+n+1, mid-w[i])-w;
        cnt+=(n+1-j);
        if (cnt>=k) return 1;
    }
//    cerr << "mid: " << mid << " cnt: " << cnt << endl;
    return cnt>=k;
}
signed main(){
    starburst;
    cin >> n >> k;
    int mn=inf, mx=-inf;
    for (int i=1;i<=n;i++){
        cin >> w[i];
        mn=min(mn, w[i]);
        mx=max(mx, w[i]);
    }
    sort(w+1, w+n+1);
//    int l=2*mn, r=2*mx;
    int l=-inf, r=inf+1;
    while (r-l>1){
        int mid=(l+r)/2;
        if (ok(mid)) l=mid;
        else r=mid;
    }
    int ans=l;
    if (ans%2!=0){
        cout << ans << endl;
        cout << 2;
    }
    else {
        cout << ans/2 << endl;
        cout << 1;
    }
    return 0;
}

