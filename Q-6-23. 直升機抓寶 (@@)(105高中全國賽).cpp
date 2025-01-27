#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
#define LO(x) x&(-x)
const int N=2.5e5+5;
int n;
int s, t;
int bit[N];
void build(){ memset(bit, 0, sizeof(bit)); }
void single_add(int i, int x){
    i++;
    while (i<=n){
        bit[i]+=x;
        i+=LO(i);
    }
}
int prefix_sum(int i){
    i++;
    int sum=0;
    while (i>0){
        sum+=bit[i];
        i-=LO(i);
    }
    return sum;
}
signed main(){
    starburst;
    cin >> n;
    build();
    for (int i=0;i<n;i++){
        cin >> s >> t;
        single_add(s, 1);
        single_add(t+1, -1);
        int now=prefix_sum(t);
        int l=t, r=n;
        while (l<r-1){
            int mid=(l+r)/2;
            if (prefix_sum(mid)>=now) r=mid;
            else l=mid;
        }
        single_add(t+1, 1);
        single_add(l+1, -1);
    }
    cout << prefix_sum(n-1);
    return 0;
}
