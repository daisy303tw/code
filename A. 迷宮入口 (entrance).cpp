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
const int N=2500;
int n, r, x, y;
set<pii> st;
bool ok(int i, int j, int x, int y){
    return ((i-x)*(i-x)+(j-y)*(j-y)<=r*r);
}
signed main(){
    starburst;
    cin >> n >> r;
    for (int k=0;k<n;k++){
        cin >> x >> y;
        for (int i=x-r;i<=x+r;i++){
            for (int j=y-r;j<=y+r;j++){
                if (ok(i, j, x, y)){
                    if (st.count(pii(i, j))){
                        st.erase(pii(i, j));
                    }
                    else st.insert(pii(i, j));
                }
            }
        }
    }
    cout << st.size();
    return 0;
}
