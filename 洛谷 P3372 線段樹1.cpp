#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define L(id) id*2
#define R(id) id*2+1
const int N=1e5+5;
int n, m;
struct node{
    int val, add;
}sum[4*N];
void pull(int id){
    sum[id].val=sum[L(id)].val+sum[R(id)].val;
}
void push(int id, int l, int r){
    int d=sum[id].add;
    int m=(l+r)/2;
    sum[L(id)].val+=d*(m-l+1); sum[L(id)].add+=d;
    sum[R(id)].val+=d*(r-m); sum[R(id)].add+=d;
    sum[id].add=0;
}
void build(int id, int l, int r, vector<int>& v){
    if (l==r){ sum[id].val=v[l]; return; }
    int m=(l+r)/2;
    build(L(id), l, m, v); build(R(id), m+1, r, v);
    pull(id);
}
void range_update(int id, int l, int r, int L, int R, int value){
    if (L<=l && r<=R){
        sum[id].val+=(value*(r-l+1)); sum[id].add+=value; return;
    }
    push(id, l, r); // !!!!!
    int m=(l+r)/2;
    if (L<=m) range_update(L(id), l, m, L, R, value);
    if (m<R) range_update(R(id), m+1, r, L, R, value);
    pull(id);
}
int range_query(int id, int l, int r, int L, int R){
    if (L<=l && r<=R) return sum[id].val;
    push(id, l, r); // !!!!!
    int m=(l+r)/2, ans=0;
    if (L<=m) ans+=range_query(L(id), l, m, L, R);
    if (m<R) ans+=range_query(R(id), m+1, r, L, R);
    return ans;
}
signed main(){
    starburst;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1, 1, n, a);
    int opt, x, y, k;
    while (m--){
        cin >> opt >> x >> y;
        if (opt==1){
            cin >> k;
            range_update(1, 1, n, x, y, k);
        }
        else {
            cout << range_query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}

