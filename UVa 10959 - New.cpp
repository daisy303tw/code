#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int P=1005, inf=1e18;
int t, p, d, x, y;
vector<int> adj[P];
int deg[P];
//void dfs(int v, int parent, int degree){
//    deg[v]=min(deg[v], degree);
//    for (int u:adj[v]){
//        if (u==parent) continue;
//        if (deg[u]<degree+1) continue;
//        deg[u]=degree+1;
//        dfs(u, v, degree+1);
//    }
//}
signed main(){
    starburst;
    cin >> t;
    while (t--){
        cin >> p >> d;
        for (int i=0;i<p;i++){
            adj[i].clear();
            deg[i]=inf;
        }
        for (int i=0;i<d;i++){
            cin >> x >> y;
            adj[x].pb(y); adj[y].pb(x);
        }
        deg[0]=0;
//        dfs(0, 0, 0);
        queue<int> q;
        q.push(0);
        while (!q.empty()){
            int v=q.front(); q.pop();
            for (int u:adj[v]){
                if (deg[u]>deg[v]+1){
                    deg[u]=deg[v]+1;
                    q.push(u);
                }
            }
        }
        for (int i=1;i<=p-1;i++) cout << deg[i] << endl;
        cout << endl;
    }
    return 0;
}
