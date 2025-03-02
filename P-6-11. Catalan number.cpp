#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=105, MOD=1e9+9;
int c[N];
int solve(int n){
    if (c[n]>=0) return c[n];
    if (n==0) return c[0]=1;
    c[n]=0;
    for (int i=0;i<n;i++){
        c[n]+=((solve(i)*solve(n-1-i))%MOD);
        c[n]%=MOD;
    }
    return c[n]%MOD;
}
signed main(){
    int n;
    cin >> n;
    fill(c, c+n+1, -1);
    cout << solve(n);
}
