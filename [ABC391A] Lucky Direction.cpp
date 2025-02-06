#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
string d;
signed main(){
    starburst;
    cin >> d;
    if (d=="N") cout << "S";
    if (d=="S") cout << "N";
    if (d=="W") cout << "E";
    if (d=="E") cout << "W";
    if (d=="NE") cout << "SW";
    if (d=="SW") cout << "NE";
    if (d=="NW") cout << "SE";
    if (d=="SE") cout << "NW";
    return 0;
}
