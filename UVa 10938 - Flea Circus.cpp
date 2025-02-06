#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=5005, lgN=15;
int n, a, b, l;
int p[N][lgN], d[N];
vector<int> adj[N];
queue<int> q;
void init(){
    memset(p, -1, sizeof(p));
    for (int i=1;i<=n;i++){
        d[i]=0;
        adj[i].clear();
    }
}
void bfs(){
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (auto u:adj[v]){
            if (p[u][0]==-1){
                p[u][0]=v;
                q.push(u);
            }
        }
    }
}
void dfs(){
    for (int i=1;i<lgN;i++){
        for (int j=1;j<=n;j++){
            if (p[j][i-1]==-1) p[j][i]=-1;
            else p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
int depth(int v){
    if (d[v]>0) return d[v];
    if (v==1) return d[v]=1;
    return d[v]=depth(p[v][0])+1;
}
int lca(int x, int y){
    int dx=depth(x), dy=depth(y);
    if (dx>dy){ swap(x, y); swap(dx, dy); }
    dy-=dx;
    for (int i=0;i<lgN;i++) if (dy&(1<<i)) y=p[y][i];
    if (x==y) return x;
    for (int i=lgN-1;i>=0;i--){
        if (p[x][i]==p[y][i]) continue;
        x=p[x][i]; y=p[y][i];
    }
    return p[x][0];
}
signed main(){
    starburst;
    while (cin >> n){
        if (n==0) return 0;
        init();
        for (int i=0;i<n-1;i++){
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }
        q.push(1); bfs();
        dfs();
        cin >> l;
        while (l--){
            cin >> a >> b;
            int c=lca(a, b);
            if (depth(a)<depth(b)) swap(a, b);
//            int delta=depth(a)-depth(b);
//            int dis=depth(a)-delta;
            int dis=depth(a)+depth(b)-2*depth(c);
//            cout << dis << endl;
            vector<int> v1, v2;
            if (b==c){
                while (a!=c){
                    v1.pb(a);
                    a=p[a][0];
                }
                v1.pb(c);
            }
            else {
                while (a!=c){
                    v1.pb(a);
                    a=p[a][0];
                }
                v1.pb(c);
                while (b!=c){
                    v2.pb(b);
                    b=p[b][0];
                }
                reverse(all(v2));
                for (auto u:v2) v1.pb(u);
            }
//            for (auto u:v1){
//                cout << u << " ";
//            }
//            cout << endl;
            int siz=v1.size();
            if (siz%2==0){
                a=v1[siz/2-1], b=v1[siz/2];
                if (a>b) swap(a, b);
                cout << "The fleas jump forever between " << a << " and " << b << "." << endl;
            }
            else {
                a=v1[siz/2];
                cout << "The fleas meet at " << a << "." << endl;
            }
        }
    }
    return 0;
}
