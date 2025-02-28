#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=50005;
int n;
vector<int> adj[N];
int sum=0;
vector<int> path;
void dfs(int v, int fa){
    path.pb(v);
    for (auto u:adj[v]){
        if (u==fa) continue;
        dfs(u, v);
        path.pb(v);
    }
}
signed main(){
    starburst;
    cin >> n;
    int a, b, w;
    for (int i=0;i<n-1;i++){
        cin >> a >> b >> w;
        adj[a].pb(b); adj[b].pb(a);
        sum+=w;
    }
    for (int i=0;i<n;i++) sort(all(adj[i]));
    dfs(0, 0);
    cout << sum*2 << endl;
    for (auto i:path) cout << i << " ";
    return 0;
}

