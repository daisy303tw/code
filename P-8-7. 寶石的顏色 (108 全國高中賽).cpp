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
const int N=2e5+5;
int n;
int c[N];
vector<int> adj[N];
unordered_map<int,int> mp;
int ans=0;
void dfs(int v){
    mp[c[v]]++;
    ans=max(ans, mp[c[v]]);
    for (auto u:adj[v]){
        dfs(u);
    }
    mp[c[v]]--;
}
signed main(){
    starburst;
    cin >> n;
    for (int i=0;i<n;i++) cin >> c[i];
    int s, t;
    for (int i=0;i<n-1;i++){
        cin >> s >> t;
        adj[s].pb(t);
    }
    dfs(0);
    cout << ans;
    return 0;
}
