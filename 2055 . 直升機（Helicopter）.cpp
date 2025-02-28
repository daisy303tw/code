#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define L(id) id*2
#define R(id) id*2+1
const int N=1e6+5;
int mn[4*N];
int n;
vector<int> h(N);
void pull(int id){
    mn[id]=min(mn[L(id)], mn[R(id)]);
}
void build(int id, int l, int r, vector<int>& v){
    if (l==r){ mn[id]=v[l]; return; }
    int m=(l+r)/2;
    build(L(id), l, m, v); build(R(id), m+1, r, v);
    pull(id);
}
int range_query(int id, int l, int r, int L, int R){
    if (L<=l && r<=R) return mn[id];
    int m=(l+r)/2, ans=N;
    if (L<=m) ans=min(ans, range_query(L(id), l, m, L, R));
    if (m<R) ans=min(ans, range_query(R(id), m+1, r, L, R));
    return ans;
}
signed main(){
    starburst;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> h[i];
    build(1, 1, n, h);
    int a, b;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        cout << range_query(1, 1, n, a, b)+1 << endl;
    }
    return 0;
}
