//#define judge
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=2e6+5; //, d=1e6;
int n, sum=0, now=0, cnt, q, fro, to, on;
//int a[N];
unordered_map<int,int> a;
string s;
int x, y;
signed main(){
    starburst;
    #ifdef judge
    freopen("/home/user/Desktop/input.txt","r",stdin);
    #endif
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x;
        on=x;
        sum+=x;
//        a[d+x]++;
        a[x]++;
    }
    cin >> q;
    if (n==1){
        while (q--){
            cin >> s >> x;
            if (s=="INFLATION"){
                on+=x;
                cout << on << endl;
            }
            else {
                cin >> y;
                if (on==x) on=y;
                cout << on << endl;
            }
        }
        return 0;
    }
    while (q--){
        cin >> s >> x;
        if (s=="INFLATION"){
            now+=x;
            sum+=(x*n);
            cout << sum << endl;
        }
        else {
            cin >> y;
//            fro=d+x-now;
            fro=x-now;
//            to=d+y-now;
            to=y-now;
            cnt=a[fro];
            a[fro]=0;
            a[to]+=cnt;
            sum+=(y-x)*cnt;
            cout << sum << endl;
        }
    }
    return 0;
}
/*
5
2 1 1 2 5
6
INFLATION 1
SET 3 2
SET 5 2
INFLATION 4
SET 6 1
SET 10 1

*/

