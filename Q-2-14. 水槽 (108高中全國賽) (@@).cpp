#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define F first
#define S second
#ifndef _WIN32
#include <sys/time.h>
#endif // _WIN32
const int N=1e5+5;
int n, in, w, x;
priority_queue<pii> pq;
int h[N];
void solve(int l, int r, int water, int input){
    if (l==r){ h[l]=water; return; }
    pii it;
    while (!pq.empty()){
        it=pq.top(); pq.pop();
        if (l<=it.S && it.S<r) break;
    }
    int hh=it.F;
    if (water>=(r-l)*hh){
        x=water/(r-l);
        for (int i=l;i<r;i++) h[i]=x;
        return;
    }
    int pos=it.S;
    if (input<pos){
        if (water<(pos-l)*hh) solve(l, pos, water, input);
        else {
            for (int i=l;i<pos;i++) h[i]=hh;
            solve(pos, r, water-hh*(pos-l), pos);
        }
    }
    else {
        if (water<(r-pos)*hh) solve(pos, r, water, input);
        else {
            for (int i=pos;i<r;i++) h[i]=hh;
            solve(l, pos, water-hh*(r-pos), pos);
        }
    }
}
signed main(){
    starburst;
    #ifdef judge
    freopen("/Users/Eric/Desktop/input.txt","r",stdin);
    #endif // judge
    cin >> n >> in >> w;
    for (int i=0;i<n;i++){
        cin >> x;
        pq.push(make_pair(x, i));
    }
    solve(0, n, w, in);
    for (int i=0;i<n-1;i++) cout << h[i] << " ";
    #ifdef random
    struct timeval T;
    gettimeofday(&T, NULL);
    srand(T.tv_usec);
    cout << rand();
    #endif // random
    return 0;
}
