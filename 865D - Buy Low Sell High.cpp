#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=3e5+5;
int n, p;
priority_queue<int, vector<int>, greater<int>> pq;
int ans=0;
signed main(){
    starburst;
    cin >> n;
    while (n--){
        cin >> p;
        pq.push(p);
        if (pq.top()<p){
            int it=pq.top(); pq.pop();
            ans+=(p-it);
            pq.push(p);
        }
    }
    cout << ans;
    return 0;
}
