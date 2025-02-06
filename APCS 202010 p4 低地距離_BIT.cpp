#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define LO(x) x&(-x)
const int N=2e5+5;
int n, x;
int bit[N];
bool existed[N]={0};
int le[N];
void build(){
    memset(bit, 0, sizeof(bit));
}
void single_add(int i, int val){
    while (i<=2*n){
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
    cin >> n;
    int ans=0;
    for (int i=0;i<2*n;i++){
        cin >> x;
        if (existed[x]){
            ans+=prefix_sum(x-1)-le[x];
        }
        else {
            le[x]=prefix_sum(x-1);
            existed[x]=1;
        }
        single_add(x, 1);
    }
    cout << ans;
    return 0;
}
