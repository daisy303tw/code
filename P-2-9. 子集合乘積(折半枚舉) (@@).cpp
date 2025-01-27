//#define judge
//#define debug
#ifndef _WIN32
#include <sys/time.h>
#endif // _WIN32
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=40;
int n, p;
int a[N];
int cnt=0;
//multiset<int> st;
unordered_map<int,int> mp;
int pwo(int a, int n, int p){
    if (n==0) return 1;
    if (n%2==1) return pwo(a, n-1, p)*a%p;
    int x=pwo(a, n/2, p);
    return x*x%p;
}
int moni(int now){
    return pwo(now, p-2, p);
}
signed main(){
    starburst;
    #ifdef judge
    freopen("/Users/Eric/Desktop/input.txt","r",stdin);
    #endif // judge
    cin >> n >> p;
    for (int i=0;i<n;i++) cin >> a[i];
    int n2=n/2;
    for (int mask=1;mask<(1<<n2);mask++){
        int now=1;
        for (int i=0;i<n2;i++){
            if (mask&(1<<i)){
                now*=a[i];
                now%=p;
            }
        }
        if (now==1) cnt++;
        #ifdef debug
        if (now==1) cout << mask << endl;
        #endif // debug
        cnt%=p;
//        st.insert(moni(now));
        mp[moni(now)]++;
    }
    for (int mask=1;mask<(1<<n2);mask++){
        int now=1;
        for (int i=n2;i<n;i++){
            if (mask&(1<<(i-n2))){
                now*=a[i];
                now%=p;
            }
        }
        if (now==1) cnt++;
        #ifdef debug
        if (now==1) cout << mask << endl;
        #endif // debug
//        cnt+=st.count(now);
        cnt+=mp[now];
        #ifdef debug
        if (st.count(now)>0) cout << "now: " << now << endl;
        #endif // debug
        cnt%=p;
    }
    cout << cnt%p;
//    #ifndef _WIN32
//    struct timeval T;
//    gettimeofday(&T, NULL);
//    srand(T.tv_usec);
//    cout << rand();
//    #endif // _WIN32

//    #ifdef duipai
//    for (int i=0;i<10;i++){
//        system("./data > in.txt");
//        system("./std < in.txt > std.txt");
//        system("./baoli < in.txt > baoli.txt");
//        if (system("diff std.txt baoli.txt")){
//            cout << "WA" << endl;
//            return 0;
//        }
//    }
//    #endif // duipai
}
