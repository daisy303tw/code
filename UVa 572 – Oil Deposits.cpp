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
const int N=105;
int m, n;
char a[N][N];
map<pii, pii> mp;
pii fiind(pii x){
    if (mp[x]==x) return x;
    return mp[mp[x]]=fiind(mp[x]);
}
void join(pii x, pii y){
    pii r1=fiind(x), r2=fiind(y);
    if (r1==r2) return;
    mp[r1]=r2;
}
signed main(){
    starburst;
    while (cin >> m >> n){
        if (m==0) return 0;
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                mp[make_pair(i, j)]=make_pair(i, j);
            }
        }
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                cin >> a[i][j];
                if (a[i][j]=='*') continue;
                if (i>1 && a[i-1][j]=='@')
                    join(make_pair(i, j), make_pair(i-1, j));
                if (j>1 && a[i][j-1]=='@')
                    join(make_pair(i, j), make_pair(i, j-1));
                if (i>1 && j>1 && a[i-1][j-1]=='@')
                    join(make_pair(i, j), make_pair(i-1, j-1));
                if (i>1 && j+1<=n && a[i-1][j+1]=='@')
                    join(make_pair(i, j), make_pair(i-1, j+1));
            }
        }
        set<pii> st;
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                if (a[i][j]=='*') continue;
                pii it=fiind(make_pair(i, j));
                if (st.count(it)==0) st.insert(it);
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}
