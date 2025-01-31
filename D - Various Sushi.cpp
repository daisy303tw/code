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
const int N=1e5+5;
int n, k, t, d;
pii a[N];
priority_queue<pii> pq;
bool exist[N]={0};
stack<pii> sk;
int dp[N];
int sum=0;
signed main(){
    starburst;
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> t >> d;
        pq.push(make_pair(d, t));
    }
    int x=0;
    for (int i=0;i<k;i++){
        auto it=pq.top(); pq.pop();
        d=it.F; t=it.S;
        if (!exist[t]) x++;
        else sk.push(make_pair(d, t));
        exist[t]=1;
        sum+=d;
    }
    dp[x]=sum+x*x;
    int dd, tt;
    while (!sk.empty() && !pq.empty()){
        auto it=pq.top(); pq.pop();
        d=it.F; t=it.S;
        if (exist[t]) continue;
        exist[t]=1;
        auto ti=sk.top(); sk.pop();
        dd=ti.F; tt=ti.S;
        sum-=dd; sum+=d;
        x++;
        dp[x]=sum+x*x;
    }
    cout << *max_element(dp, dp+n+1);
    return 0;
}
