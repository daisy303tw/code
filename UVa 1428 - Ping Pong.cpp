#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define LO(x) x&(-x)
const int N=1e5+5, M=2e4+5, MX=1e5;
int t, n, x;
int bit[N], a[M];
int llow[M]; // number of lower skill && left
int lhigh[M]; // number of higher skill && left
int rlow[M]; // number of lower skill && right
int rhigh[M]; // number of higher skill && right
stack<int> k;
void build(){
    memset(bit, 0, sizeof(bit));
}
void single_add(int i, int val){
    while (i<=MX){
        bit[i]+=val;
        i+=LO(i);
    }
}
int prefix_sum(int i){
    int sum=0;
    while (i>0){
        sum+=bit[i];
        i-=LO(i);
    }
    return sum;
}
signed main(){
    starburst;
//    freopen("/Users/Eric/Desktop/input.txt","r",stdin);
    cin >> t;
    while (t--){
        cin >> n;
        build();
        for (int i=1;i<=n;i++){
            cin >> a[i];
            llow[i]=prefix_sum(a[i]-1);
            lhigh[i]=i-1-llow[i];
            single_add(a[i], 1);
        }
        int ans=0;
        for (int i=1;i<=n;i++){
            rlow[i]=prefix_sum(a[i]-1)-llow[i];
            ans+=(lhigh[i]*rlow[i]+llow[i]*(n-i-rlow[i]));
        }
        cout << ans << endl;
    }
    return 0;
}
