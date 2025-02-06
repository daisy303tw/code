#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define LO(x) x&(-x)
const int N=5e5+5;
int n, q, opt, p, x, l, r;
int bit[N];
void build(){
    memset(bit, 0, sizeof(bit));
}
void single_add(int i, int val){
    while (i<=n){
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
    cin >> n >> q;
    build();
    for (int i=1;i<=n;i++){
        cin >> x;
        single_add(i, x);
    }
    while (q--){
        cin >> opt;
        if (opt==0){
            cin >> p >> x;
            p++;
            single_add(p, x);
        }
        else {
            cin >> l >> r;
            l++; r++;
            cout << prefix_sum(r-1)-prefix_sum(l-1) << endl;
        }
    }
    return 0;
}
