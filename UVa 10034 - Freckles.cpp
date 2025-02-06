#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
const int N=105;
int t, n;
int parent[N];
double len(pdd x, pdd y){
    return sqrt((x.F-y.F)*(x.F-y.F)+(x.S-y.S)*(x.S-y.S));
}
int fiind(int x){
    if (parent[x]==x) return x;
    return parent[x]=fiind(parent[x]);
}
void join(int x, int y){
    int r1=fiind(x), r2=fiind(y);
    parent[r1]=r2;
}
signed main(){
    starburst;
    cin >> t;
    while (t--){
        cin >> n;
        vector<pdd> v(n);
        for (int i=0;i<n;i++) cin >> v[i].F >> v[i].S;
        vector<pair<double,pii>> edges;
        for (int i=0;i<n;i++){
            parent[i]=i;
            for (int j=i+1;j<n;j++){
                edges.pb(make_pair(len(v[i], v[j]), make_pair(i, j)));
            }
        }
        sort(all(edges));
        int cnt=0;
        double ans=0;
        for (auto it:edges){
            double w=it.F;
            int x=it.S.F, y=it.S.S;
            if (fiind(x)!=fiind(y)){
                join(x, y);
                cnt++;
                ans+=w;
            }
            if (cnt==n-1) break;
        }
        cout << fixed << setprecision(2) << ans << endl;
        cout << endl;
    }
    return 0;
}
