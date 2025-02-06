#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=55;
int n, m;
char s[N][N], t[N][N];
signed main(){
    starburst;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> s[i][j];
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=m;j++){
            cin >> t[i][j];
        }
    }
    bool flag=1;
    for (int a=1;a<=n-m+1;a++){
        for (int b=1;b<=n-m+1;b++){
            flag=1;
            for (int i=1;i<=m;i++){
                for (int j=1;j<=m;j++){
                    if (s[a+i-1][b+j-1]!=t[i][j]){
                        flag=0; break;
                    }
                }
            }
            if (flag){
                cout << a << " " << b; return 0;
            }
        }
    }
    return 0;
}

