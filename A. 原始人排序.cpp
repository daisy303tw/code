#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define F first
#define S second
const int N=1005;
int n;
pair<pii, int> a[N];
signed main(){
    starburst;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i].S;
        a[i].F.F=__builtin_popcount(a[i].S);
        a[i].F.S=i;
    }
    sort(a, a+n);
    for (int i=0;i<n;i++) cout << a[i].S << " ";
    return 0;
}
