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
const int N=2e5+5;
int n, x, y;
int ans=0;
vector<pii> v[2];
int solve(vector<int>& a){
    sort(all(a));
    int now=0, sum=0, siz=a.size();
    for (int i=0;i<siz;i++){
        now+=(a[i]*i-sum); sum+=a[i];
    }
    return now;
}
signed main(){
    starburst;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x >> y;
        v[(x+y)%2].pb(make_pair(x, y));
    }
    for (int i=0;i<2;i++){
        vector<int> xx, yy;
        for (auto &[x, y]:v[i]){
            xx.pb(x+y); yy.pb(x-y);
        }
        ans+=solve(xx)+solve(yy);
    }
    cout << ans/2 << endl;
    return 0;
}
