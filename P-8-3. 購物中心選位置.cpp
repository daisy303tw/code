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
const int N=1e5+5;
int n;
int p[N], w[N];
int median=-1, ans=0;
int subcnt[N];
vector<pii> child[N];
void dfs(int v){
    subcnt[v]=1;
    for (auto it:child[v]){
        int u=it.F, d=it.S;
        dfs(u);
        subcnt[v]+=subcnt[u];
        ans+=min(subcnt[u], n-subcnt[u])*d;
    }
    if (median<0 && subcnt[v]>=(n+1)/2) median=v;
}
signed main(){
    starburst;
    cin >> n;
    for (int i=1;i<n;i++){
        cin >> p[i] >> w[i];
        child[p[i]].pb(pii(i, w[i]));
    }
    dfs(0);
    cout << median << endl;
    cout << ans << endl;
    return 0;
}
