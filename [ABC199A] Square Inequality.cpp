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
int a, b, c;
signed main(){
    starburst;
    cin >> a >> b >> c;
    if (a*a+b*b<c*c) cout << "Yes";
    else cout << "No";
    return 0;
}
