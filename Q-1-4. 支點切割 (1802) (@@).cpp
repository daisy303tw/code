#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
const int N=5e4+5, inf=1e18;
int n, K;
int p[N], pii[N], pi[N];
int sum=0;
void cut(int s, int t, int k){
    if (k>K || t-s+1<3) return;
//    double goal=(double)(pii[t]-pii[s-1])/(double)(pi[t]-pii[s-1]);
    int a=pii[t]-pii[s-1];
    int b=pi[t]-pi[s-1];
    int m;
//    int m=round(goal);
//    if (m-goal==0.5) m--;
//    if (m==t) m--;
//    if (m==s) m++;
    int now=inf;
    for (int i=s+1;i<t;i++){
        if (abs(a-i*b)<now){
            now=abs(a-i*b);
            m=i;
        }
    }
//    cout << m << endl;
    sum+=p[m];
    cut(s, m-1, k+1); cut(m+1, t, k+1);
}
signed main(){
    starburst;
//    freopen("/Users/Eric/Downloads/Q_1_4_1.in", "r", stdin);
    cin >> n >> K;
    pii[0]=pi[0]=0;
    for (int i=1;i<=n;i++){
        cin >> p[i];
        pii[i]=pii[i-1]+p[i]*i;
        pi[i]=pi[i-1]+p[i];
    }
    cut(1, n, 1);
    cout << sum;
    return 0;
}
