#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define F first
#define S second
#define LO(x) x&(-x)
const int N=1e5+5;
int n;
int bit[N], cnt[N];
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
    cin >> n;
    vector<pii> a(n);
    for (int i=0;i<n;i++) cin >> a[i].F >> a[i].S;
    sort(all(a));
    for (int i=0;i<n;i++){
        cnt[prefix_sum(a[i].S)]++;
        single_add(a[i].S, 1);
    }
    for (int i=0;i<n;i++) cout << cnt[i] << endl;
    return 0;
}
