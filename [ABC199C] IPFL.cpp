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
int n, q, t, a, b;
string s;
bool flag=0;
signed main(){
    starburst;
    cin >> n >> s;
    cin >> q;
    while (q--){
        cin >> t >> a >> b;
        a--, b--;
        if (t==2) flag=(!flag);
        else {
            if (flag){
                if (a>=n) a-=n;
                else a+=n;
                if (b>=n) b-=n;
                else b+=n;
            }
            swap(s[a], s[b]);
        }
//        if (flag){
//            for (int i=n;i<2*n;i++) cerr << s[i];
//            for (int i=0;i<n;i++) cerr << s[i];
//        }
//        else cerr << s;
//        cerr << endl;
    }
    if (flag){
        for (int i=n;i<2*n;i++) cout << s[i];
        for (int i=0;i<n;i++) cout << s[i];
    }
    else cout << s;
    return 0;
}

