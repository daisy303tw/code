#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=2e5+5, MX=1e15;
int n;
int a[N], b[N], psum[N];
int ans=0;
signed main(){
    starburst;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int t=10;t<=MX;t*=10){
        for (int i=1;i<=n;i++) b[i]=a[i]%t;
        sort(b+1, b+n+1);
        for (int i=1;i<=n;i++) psum[i]=psum[i-1]+(b[i]/(t/10LL));
        for (int i=1;i<=n;i++){
            int it=lower_bound(b+1, b+n+1, t-b[i])-b;
            ans+=psum[it-1];
            ans+=(it-1)*(b[i]/(t/10LL));
            if (it<=n){
                ans+=(psum[n]-psum[it-1]);
                ans+=(n-it+1)*(b[i]/(t/10LL)-9LL); // !
            }
        }
    }
    cout << ans << endl;
    return 0;
}
