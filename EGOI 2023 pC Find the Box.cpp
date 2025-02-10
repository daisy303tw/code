#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
int h, w, i, j;
void query(int x, int y){
    string s;
    for (int i=1;i<x;i++) s+="v";
    for (int i=1;i<y;i++) s+=">";
    cout << "? " << s << endl;
}
void ans(int i, int j){
    cout << "! " << i << " " << j << endl;
}
signed main(){
    starburst;
    cin >> h >> w;
    query(h, w);
    cin >> i >> j;
    if (i==h-1 && j==w-1){
        string down, up, r=">", weird="<^>";
        for (int i=1;i<h;i++){
            down+="v"; up+="^";
        }
        string s=down+r+up+weird, ss;
        for (int i=1;i<w;i++){
            ss+=s;
        }
        cout << "? " << ss << endl;
        cin >> i >> j;
        ans(i, j+1);
    }
    else if (i==h-1){
        ans(i, j+1);
    }
    else ans(i+1, 0);
    return 0;
}
/*

*/

