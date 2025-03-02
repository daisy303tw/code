#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define N 505
#define pii pair<int,int>
#define f first
#define s second
int m, n;
char a[N][N];
int d[N][N];
queue<pii> q;
int di[4]={1,-1,0,0}, dj[4]={0,0,1,-1};
signed main(){
    starburst;
    cin >> m >> n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
            d[i][j]=-1;
            a[0][j]=a[m+1][j]='1';
            a[i][0]=a[i][n+1]='1';
        }
    q.push({1,1});
    d[1][1]=0;
    while (!q.empty()){
        if (d[m][n]>=0) break;
        auto it=q.front();
        int si=it.f, sj=it.s;
        q.pop();
        for (int x=0;x<4;x++){
            int ni=si+di[x], nj=sj+dj[x];
            while (a[ni][nj]=='0'){
                if (d[ni][nj]==-1){
                    d[ni][nj]=d[si][sj]+1;
                    q.push({ni,nj});
                }
                ni+=di[x], nj+=dj[x];
            }
        }
    }
    if (d[m][n]>0) d[m][n]--;
    cout << d[m][n];
    return 0;
}
