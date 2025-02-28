#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=2e5+5;
int n, m;
int item[105];
int w[N]={0}, l[N]={0}, r[N]={0};
void add(int id){
    if (l[id]==0) return;
    add(l[id]); add(r[id]);
    w[id]=w[l[id]]+w[r[id]];
}
int solve(int id, int val){
    w[id]+=val;
    int L=l[id], R=r[id];
    if (L==0) return id;
    if (w[L]>w[R]) swap(L, R);
    return solve(L, val);
}
signed main(){
    starburst;
    cin >> n >> m;
    for (int i=n;i<2*n;i++) cin >> w[i];
    for (int i=0;i<m;i++) cin >> item[i];
    int p, s, t;
    for (int i=0;i<n-1;i++){
        cin >> p >> s >> t;
        l[p]=s; r[p]=t;
    }
    add(1);
    for (int i=0;i<m;i++){
        cout << solve(1, item[i]) << " ";
    }
    return 0;
}
