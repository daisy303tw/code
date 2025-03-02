#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=2e5+5;
int n, x;
vector<int> lis;
int cnt=1;
signed main(){
    starburst;
    cin >> n;
    cin >> x;
    lis.pb(x);
    for (int i=1;i<n;i++){
        cin >> x;
        if (x>lis.back()){
            lis.pb(x);
            cnt++;
        }
        else {
            auto it=lower_bound(all(lis), x);
            *it=x;
        }
    }
    cout << cnt;
    return 0;
}
