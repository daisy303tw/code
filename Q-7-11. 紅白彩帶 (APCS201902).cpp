#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e5+5;
int n, k;
bool a[N];
int parent[N], siz[N];
multiset<int> st;
int mx=0, mn=0;
int fiind(int x){
    if (parent[x]==x) return x;
    return parent[x]=fiind(parent[x]);
}
void join(int x, int y){
    int r1=fiind(x), r2=fiind(y);
    if (r1==r2) return;
    if (siz[r1]>siz[r2]) swap(r1, r2);
    siz[r1]=siz[r2]=siz[r1]+siz[r2];
    parent[r1]=r2;
}
signed main(){
    starburst;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        parent[i]=i;
        siz[i]=1;
        if (a[i-1]==1 && a[i]==1) join(i, i-1);
    }
    for (int i=1;i<=n;i++){
        if (a[i]==1 && fiind(i)==i) st.insert(siz[i]);
    }
    mx+=(*st.rbegin());
    mn+=(*st.begin());
    int x;
    while (k--){
        cin >> x;
        if (a[x-1]==1 && a[x+1]==1){
            st.erase(st.find(siz[fiind(x-1)]));
            st.erase(st.find(siz[fiind(x+1)]));
            join(x-1, x); join(x+1, x);
            st.insert(siz[fiind(x)]);
        }
        else if (a[x-1]==1){
            st.erase(st.find(siz[fiind(x-1)]));
            join(x-1, x);
            st.insert(siz[fiind(x)]);
        }
        else if (a[x+1]==1){
            st.erase(st.find(siz[fiind(x+1)]));
            join(x+1, x);
            st.insert(siz[fiind(x)]);
        }
        else st.insert(1);
        a[x]=1;
        mx+=(*st.rbegin());
        mn+=(*st.begin());
    }
    cout << mx << endl;
    cout << mn << endl;
    return 0;
}
