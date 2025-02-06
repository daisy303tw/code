#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=2e5+5, MX=3e18+5;
int n, K;
int a[N], b[N], c[N];
priority_queue<int> pq;
int f(int i, int j, int k){ return a[i]*b[j]+b[j]*c[k]+c[k]*a[i]; }
signed main(){
    starburst;
    cin >> n >> K;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=n;i++) cin >> c[i];
    sort(a+1, a+n+1, greater<int>());
    sort(b+1, b+n+1, greater<int>());
    sort(c+1, c+n+1, greater<int>());
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n && i*j<=K;j++){
            for (int k=1;k<=n && i*j*k<=K;k++){
                pq.push(f(i, j, k));
            }
        }
    }
    K--;
    while (K--) pq.pop();
    cout << pq.top();
    return 0;
}
