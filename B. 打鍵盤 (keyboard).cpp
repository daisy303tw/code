#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define F first
#define S second
const int N=1e4+5, inf=1e9;
int dp[N][30][30];
int dis[30][30];
string s1="QWERTYUIOP";
string s2="ASDFGHJKL";
string s3="ZXCVBNM";
int n;
string s;
void pre(){
    memset(dis, 0x3f, sizeof(dis));
    memset(dp, 0x3f, sizeof(dp));
    for (int i=0;i<26;i++) dis[i][i]=0;
    for (int i=0;i+1<s1.size();i++){
        int u=s1[i]-'A', v=s1[i+1]-'A';
        dis[u][v]=dis[v][u]=1;
    }
    for (int i=0;i+1<s2.size();i++){
        int u=s2[i]-'A', v=s2[i+1]-'A';
        dis[u][v]=dis[v][u]=1;
    }
    for (int i=0;i+1<s3.size();i++){
        int u=s3[i]-'A', v=s3[i+1]-'A';
        dis[u][v]=dis[v][u]=1;
    }
    for (int i=0;i<s2.size();i++){
        int u=s2[i]-'A', v=s1[i]-'A';
        dis[u][v]=dis[v][u]=1;
        v=s1[i+1]-'A';
        dis[u][v]=dis[v][u]=1;
    }
    for (int i=0;i<s3.size();i++){
        int u=s3[i]-'A', v=s2[i]-'A';
        dis[u][v]=dis[v][u]=1;
        v=s2[i+1]-'A';
        dis[u][v]=dis[v][u]=1;
    }
    for (int k=0;k<26;k++){
        for (int i=0;i<26;i++){
            for (int j=0;j<26;j++){
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
//    cerr << dis['Q'-'A']['M'-'A'] << endl;
//    cerr << dis[0][0] << endl;
    for (int i=0;i<26;i++){
        for (int j=0;j<26;j++){
            dp[0][i][j]=dis[i]['F'-'A']+dis[j]['J'-'A'];
        }
    }
}
signed main(){
    starburst;
    pre();
    cin >> n >> s;
    for (int i=1;i<=n;i++){
        int now=s[i-1]-'A';
        for (int j=0;j<26;j++){
            int mn1=inf, mn2=inf;
            for (int k=0;k<26;k++){
                mn1=min(mn1, dp[i-1][k][j]+dis[k][now]);
                mn2=min(mn2, dp[i-1][j][k]+dis[k][now]);
            }
            dp[i][now][j]=mn1;
            dp[i][j][now]=mn2;
        }
    }
    int mn=inf;
    for (int i=0;i<26;i++){
        mn=min(mn, dp[n][i][s[n-1]-'A']);
        mn=min(mn, dp[n][s[n-1]-'A'][i]);
    }
    cout << mn;
    return 0;
}

