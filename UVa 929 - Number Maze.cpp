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
const int N=1005, inf=1e18;
int t, m, n;
int a[N][N], dis[N][N];
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
bool ok(int i, int j){
    return ((i>=1)&&(j>=1)&&(i<=m)&&(j<=n));
}
signed main(){
    starburst;
    cin >> t;
    while (t--){
        cin >> m >> n;
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                cin >> a[i][j];
                dis[i][j]=inf;
            }
        }
        queue<pii> q;
        q.push(make_pair(1, 1));
        dis[1][1]=a[1][1];
        while (!q.empty()){
            auto it=q.front(); q.pop();
            int x=it.F, y=it.S;
            for (int d=0;d<4;d++){
                int i=x+dx[d], j=y+dy[d];
                if (!ok(i, j)) continue;
                if (dis[i][j]<=dis[x][y]+a[i][j]) continue;
                dis[i][j]=dis[x][y]+a[i][j];
                q.push(make_pair(i, j));
            }
        }
        cout << dis[m][n] << endl;
    }
    return 0;
}
