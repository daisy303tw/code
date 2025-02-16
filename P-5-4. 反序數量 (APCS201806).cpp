#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define LO(x) x&(-x)
const int N=1e5+5, MX=1e6;
int n, x;
int bit[MX+5];
void build(){
    fill(bit, bit+MX+5, 0);
}
void single_add(int i, int x){
    while (i<=MX+4){
        bit[i]+=x;
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
    cin >> n;
    int cnt=0;
    cin >> x;
    single_add(x, 1);
    for (int i=1;i<n;i++){
        cin >> x;
        cnt+=prefix_sum(MX)-prefix_sum(x);
        single_add(x, 1);
    }
    cout << cnt;
    return 0;
}
