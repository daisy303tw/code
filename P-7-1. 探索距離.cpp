#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=4005, inf=1e18;
int n, m, s;
vector<int> adj[N];
int cnt=0, sum=0;
int d[N];
queue<int> q;
signed main(){
    starburst;
    cin >> n >> m >> s;
    fill(d, d+n, inf);
    int a, b;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        if (a!=b) adj[a].pb(b);
    }
    d[s]=0;
    q.push(s);
    while (!q.empty()){
        int v=q.front(); q.pop();
        cnt++;
        sum+=d[v];
        for (auto u:adj[v]){
            if (d[u]>d[v]+1){
                d[u]=d[v]+1;
                q.push(u);
            }
        }
    }
    cout << cnt-1 << endl;
    cout << sum;
    return 0;
}
