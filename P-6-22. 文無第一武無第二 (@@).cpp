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
const int N=1e5+5;
int n;
map<int,int> mp;
struct ss{
    int p, c, m;
}a[N];
bool cmp(ss x, ss y){
    if (x.c!=y.c) return x.c>y.c;
    return x.m<y.m;
} // c:x, m:y, ±q¥k©¹¥ª LIS
signed main(){
    starburst;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i].p;
    for (int i=0;i<n;i++) cin >> a[i].c;
    for (int i=0;i<n;i++) cin >> a[i].m;
    sort(a, a+n, cmp);
    mp[-1]=0;
    int ans=0;
    for (int i=0;i<n;i++){
        auto it=mp.upper_bound(a[i].m); it--;
        int w=it->S+a[i].p;
        ans=max(ans, w);
        it=mp.insert(it, {a[i].m, w});
        if (it->S<w) it->S=w;
        it++;
        while (it!=mp.end() && it->S<=w) it=mp.erase(it);
    }
    cout << ans;
    return 0;
}
