#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e4+5;
int t, n, m, a, b, id;
vector<int> adj[N];
int dfn[N], low[N], cut[N];
bool visited[N];
vector<int> ans;
void init(){
    for (int i=1;i<=n;i++){
        adj[i].clear();
        dfn[i]=low[i]=cut[i]=visited[i]=0;
    }
    ans.clear();
}
void dfs(int v, int p){
    visited[v]=1;
    id++; dfn[v]=low[v]=id;
    int child=0;
    for (auto u:adj[v]){
        if (!visited[u]){
            child++;
            dfs(u, v);
            low[v]=min(low[v], low[u]);
            if (v!=p && low[u]>=dfn[v] && !cut[v]){
                cut[v]=1; ans.pb(v);
            }
        }
        else if (u!=p) low[v]=min(low[v], dfn[u]);
    }
    if (v==p && child>=2 && !cut[v]){
        cut[v]=1; ans.pb(v);
    }
}
signed main(){
    starburst;
    cin >> t;
    while (t--){
        cin >> n >> m;
        init();
        for (int i=0;i<m;i++){
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }
        for (int i=1;i<=n;i++){
            if (!visited[i]){
                id=0; dfs(i, i);
            }
        }
        sort(all(ans));
        cout << ans.size() << endl;
        if (ans.empty()) cout << 0;
        else for (auto i:ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}
