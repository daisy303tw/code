#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define LO(x) x&(-x)
const int N=1e5+5;
int n, siz;
int bit[N];
int cnt=1;
void build(){
    memset(bit, 0, sizeof(bit));
}
void single_add(int i, int val){
    while (i<=siz){
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
    while (cin >> n){
        if (n==0) return 0;
        vector<int> a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        vector<int> v=a;
        sort(all(v));
        v.resize(unique(all(v))-v.begin());
        siz=v.size();
        build();
        int ans=0;
        for (auto i:a){
            int id=lower_bound(all(v), i)-v.begin();
            id++;
            ans+=prefix_sum(siz)-prefix_sum(id);
            single_add(id, 1);
        }
        cout << "Case #" << cnt << ": " << ans << endl;
        cnt++;
    }
    return 0;
}
