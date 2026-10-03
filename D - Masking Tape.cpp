#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define F first 
#define S second
const int inf=1e9;
const int N=3e5+5;
char color[N];
int tile[N]; // the last time to be placed on a tile (-1 if never)
int full[N]; // has tile or not
int removedat[N]; // last time to be removed
#define pic pair<int,char>
struct ss{
    int op;
    int x;
    char c;
}s[N];
signed main(){
    starburst;
    int n, q;
    cin >> n >> q;
    for (int i=1;i<=n;i++){
        color[i]='a';
        tile[i]=-1;
        full[i]=0;
        removedat[i]=0;
    }
    int lastcolortime=0;
    for (int t=1;t<=q;t++){ // t=time
        cin >> s[t].op;
        if (s[t].op==1){
            cin >> s[t].x;
        }
        else {
            lastcolortime=t;
            cin >> s[t].c;
        }
    }
    vector<int> colortimes;
    // colortimes.pb(0);
    int time=0;
    // map<int,char> mp;
    // mp[0]='a';
    char cc='a'; // last color
    for (int t=1;t<=q;t++){
        if (t>lastcolortime) break;
        if (s[t].op==1){
            int pos=s[t].x;
            if (full[pos]==0){
                // auto it=lower_bound(all(colortimes), t);
                // it--;
                // color[pos]=mp[*(it)];
                if (time>removedat[pos]) color[pos]=cc;
                // cerr << pos << " " << color[pos] << endl;
                tile[pos]=t;
                full[pos]=1;
            }
            else {
                full[pos]=0;
                removedat[pos]=t;
            }
        }
        else {
            // colortimes.pb(t);
            // mp[t]=s[t].c;
            time=t;
            cc=s[t].c;
            // cerr << t << " " << mp[t] << endl;
        }
    }
    // for (auto p:mp){
    //     cerr << p.F << " " << p.S << endl;
    // }
    // for (int i=1;i<=n;i++) cerr << i << " " << color[i] << endl;
    for (int i=1;i<=n;i++){
        // cerr << endl << i << ": ";
        if (full[i]==0){
            // cout << mp[lastcolortime];
            cout << cc;
            // cerr << " (if)" << endl;
        }
        else cout << color[i];
    }
    return 0;
}
