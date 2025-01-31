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
const int N=1e5+5, K=(1LL<<30);
int n, k;
pii s[N];
int now, sum, ans=0;
signed main(){
    starburst;
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> s[i].F >> s[i].S;
    k++; // !
    for (int i=0;i<=30;i++){
        if ((k>>i)&1){
            now=((k>>i)^1)<<i; now|=((1<<i)-1);
            sum=0;
            for (int i=0;i<n;i++){
                if ((s[i].F&now)==s[i].F) sum+=s[i].S;
            }
        }
        ans=max(ans, sum);
    }
    cout << ans;
    return 0;
}
