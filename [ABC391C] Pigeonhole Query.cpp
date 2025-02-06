#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e6+5;
int n, q, opt, p, h;
int a[N];
map<int,int> mp;
signed main(){
    starburst;
    cin >> n >> q;
    for (int i=1;i<=n;i++){
        mp[i]=i;
        a[i]=1;
    }
    int cnt=0;
    while (q--){
        cin >> opt;
        if (opt==1){
            cin >> p >> h;
            int from=mp[p];
            if (a[from]==2) cnt--;
            a[from]--;
            a[h]++;
            if (a[h]==2) cnt++;
            mp[p]=h;
        }
        else {
            cout << cnt << endl;
        }
    }
    return 0;
}

