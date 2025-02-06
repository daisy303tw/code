#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5;
int t, n, m, x, y, id=0;
vector<int> adj[N], jda[N];
bool visited[N];
stack<int> stk;
int scc[N];
void dfs1(int v){
    visited[v]=1;
    for (auto u:adj[v]){
        if (!visited[u]) dfs1(u);
    }
//    stk.push(v);
}
//void dfs2(int v){
//    visited[v]=1;
//    scc[v]=id;
//    for (auto u:jda[v]){
//        if (!visited[u]) dfs2(u);
//    }
//}
void init(){
//    while (!stk.empty()) stk.pop();
    for (int i=1;i<=n;i++){
        adj[i].clear(); //jda[i].clear();
        visited[i]=0;
    }
    id=0;
}
signed main(){
    starburst;
    cin >> t;
    while (t--){
        cin >> n >> m;
        init();
        for (int i=0;i<m;i++){
            cin >> x >> y;
            adj[x].pb(y); //jda[y].pb(x);
        }
        vector<int> v;
        for (int i=1;i<=n;i++){
            if (!visited[i]){
                dfs1(i);
                v.pb(i);
            }
        }
//        fill(visited+1, visited+n+1, 0);
        reverse(all(v));
        for (auto u:v){
            if (!visited[u]){
                dfs1(u);
                id++;
            }
        }
        cout << id << endl;
//        while (!stk.empty()){
//            int x=stk.top(); stk.pop();
//            if (visited[x]) continue;
//            id++;
//            dfs2(x);
//        }
    }
    return 0;
}
