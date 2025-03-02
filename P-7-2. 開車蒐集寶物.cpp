#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=5e5+5;
int n, m;
int mx=0;
int sum[N], parent[N];
int fiind(int x){
    if (parent[x]==x) return x;
    return parent[x]=fiind(parent[x]);
}
void join(int x, int y){
    int r1=fiind(x), r2=fiind(y);
    if (r1==r2) return;
    parent[r1]=r2;
    sum[r1]=sum[r2]=sum[r1]+sum[r2];
    mx=max(mx, sum[r1]);
}
signed main(){
    starburst;
    cin >> n >> m;
    int a, b;
    for (int i=0;i<n;i++){
        cin >> sum[i];
        parent[i]=i;
        mx=max(mx, sum[i]);
    }
    for (int i=0;i<m;i++){
        cin >> a >> b;
        if (a!=b) join(a, b);
    }
    cout << mx;
    return 0;
}
