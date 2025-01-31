#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=2e5+5;
int n;
int a[N], b[N], s=0;
bool flag1=0, flag2=0;
int p, q;
signed main(){
    starburst;
    cin >> n;
    b[1]=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        b[1]+=a[i];
    }
    for (int i=2;i<=n;i++){
        b[i]=b[i-1]-a[i-1];
        s+=b[i];
        if (b[i]<0) flag1=1;
        else if (b[i]>0) flag2=1;
        if (b[i]==-1) p=i;
        else if (b[i]==1) q=i;
    }
    if (b[1]>0){
        cout << "Yes" << endl;
        cout << -s << " ";
        int now=-s;
        for (int i=2;i<=n;i++){
            now+=b[1]; cout << now << " ";
        }
    }
    else if (b[1]<0){
        cout << "Yes" << endl;
        cout << s << " ";
        int now=s;
        for (int i=2;i<=n;i++){
            now-=b[1]; cout << now << " ";
        }
    }
    else if (flag1==1 && flag2==1){
        cout << "Yes" << endl;
        if (s>=0){
            int now=0;
            for (int i=1;i<=n;i++){
                now+=1+((i==p)?s:0);
                cout << now << " ";
            }
        }
        else {
            int now=0;
            for (int i=1;i<=n;i++){
                now+=1+((i==q)?-s:0);
                cout << now << " ";
            }
        }
    }
    else cout << "No" << endl;
    return 0;
}
