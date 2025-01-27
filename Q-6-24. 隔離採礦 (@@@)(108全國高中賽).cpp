#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=1e6+5;
int n;
int h[N], v[N];
int dp[N];
int domx[N], mx[N];
stack<int> sk1, sk2;
signed main(){
    starburst;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> h[i];
    for (int i=1;i<=n;i++) cin >> v[i];
    for (int i=1;i<=n;i++){
        while (!sk1.empty() && h[sk1.top()]<h[i]){
            domx[i]=max(domx[i], max(domx[sk1.top()], dp[sk1.top()]));
            sk1.pop();
        }
        while (!sk2.empty() && h[sk2.top()]<=h[i]){
            sk2.pop();
        }
        if (sk1.empty()){
            dp[i]=v[i];
            mx[i]=domx[i];
        }
        else {
            dp[i]=v[i];
            mx[i]=max(mx[sk1.top()], domx[i]);
            if (!sk2.empty()) dp[i]+=mx[sk2.top()];
        }
        sk1.push(i); sk2.push(i);
    }
    cout << *max_element(dp+1, dp+n+1);
    return 0;
}
