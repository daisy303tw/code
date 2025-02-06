#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define F first
#define S second
const int N=2e5+5, inf=1e9+5;
vector<pii> v[N];
int t[N];
unordered_map<int,int> mp;
int n, w, q, tt, a;
int x, y, id;
signed main(){
    starburst;
    cin >> n >> w;
    for (int i=1;i<=n;i++){
        cin >> x >> y;
        id=i;
        v[x].pb(make_pair(y, id));
    }
    int mn=inf;
    for (int i=1;i<=w;i++){
        sort(all(v[i]));
        int cnt=0;
        for (auto u:v[i]){
            cnt++;
            t[cnt]=max(t[cnt], u.F);
            mp[u.S]=cnt;
        }
        mn=min(mn, cnt);
    }
    cin >> q;
    while (q--){
        cin >> tt >> a;
        if (mp[a]>mn) cout << "Yes" << endl;
        else if (t[mp[a]]>tt) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

