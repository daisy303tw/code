#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=25;
int n, m;
vector<int> adj[N];
int c[N], depth[N];
int ans=1;
bool flag=0;
int dfs(int v){
    for (auto u:adj[v]) if (c[u]==c[v]) return 0;
    int now=1;
    for (auto u:adj[v]){
        if (depth[u]==-1) depth[u]=depth[v]+1;
        if (depth[u]!=depth[v]+1) continue;
        int cnt=0;
        c[u]=(c[v]+1)%3; cnt+=dfs(u);
        c[u]=(c[u]+1)%3; cnt+=dfs(u);
        c[u]=-1;
        if (cnt==0) return 0;
        now*=cnt;
    }
    return now;
}
signed main(){
    starburst;
    cin >> n >> m;
    int a, b;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    fill(depth, depth+n+1, -1);
    fill(c, c+n+1, -1);
    for (int i=1;i<=n;i++){
        if (depth[i]==-1){
            depth[i]=0; c[i]=0;
            ans*=3*dfs(i);
        }
    }
    cout << ans << endl;
    return 0;
}
