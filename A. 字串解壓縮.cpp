#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
string s;
signed main(){
    starburst;
    cin >> s;
    int num=0;
    for (int i=0;i<s.size();i++){
//        cout << s[i] << " " << (s[i]>='a' && s[i]<='z') << endl;
        if (s[i]>='a' && s[i]<='z'){
            if (num==0) num++;
            for (int j=0;j<num;j++) cout << s[i];
            num=0;
        }
        else {
            num*=10;
            num+=(s[i]-'0');
        }
    }
    return 0;
}
