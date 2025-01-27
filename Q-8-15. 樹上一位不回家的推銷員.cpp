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
const int N=5e4+5, inf=1e18;
int n, a, b, w;
vector<pii> adj[N];
bool visited[N];
int mx=0, far;
void dfs(int v, int dis){
    visited[v]=1;
    if (dis>mx){
        mx=dis; far=v;
    }
    for (auto it:adj[v]){
        int u=it.F, w=it.S;
        if (visited[u]) continue;
        dfs(u, dis+w);
    }
}
signed main(){
    starburst;
    cin >> n;
    int sum=0;
    for (int i=0;i<n-1;i++){
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
        sum+=w;
    }
    sum*=2;
    fill(visited, visited+n, 0);
    dfs(0, 0);
    fill(visited, visited+n, 0);
    mx=0;
    dfs(far, 0);
    cout << sum-mx;
    return 0;
}
