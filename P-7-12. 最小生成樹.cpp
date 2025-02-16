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
#define piii pair<int,pii>
const int N=1e5+5;
int n, m;
int parent[N];
int ans=0;
priority_queue<piii, vector<piii>, greater<piii>> pq;
int fiind(int x){
    if (parent[x]==x) return x;
    return parent[x]=fiind(parent[x]);
}
void join(int x, int y, int w){
    int r1=fiind(x), r2=fiind(y);
    if (r1==r2) return;
    parent[r1]=r2;
    ans+=w;
}
signed main(){
    starburst;
    cin >> n >> m;
    for (int i=0;i<n;i++) parent[i]=i;
    int u, v, w;
    for (int i=0;i<m;i++){
        cin >> u >> v >> w;
        pq.push(piii(w, pii(u, v)));
    }
    while (!pq.empty()){
        auto it=pq.top(); pq.pop();
        int w=it.F, u=it.S.F, v=it.S.S;
        join(u, v, w);
    }
    int root=fiind(0);
    bool flag=1;
    for (int i=1;i<n;i++){
        if (fiind(i)!=root){
            flag=0; break;
        }
    }
    if (!flag) cout << -1;
    else cout << ans;
    return 0;
}
