#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define L(id) id*2
#define R(id) id*2+1
const int N=1e6+5, inf=1e18;
struct Node{
    int val, add=0, to=inf;
}mx[4*N];
void pull(int id){
    mx[id].val=max(mx[L(id)].val, mx[R(id)].val);
}
void pushto(int id){
    if (mx[id].to==inf) return;
    int d=mx[id].to;
    mx[L(id)].val=mx[L(id)].to=d; mx[L(id)].add=0;
    mx[R(id)].val=mx[R(id)].to=d; mx[R(id)].add=0;
    mx[id].to=inf;
}
void pushadd(int id){
    int d=mx[id].add;
    mx[L(id)].val+=d; mx[R(id)].val+=d;
    mx[L(id)].add+=d; mx[R(id)].add+=d;
    mx[id].add=0;
}
void build(int id, int l, int r, vector<int>& v){
    mx[id].to=inf;
    if (l==r){ mx[id].val=v[l]; return; }
    int m=(l+r)/2;
    build(L(id), l, m, v); build(R(id), m+1, r, v);
    pull(id);
}
void range_to(int id, int l, int r, int L, int R, int value){
    if (L<=l && r<=R){
        mx[id].val=mx[id].to=value;
        mx[id].add=0;
        return;
    }
    pushto(id);
    pushadd(id);
    int m=(l+r)/2;
    if (L<=m) range_to(L(id), l, m, L, R, value);
    if (m<R) range_to(R(id), m+1, r, L, R, value);
    pull(id);
}
void range_add(int id, int l, int r, int L, int R, int value){
    if (L<=l && r<=R){
        mx[id].val+=value; mx[id].add+=value;
        return;
    }
    pushto(id);
    pushadd(id);
    int m=(l+r)/2;
    if (L<=m) range_add(L(id), l, m, L, R, value);
    if (m<R) range_add(R(id), m+1, r, L, R, value);
    pull(id);
}
int range_query(int id, int l, int r, int L, int R){
    if (L<=l && r<=R) return mx[id].val;
    pushto(id);
    pushadd(id);
    int ans=-inf, m=(l+r)/2;
    if (L<=m) ans=max(ans, range_query(L(id), l, m, L, R));
    if (m<R) ans=max(ans, range_query(R(id), m+1, r, L, R));
    return ans;
}
signed main(){
    starburst;
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    for (int i=1;i<=n;i++) cin >> v[i];
    build(1, 1, n, v);
    int opt, l, r, x;
    while (q--){
        cin >> opt >> l >> r;
        if (opt==1){
            cin >> x;
            range_to(1, 1, n, l, r, x);
        }
        else if (opt==2){
            cin >> x;
            range_add(1, 1, n, l, r, x);
        }
        else cout << range_query(1, 1, n, l, r) << endl;
    }
}
