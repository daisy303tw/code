#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=205;
int m, n;
int a[N][N], colsum[N][N];
signed main(){
    starburst;
    cin >> m >> n;
    memset(colsum, 0LL, sizeof(colsum));
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
            colsum[i][j]=colsum[i-1][j]+a[i][j];
        }
    }
    int mx=a[1][1];
    int now, delta;
    for (int i=1;i<=m;i++){
        for (int k=i;k<=m;k++){
            now=0;
            for (int j=1;j<=n;j++){
                delta=colsum[k][j]-colsum[i-1][j];
                now+=delta;
                now=max(0LL, now);
                mx=max(mx, now);
            }
        }
    }
    cout << mx;
    return 0;
}
