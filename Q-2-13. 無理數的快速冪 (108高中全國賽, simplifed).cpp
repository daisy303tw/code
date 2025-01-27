//#define judge
//#define debug
//#ifndef _WIN32
//#include <sys/time.h>
//#endif // _WIN32
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int p=1e9+9;
int n;
struct ss{
    int s;
    int t;
};
ss a;
ss operator*(ss a, ss b){
    ss c;
    c.s=((a.s*b.s)%p+(2*a.t*b.t)%p)%p;
    c.t=((a.s*b.t)%p+(a.t*b.s)%p)%p;
    return c;
}
ss pwo(ss a, int n){
    if (n==1) return a;
    if (n%2==1) return a*pwo(a, n-1);
    ss t=pwo(a, n/2);
    return t*t;
}
signed main(){
    starburst;
    #ifdef judge
    freopen("/Users/Eric/Desktop/input.txt","r",stdin);
    #endif // judge
    cin >> a.s >> a.t >> n;
    ss ans=pwo(a, n);
    cout << ans.s << " " << ans.t;
//    #ifndef _WIN32
//    struct timeval T;
//    gettimeofday(&T, NULL);
//    srand(T.tv_usec);
//    cout << rand();
//    #endif // _WIN32
    return 0;
}
