#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=105, inf=1e9;
int m, n;
int a[N][N];
bool visited[N][N]={0};
int sum=0;
int di[4]={0, 0, 1, -1};
int dj[4]={1, -1, 0, 0};
bool ok(int i, int j){
    if (i<=0 || j<=0 || i>m || j>n) return 0;
    if (visited[i][j]) return 0;
    return 1;
}
void solve(int i, int j){
//    cerr << a[i][j] << endl;
    sum+=a[i][j];
    visited[i][j]=1;
    int mn=inf, si, sj;
    for (int d=0;d<4;d++){
        int ni=i+di[d], nj=j+dj[d];
        if (!ok(ni, nj)) continue;
        if (a[ni][nj]<mn){
            si=ni; sj=nj;
            mn=a[ni][nj];
        }
    }
    if (mn==inf) return;
    solve(si, sj);
}
signed main(){
    starburst;
    cin >> m >> n;
    int mn=inf, si, sj;
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
            if (a[i][j]<mn){
            si=i; sj=j;
            mn=a[i][j];
        }
        }
    }
    solve(si, sj);
    cout << sum;
    return 0;
}

