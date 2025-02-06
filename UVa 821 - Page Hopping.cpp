#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=105;
const double inf=1e18;
double g[N][N];
int cas=0, mx=0;
bool flag=0;
void init(){
    for (int i=1;i<N;i++){
        g[i][i]=0;
        for (int j=1;j<N;j++)
            g[i][j]=inf;
    }
    mx=0;
}
signed main(){
    starburst;
    init();
    int a, b;
    while (cin >> a >> b){
        if (a==0 && b==0){
            if (flag) return 0;
            flag=1;
            double ans=0;
            for (int k=1;k<=mx;k++){
                 for (int i=1;i<=mx;i++){
                    for (int j=1;j<=mx;j++){
                            g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
                    }
                }
            }
            double cnt=0;
            for (int i=1;i<=mx;i++){
                for (int j=1;j<=mx;j++){
                    if (g[i][j]!=inf && i!=j){
                        ans+=g[i][j];
                        cnt++;
                    }
                }
            }
//            cerr << ans << endl;
//            cerr << cnt << endl;
            ans/=cnt;
            cas++;
            cout << "Case " << cas << ": average length between pages = ";
            cout << fixed << setprecision(3) << ans << " clicks" << endl;
            init();
        }
        else {
            flag=0;
            g[a][b]=1;
            mx=max({mx, a, b});
        }
    }
    return 0;
}
