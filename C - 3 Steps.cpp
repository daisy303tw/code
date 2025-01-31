#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5;
int n, m, a, b;
int cnt=0;
vector<int> adj[N];
int c[N]={0};
bool flag=0;
bool dfs(int v){
    if (c[v]==1) cnt++;
    for (auto u:adj[v]){
        if (c[u]==c[v]) return 0;
        if (c[u]==0){
            c[u]=((c[v]==1)?-1:1);
            if (!dfs(u)) return 0;
        }
    }
    return 1;
}
signed main(){
    starburst;
    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    c[1]=1;
    if (dfs(1)) cout << cnt*(n-cnt)-m;
    else cout << n*(n-1)/2-m;
    return 0;
}
