#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=505, MN=300000;
// adj:+n+2, -n-2, +1, -1
int m, n, k, id;
int parent[MN], siz[MN];
int a[MN];
int mx=0, sum=0;
int cnt=0, ans=0;
void init(){
    for (int i=0;i<MN;i++){
        parent[i]=i;
        a[i]=0;
        siz[i]=1;
    }
}
int fiind(int i){
    if (parent[i]==i) return i;
    return parent[i]=fiind(parent[i]);
}
void join(int i, int j){
    int r1=fiind(i), r2=fiind(j);
    mx=max(mx, siz[r1]); mx=max(mx, siz[r2]);
    if (r1==r2) return;
    cnt--;
    if (siz[r1]<siz[r2]){
        swap(r1, r2); swap(i, j);
    }
    parent[r2]=r1;
    siz[r1]=siz[r2]=siz[r1]+siz[r2];
    mx=max(mx, siz[r1]);
}
signed main(){
    starburst;
    cin >> m >> n >> k;
    init();
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            id=(n+2)*i+j;
            cin >> a[id];
            if (a[id]==0) continue;
            cnt++;
            if (a[id-1]==1) join(id, id-1);
            if (id-n-2<0) continue;
            if (a[id-n-2]==1) join(id, id-n-2);
        }
    }
    sum=mx; ans+=cnt;
    int i, j, x, y;
    while (k--){
        cin >> i >> j;
        x=(n+2)*i+j;
        if (a[x]==1) continue;
        cnt++;
        a[x]=1;
        y=x+n+2; if (a[y]==1) join(x, y);
        y=x-n-2; if (y>=0 && a[y]==1) join(x, y);
        y=x+1; if (a[y]==1) join(x, y);
        y=x-1; if (a[y]==1) join(x, y);
        sum+=mx; ans+=cnt;
    }
    cout << sum << endl;
    cout << ans;
    return 0;
}
