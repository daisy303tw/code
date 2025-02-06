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
const int N=1e4+5;
string s;
stringstream ssin;
vector<pii> adj[N];
bool visited[N];
int n;
int x, y, w, ans, far;
void init(){
    for (int i=1;i<=10000;i++){
        adj[i].clear();
    }
}
void dfs(int v, int dis){
    visited[v]=1;
    if (dis>ans){
        ans=dis; far=v;
    }
    for (auto it:adj[v]){
        int u=it.F, w=it.S;
        if (!visited[u]) dfs(u, dis+w);
    }
}
signed main(){
    starburst;
//    freopen("/Users/Eric/Desktop/input.txt","r",stdin);
    while (getline(cin, s)){
        if (s==""){
            far=0; ans=0;
            fill(visited, visited+n+1, 0);
            dfs(1, 0);
            fill(visited, visited+n+1, 0);
            dfs(far, 0);
            cout << ans << endl;
            init();
            continue;
        }
        ssin.clear(); ssin.str("");
        ssin << s;
        ssin >> x; ssin >> y; ssin >> w;
        n=max({n, x, y});
        adj[x].pb(make_pair(y, w));
        adj[y].pb(make_pair(x, w));
    }
    far=0; ans=0;
    fill(visited, visited+n+1, 0);
    dfs(1, 0);
    fill(visited, visited+n+1, 0);
    dfs(far, 0);
    cout << ans << endl;
    cout << endl;
    return 0;
}
