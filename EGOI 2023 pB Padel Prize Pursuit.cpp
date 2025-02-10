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
const int N=2e5+5;
int n, m;
vector<int> g[N];
vector<int> who(N), len(N), cnt(N);
priority_queue<pii> pq;
vector<int> ans(N);
void merge_medal(int x, int y){
    len[x]=y-x; g[y].pb(x);
}
void dfs(int now){
    cnt[who[now]]+=len[now];
    pq.push(pii(cnt[who[now]], -who[now]));
    while (!pq.empty() && cnt[-pq.top().S]!=pq.top().F) pq.pop();
    ans[-pq.top().S]++;
    for (auto i:g[now]) dfs(i);
    cnt[who[now]]-=len[now];
    pq.push(pii(cnt[who[now]], -who[now]));
}
signed main(){
    starburst;
    cin >> n >> m;
    vector<int> lst(n, -1);
    int x, y;
    for (int i=0;i<m;i++){
        cin >> x >> y;
        who[i]=x;
        if (lst[x]!=-1) merge_medal(lst[x], i);
        if (lst[y]!=-1) merge_medal(lst[y], i);
        lst[y]=-1; lst[x]=i;
    }
    for (int i=0;i<n;i++){
        if (lst[i]==-1) continue;
        int id=lst[i];
        len[id]=m-id;
        dfs(id);
    }
    for (int i=0;i<n;i++) cout << ans[i] << " ";
    return 0;
}
