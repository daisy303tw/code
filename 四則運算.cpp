#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
#define starburst ios::sync_with_stdio(0), cin.tie(0)
#define pb push_back
#define all(x) x.begin(), x.end()
string s;
deque<string> dq;
stack<string> opts;
stack<int> stk;
map<string, int> mp;
signed main(){
    starburst;
    mp["*"]=mp["/"]=2;
    mp["+"]=mp["-"]=1;
    mp["("]=0;
    cin >> s;
    char y='+';
    bool flag;
    for (char c:s){
        if (y>='0' && y<='9') flag=1;
        else flag=0;
        y=c;
        string x = string(1, c);
        if (x=="(") opts.push(x);
        else if (x==")"){
            while (!opts.empty()){
                if (opts.top()=="("){
                    opts.pop(); // pop (
                    break;
                }
                dq.pb(opts.top());
                opts.pop();
            }
        }
        else if (x=="+" || x=="-" || x=="*" || x=="/"){
            while (!opts.empty() && mp[opts.top()]>=mp[x]){
                dq.pb(opts.top());
                opts.pop();
            }
            opts.push(x);
        }
        else if (!dq.empty() && flag){
            string ss=dq.back();
            dq.pop_back();
            dq.pb(ss+x);
        }
        else dq.pb(x);
    }
    while (!opts.empty()){
        dq.pb(opts.top());
        opts.pop();
    }
    while (!dq.empty()){
        string x=dq.front();
        // cerr << x << " ";
        if (x=="+" || x=="-" || x=="*" || x=="/"){
            int z=stk.top(); stk.pop();
            int y=stk.top(); stk.pop();
            if (x=="+") stk.push(y+z);
            else if (x=="-") stk.push(y-z);
            else if (x=="*") stk.push(y*z);
            else if (x=="/") stk.push(y/z);
        }
        else stk.push(stoi(x));
        dq.pop_front();
    }
    cout << stk.top();
    return 0;
}
