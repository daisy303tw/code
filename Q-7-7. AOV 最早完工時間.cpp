#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e4+5;
int n, m;
int w[N];
vector<int> parent[N], child[N];
int deg[N]={0};
int t[N]; // start time
signed main(){
    starburst;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> w[i];
    int u, v;
    for (int i=0;i<m;i++){
        cin >> u >> v;
        parent[v].pb(u); child[u].pb(v);
        deg[v]++;
    }
    queue<int> q;
    for (int i=1;i<=n;i++){
        t[i]=0;
        if (deg[i]==0) q.push(i);
    }
    int mx=0;
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (auto u:child[v]){
            t[u]=max(t[u], t[v]+w[v]);
            mx=max(mx, t[u]+w[u]);
            if (--deg[u]==0) q.push(u);
        }
    }
    for (int i=1;i<=n;i++){
        if (t[i]+w[i]==mx) q.push(i);
    }
    set<int> st;
    while (!q.empty()){
        int v=q.front(); q.pop();
        st.insert(v);
        for (auto u:parent[v]){
            if (t[u]+w[u]==t[v]) q.push(u);
        }
    }
    cout << mx << endl;
    for (auto u:st) cout << u << " ";
    return 0;
}
