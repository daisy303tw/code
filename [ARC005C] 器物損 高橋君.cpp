#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define F first
#define S second
const int N=505;
int h, w;
char a[N][N];
int dp[N][N];
//bool visited[N][N];
int si, sj, gi, gj;
int di[4]={0, 0, 1, -1};
int dj[4]={1, -1, 0, 0};
deque<pii> dq;
bool ok(int i, int j){
    return (i>=1 && i<=h && j>=1 && j<=w);
}
signed main(){
    starburst;
    cin >> h >> w;
    for (int i=1;i<=h;i++){
        for (int j=1;j<=w;j++){
            cin >> a[i][j];
            if (a[i][j]=='s'){ si=i; sj=j; }
            if (a[i][j]=='g'){ gi=i; gj=j; }
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[si][sj]=0;
    dq.pb({si, sj});
    while (!dq.empty()){
        auto it=dq.front(); dq.pop_front();
        int x=it.F, y=it.S;
//        visited[x][y]=1;
        for (int d=0;d<4;d++){
            int i=x+di[d], j=y+dj[d];
            if (!ok(i, j)) continue;
            int cost=dp[x][y]+(a[i][j]=='#');
            if (cost<dp[i][j]){
                dp[i][j]=cost;
                if (a[i][j]=='#') dq.pb({i, j});
                else dq.push_front({i, j});
            }
        }
    }
    if (dp[gi][gj]<=2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}


