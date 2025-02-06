#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=5005;
int n, x, y, z;
priority_queue<int, vector<int>, greater<int>> pq;
signed main(){
    starburst;
    while (cin >> n){
        int ans=0;
        if (n==0) return 0;
        for (int i=0;i<n;i++){
            cin >> x; pq.push(x);
        }
        while (pq.size()>1){
            x=pq.top(); pq.pop();
            y=pq.top(); pq.pop();
            pq.push(x+y);
            ans+=x+y;
        }
        cout << ans << endl;
        pq.pop();
    }
    return 0;
}
