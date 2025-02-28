#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e4+5;
int t, n, m;
bool flag=1;
bool visited[N];
int c[N];
vector<int> adj[N];
void init(int n){
    flag=1;
    for (int i=0;i<n;i++){
        visited[i]=0;
        adj[i].clear();
        c[i]=-1;
    }
}
void dfs(int v, int fa){
    if (visited[v]) return;
    visited[v]=1;
    for (auto u:adj[v]){
        if (u==fa) continue;
        if (c[u]==c[v]){
            flag=0; break;
        }
        c[u]=!(c[v]);
        dfs(u, v);
    }
}
signed main(){
    starburst;
    cin >> t;
    while (t--){
        cin >> n >> m;
        init(n);
        int a, b;
        for (int i=0;i<m;i++){
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }
        c[0]=0;
        for (int i=0;i<n;i++){
            if (!flag) break;
            if (!visited[i]){
                c[i]=0;
                dfs(i, i);
            }
        }
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
