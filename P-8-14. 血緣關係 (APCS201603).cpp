#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5;
int n;
vector<int> adj[N];
int far, mx=0;
void dfs(int v, int fa, int dis){
    if (dis>mx){
        mx=dis; far=v;
    }
    for (auto u:adj[v]){
        if (u==fa) continue;
        dfs(u, v, dis+1);
    }
    return;
}
signed main(){
    starburst;
    cin >> n;
    int a, b;
    for (int i=0;i<n-1;i++){
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(0, 0, 0);
    dfs(far, far, 0);
    cout << mx;
    return 0;
}
