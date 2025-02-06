#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
const int N=15;
int n;
string s, ss, to;
vector<int> v;
signed main(){
    starburst;
    cin >> n;
    cin >> s;
    to=s;
    while (to.size()>1){
        int siz=to.size();
        ss="";
        for (int i=0;i<siz;i+=3){
            int cnt=(to[i]-'0'+to[i+1]-'0'+to[i+2]-'0');
            if (cnt>=2) ss+="1";
            else ss+="0";
        }
        to=ss;
    }
    int mx=pow(3, n);
    for (int i=0;i<mx;i+=3){
        int cnt=(s[i]-'0'+s[i+1]-'0'+s[i+2]-'0');
        if (to=="1") v.pb(max(0LL, cnt-1));
        else v.pb(max(0LL, 3-cnt-1));
    }
    while (v.size()>1){
        vector<int> now;
        int siz=v.size();
        for (int i=0;i<siz;i+=3){
            vector<int> three;
            three.pb(v[i]); three.pb(v[i+1]); three.pb(v[i+2]);
            sort(all(three));
            now.pb(three[0]+three[1]);
        }
        v=now;
    }
    cout << v[0];
    return 0;
}


