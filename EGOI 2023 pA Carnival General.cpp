//#define judge
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1005;
int n;
int a[N][N];
struct ss{
    int to;
}s[N];
bool ok(int i, int j){
//    if (i==j) return 0;
//    if (i>j) return (a[i][j]<=((i-1)/2));
//    return (a[j][i]<=((j-1)/2));
    return a[i][j];
}
signed main(){
    starburst;
    #ifdef judge
    freopen("/home/user/Desktop/input.txt","r",stdin);
    #endif
    cin >> n;
    int aa;
    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            cin >> aa;
            if (2*j<i) a[i][aa]=a[aa][i]=1;
            else a[i][aa]=a[aa][i]=0;
//            if (a[i][j]==0) cerr << "no: " << i << " " << j << endl;
        }
    }
//    for (int i=1;i<n;i++){
//        for (int j=0;j<i;j++){
//            cerr << a[i][j] << " ";
//        }
//        cerr << endl;
//    }
//    s[0].to=1;
//    int head=0, tail=1;
    s[1].to=0;
    int head=1, tail=0;
    for (int i=2;i<n;i++){
        int x=head;
        if (ok(i, head)){
            s[i].to=head;
            head=i; continue;
        }
        else if (ok(i, tail)){
            s[tail].to=i;
            tail=i; continue;
        }
        else while (x!=tail){
            int too=s[x].to;
            if (ok(i, x) && ok(i, too)){
                s[x].to=i;
                s[i].to=too;
                break;
            }
            x=s[x].to;
        }
    }
    int y=head;
    while (y!=tail){
        cout << y << " ";
        y=s[y].to;
    }
    cout << y << endl;
    return 0;
}
