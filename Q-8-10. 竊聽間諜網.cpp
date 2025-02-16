#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5;
int n;
int p[N], deg[N], yes[N];
signed main(){
    starburst;
    cin >> n;
    for (int i=1;i<=n-1;i++){
        cin >> p[i];
        deg[p[i]]++;
    }
    queue<int> q;
    for (int i=1;i<=n-1;i++){
        if (deg[i]==0) q.push(i);
    }
    int cnt=0;
    while (!q.empty()){
        int v=q.front(); q.pop();
        if (v==0) break;
        if (!yes[v]) yes[p[v]]=1;
        else cnt++;
        if (--deg[p[v]]==0) q.push(p[v]);
    }
    if (yes[0]) cnt++;
    cout << cnt;
    return 0;
}
