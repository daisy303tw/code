#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
//const int N=
int t, n, x, y;
string opt;
int fiind(int x, vector<int>& parent){
    if (parent[x]==x) return x;
    return parent[x]=fiind(parent[x], parent);
}
void join(int x, int y, vector<int>& parent){
    int r1=fiind(x, parent), r2=fiind(y, parent);
    if (r1==r2) return;
    parent[r1]=r2;
}
signed main(){
    starburst;
    cin >> t;
    cin >> n;
    while (t--){
        vector<int> parent(n+1);
        for (int i=1;i<=n;i++) parent[i]=i;
        int good=0, bad=0;
        while (cin >> opt){
            if (opt=="c"){
                cin >> x >> y;
                join(x, y, parent);
            }
            else if (opt=="q"){
                cin >> x >> y;
                if (fiind(x, parent)==fiind(y, parent)) good++;
                else bad++;
            }
            else {
                n=stoi(opt);
                break;
            }
        }
        cout << good << "," << bad << endl << endl;
    }
    return 0;
}
