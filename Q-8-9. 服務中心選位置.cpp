#ifndef _WIN32
#include <sys/time.h>
#endif // _WIN32
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=1e5+5;
int n, u, v;
vector<int> adj[N];
int parent[N];
bool visited[N];
bool picked[N], dominated[N];
stack<int> k;
void dfs(int v){
    k.push(v);
    for (auto u:adj[v]){
        if (!visited[u]){
            visited[u]=1;
            parent[u]=v;
            dfs(u);
        }
    }
}
signed main(){
    starburst;
    #ifdef judge
    freopen("/Users/Eric/Desktop/input.txt","r",stdin);
    #endif // judge
    cin >> n;
    for (int i=0;i<n-1;i++){
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    visited[1]=1;
    parent[1]=1;
    dfs(1);
    int ans=0;
    while (!k.empty()){
        v=k.top(); k.pop();
        if (!dominated[v]){
            if (!picked[parent[v]]){
                picked[parent[v]]=1; ans++;
            }
            dominated[v]=dominated[parent[v]]=dominated[parent[parent[v]]]=1;
        }
    }
    cout << ans;
}
#ifdef findprime
void pre(int n){
    bool notprime[N];
    vector<int> prime;
    for (int i=2;i<=n;i++){
        if (!notprime[i]) prime.pb(i);
        for (auto j:prime){
            if (j*i>n) break;
            notprime[j*i]=1;
            if (i%j==0) break;
        }
    }
}
#endif // findprime
#ifdef random
    struct timeval T;
    gettimeofday(&T, NULL);
    srand(T.tv_usec);
    cout << rand();
    #endif // random
    #ifdef duipai
    for (int i=0;i<10;i++){
        double c=clock();
        system("./data > in.txt");
        system("./std < in.txt > std.txt");
        system("./baoli < in.txt > baoli.txt");
        if (system("diff std.txt baoli.txt")){
            cout << "WA" << endl; return 0;
        }
        double d=clock();
        if (d-c>1000) cout << "TLE" << endl;
    }
    #endif // duipai
