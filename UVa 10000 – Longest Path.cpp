#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=105;
int n, s, a, b;
vector<int> adj[N];
int mx=0, to=101;
int d[N];
void init(){
    for (int i=1;i<=100;i++){
        adj[i].clear();
        d[i]=-1;
    }
    mx=0, to=101;
}
void dfs(int v){
    if (d[v]>mx || (d[v]==mx && v<to)){
        mx=d[v]; to=v;
    }
    for (auto u:adj[v]){
        if (d[u]<d[v]+1){
            d[u]=d[v]+1;
            dfs(u);
        }
    }
}
signed main(){
    starburst;
//    freopen("/Users/Eric/Desktop/output.txt","w",stdout);
    int cnt=0;
    while (cin >> n){
        if (n==0) return 0;
        cin >> s;
        init();
        d[s]=0;
        while (cin >> a >> b){
            if (a==0 && b==0) break;
            adj[a].pb(b);
        }
        dfs(s);
        cnt++;
        cout << "Case " << cnt << ": The longest path from " << s;
        cout << " has length " << mx << ", finishing at " << to << "." << endl;
        cout << endl;
    }
    return 0;
}
