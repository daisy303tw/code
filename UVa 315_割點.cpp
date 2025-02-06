#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=105;
int n;
int dfn[N], low[N], cut[N];
bool visited[N]={0};
vector<int> adj[N];
string in;
stringstream sinn;
int x, y, id;
int ans=0;
void dfs(int u, int p){
    visited[u]=1;
    id++; dfn[u]=low[u]=id;
    int child=0;
    for (auto v:adj[u]){
        if (!visited[v]){
            child++;
            dfs(v, u);
            low[u]=min(low[u], low[v]);
            if (u!=p && low[v]>=dfn[u] && !cut[u]){
                cut[u]=1; ans++;
            }
        }
        else if (v!=p){
            low[u]=min(low[u], dfn[v]);
        }
    }
    if (u==p && child>=2 && !cut[u]){
        cut[u]=1; ans++;
    }
}
void init(){
    ans=0;
    for (int i=1;i<=n;i++){
        visited[i]=cut[i]=0;
        adj[i].clear();
        dfn[i]=low[i]=0;
    }
}
signed main(){
    starburst;
    while (cin >> n){
        if (n==0) return 0;
        init();
        getline(cin, in);
        while (getline(cin, in)){
            sinn.clear();
            sinn.str("");
            sinn << in;
            sinn >> x;
            if (x==0) break;
            while (sinn >> y){
                adj[x].pb(y); adj[y].pb(x);
            }
            sinn.clear();
            sinn.str("");
        }
        for (int i=1;i<=n;i++){
            if (!visited[i]){
                id=0;
                dfs(i, i);
            }
        }
        cout << ans << endl;
//        for (int i=1;i<=n;i++){
//            cerr << i << ": ";
//            for (auto u:adj[i]){
//                cerr << u << " ";
//            }
//            cerr << endl;
//        }
    }

    return 0;
}

