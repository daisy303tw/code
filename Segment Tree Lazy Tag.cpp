#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define N 200005
#define L(id) id*2
#define R(id) id*2+1
#define inf LLONG_MAX
int n, q, t, a, b, u, k;
vector<int> v(N);
struct Node {
int add;
int val;
};
struct tree {
    Node a[4*N];
    void pull(int id){
        a[id].val=min(a[L(id)].val, a[R(id)].val);
    }
    void push(int id){
        a[L(id)].add+=a[id].add; a[L(id)].val+=a[id].add;
        a[R(id)].add+=a[id].add; a[R(id)].val+=a[id].add;
        a[id].add=0;
    }
    void build(int id, int l, int r, vector<int>& v){
        if (l==r){ a[id].val=v[l]; return; }
        int m=(l+r)/2;
        build(L(id), l, m, v), build(R(id), m+1, r, v);
        pull(id);
    }
    void range_update(int id, int l, int r, int L, int R, int value){
        if (L<=l && r<=R){
            a[id].val+=value;
            a[id].add+=value;
            return;
        }
        push(id); // !!!!!
        int m=(l+r)/2;
        if (L<=m) range_update(L(id), l, m, L, R, value);
        if (m<R) range_update(R(id), m+1, r, L, R, value);
        pull(id);
    }
    int range_query(int id, int l, int r, int L, int R){
        if (L<=l && r<=R) return a[id].val;
        push(id); // !!!!!
        int m=(l+r)/2, sum=inf;
        if (L<=m) sum=min(sum, range_query(L(id), l, m, L, R));
        if (m<R) sum=min(sum, range_query(R(id), m+1, r, L, R));
        return sum;
    }
}SegmentTree;

signed main(){
    starburst;
    //freopen("/Users/Eric/Downloads/test_input.txt", "r", stdin);
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> v[i];
    SegmentTree.build(1, 1, n, v);
    while (q--){
        cin >> t;
        if (t==1){
            cin >> a >> b >> u;
            SegmentTree.range_update(1, 1, n, a, b, u);
        }
        else {
            cin >> k;
            cout << SegmentTree.range_query(1, 1, n, k, k) << endl;
        }
    }
    return 0;
}
