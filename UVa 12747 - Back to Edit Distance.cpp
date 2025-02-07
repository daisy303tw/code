#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=2e5+5, inf=1e9;
int t, n, x;
int a[N], b[N];
//int dp[N];
signed main(){
    starburst;
    cin >> t;
    int cnt=0;
    while (t--){
        cin >> n;
//        memset(dp, 0, sizeof(dp));
        for (int i=0;i<n;i++){
            cin >> x;
            a[x]=i;
        }
        for (int i=0;i<n;i++){
            cin >> x;
            b[i]=a[x];
//            cerr << b[i] << " ";
        }
//        cerr << endl;
        vector<int> lis;
        int len=1;
        lis.pb(b[0]);
        for (int i=1;i<n;i++){
            if (b[i]>lis.back()){
                lis.pb(b[i]);
                len++;
//                dp[i]=len;
            }
            else {
                auto it=lower_bound(all(lis), b[i]);
                *it=b[i];
//                dp[i]=(int)(it-lis.begin()+1);
            }
        }
        cnt++;
        cout << "Case " << cnt << ": ";
        cout << 2*(n-len) << endl;
    }
    return 0;
}
