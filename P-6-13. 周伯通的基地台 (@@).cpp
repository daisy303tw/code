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
const int N=2e5+5;
int n, k;
int c[N];
int ans[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
signed main(){
    starburst;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> c[i];
    ans[1]=c[1];
    pq.push(pii(ans[1], 1LL));
    for (int i=2;i<=n;i++){
        if (i<=k+1) ans[i]=c[i];
        else {
            while (pq.top().S<i-2*k-1) pq.pop();
            ans[i]=pq.top().F+c[i];
        }
        pq.push(pii(ans[i], i));
    }
    cout << *min_element(ans+n-k, ans+n+1);
    return 0;
}
