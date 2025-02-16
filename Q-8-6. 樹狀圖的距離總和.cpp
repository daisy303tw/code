#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5;
int n;
int p, w[N], siz[N];
vector<int> child[N];
int ans=0;
void dfs(int v){
    siz[v]=1;
    for (auto u:child[v]){
        dfs(u);
        siz[v]+=siz[u];
    }
    ans+=(siz[v])*(n-siz[v])*w[v];
}
signed main(){
    starburst;
    cin >> n;
    for (int i=2;i<=n;i++){
        cin >> p;
        child[p].pb(i);
    }
    for (int i=2;i<=n;i++){
        cin >> w[i];
    }
    w[1]=0;
    dfs(1);
    cout << ans*2;
    return 0;
}
