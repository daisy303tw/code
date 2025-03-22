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
int a=1, b=1000, x;
signed main(){
    starburst;
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> x;
        a=max(a, x);
    }
    for (int i=1;i<=n;i++){
        cin >> x;
        b=min(b, x);
    }
    cout << max(0LL, b-a+1);
    return 0;
}

