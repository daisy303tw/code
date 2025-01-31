#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=3e6+5, MOD=998244353;
int t, n;
int f[N], g[N];

int mod(int x, int m){ return (x%m+m)%m; }
int pwo(int a, int n, int p){
    if (n==0) return 1;
    if (n%2) return mod(pwo(a, n-1, p)*a, p);
    int x = pwo(a, n/2, p);
    return mod(x*x, p);
}
int solve(int x, int y){
    return mod(f[x]*g[y]% MOD*g[x-y]%MOD, MOD);
}

signed main(){
    starburst;
    cin >> t;
    f[0]=1;
    for (int i=1;i<N;i++) f[i]=mod(f[i-1]*i, MOD);
    g[N-1] = pwo(f[N-1], MOD-2, MOD);
    for (int i=N-2;i>=0;i--) g[i]=mod(g[i+1]*(i+1), MOD);
    while (t--){
        cin >> n;
        cout << mod(solve(2*n-3, n-2)+solve(2*n-4, n-3)*n%MOD, MOD) << endl;
    }
    return 0;
}
