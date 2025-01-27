#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
const int N=1e3+5, M=85, inf=1e18;
int n, m;
vector<int> child[N];
map<char,int> mp;
int dp[N][M][4];
int solve(int id, int num, int c){
    if (dp[id][num][c]>=0) return dp[id][num][c];
    if (child[id].empty()) return dp[id][num][c]=0;
    dp[id][num][c]=0;
    for (auto u:child[id]){
        int add=inf;
        for (int k=0;k<4;k++) add=min(add, solve(u, num, k)+(k!=c));
        dp[id][num][c]+=add;
    }
    return dp[id][num][c];
}
signed main(){
    starburst;
    #ifdef judge
    freopen("/Users/Eric/Desktop/input.txt","r",stdin);
    #endif // judge
    #ifdef random
    struct timeval T;
    gettimeofday(&T, NULL);
    srand(T.tv_usec);
    cout << rand();
    #endif // random
    mp['A']=0; mp['U']=1; mp['C']=2; mp['G']=3;
    cin >> n >> m;
    int i, j;
    string s;
    for (int now=0;now<n;now++){
        cin >> i >> j >> s;
        if (i!=j) child[j].pb(i);
        for (int d=0;d<m;d++){
            for (int k=0;k<4;k++){
                dp[i][d][k]=-1;
                if (s[d]!='@' && mp[s[d]]!=k) dp[i][d][k]=inf;
            }
        }
    }
    int ans=0;
    for (int k=0;k<m;k++){
        ans+=min({solve(1, k, 0), solve(1, k, 1), solve(1, k, 2), solve(1, k, 3)});
    }
    cout << ans;
}
