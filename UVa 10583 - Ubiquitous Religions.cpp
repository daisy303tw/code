#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=5e4+5;
int n, m, x, y;
int parent[N];
int fiind(int x){
    if (parent[x]==x) return x;
    return parent[x]=fiind(parent[x]);
}
void join(int x, int y){
    int r1=fiind(x), r2=fiind(y);
    if (r1==r2) return;
    parent[r1]=r2;
}
signed main(){
    starburst;
    int cnt=1;
    while (cin >> n >> m){
        if (n==0 && m==0) return 0;
        for (int i=1;i<=n;i++) parent[i]=i;
        for (int i=0;i<m;i++){
            cin >> x >> y;
            join(x, y);
        }
        unordered_set<int> st;
        for (int i=1;i<=n;i++){
            int x=fiind(i);
            if (st.count(x)==0) st.insert(x);
        }
        cout << "Case " << cnt << ": " << st.size() << endl;
        cnt++;
    }
    return 0;
}
