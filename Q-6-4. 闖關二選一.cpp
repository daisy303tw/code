#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
int n, t;
signed main(){
    starburst;
    cin >> n >> t;
    int a, b;
    int now1=0, now2=0, ans1=0, ans2=0;
    int c=t, d=t;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        ans1=min(abs(a-c)+now1, abs(a-d)+now2);
        ans2=min(abs(b-c)+now1, abs(b-d)+now2);
        c=a; d=b;
        now1=ans1; now2=ans2;
    }
    cout << min(ans1, ans2);
    return 0;
}

