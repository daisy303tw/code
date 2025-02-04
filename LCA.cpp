#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=2e5+5;
const int lgN=20;
int n, q, x, y;
int p[N][lgN];
int d[N];
void dfs(){
    for (int i=1;i<lgN;i++){
        for (int j=1;j<=n;j++){
            if (p[j][i-1]==-1) p[j][i]=-1;
            else p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
int depth(int v){
    if (d[v]>0) return d[v];
    if (v==1) return d[v]=1;
    return d[v]=depth(p[v][0])+1;
}
int solve(int x, int y){
    int dx=depth(x), dy=depth(y);
    if (dx>dy){
        swap(x, y); swap(dx, dy);
    }
    dy-=dx;
    for (int i=0;i<lgN;i++){
        if (dy&(1<<i)) y=p[y][i];
    }
    if (x==y) return x; // !!!!!
    for (int i=lgN-1;i>=0;i--){
        if (p[x][i]==p[y][i]) continue;
        else {
            x=p[x][i]; y=p[y][i];
        }
    }
    return p[x][0];
}
signed main(){
    starburst;
    memset(p, -1, sizeof(p));
    memset(d, 0, sizeof(d));
    cin >> n >> q;
    for (int i=2;i<=n;i++) cin >> p[i][0];
    dfs();
    while (q--){
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
    return 0;
}
