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
vector<pii> adj[N];
int t[N], cnt[N];
int mx1=0, mx2=0;
void dfs(int v){
    mx1=max(mx1, t[v]);
    mx2=max(mx2, cnt[v]);
    for (auto it:adj[v]){
        int u=it.F, w=it.S;
        t[u]=t[v]+w;
        cnt[u]=cnt[v]+1;
        dfs(u);
    }
}
signed main(){
    starburst;
    cin >> n;
    int x, w;
    for (int i=1;i<=n-1;i++){
        cin >> x >> w;
        adj[x].pb(pii(i, w));
    }
    t[0]=cnt[0]=0;
    dfs(0);
    cout << mx1 << endl;
    cout << mx2 << endl;
    return 0;
}
