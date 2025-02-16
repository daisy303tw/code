#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int SIZE = 1 << 20;
LL sum[SIZE];
void solve() {
    LL n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= m; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    if (sum[m] * n <= t) {
        cout << (k + m) * n << '\n';
        return;
    }
    LL an = 0;
    for (int i = 1; i <= m; i++) {
        LL base_t = sum[i - 1] * n;
        if (base_t > t)
            break;
        LL potential_full_cnt = (t - base_t) / (sum[m] - sum[i - 1]);
        LL r_cnt = min(n - potential_full_cnt, (t - base_t - potential_full_cnt * (sum[m] - sum[i - 1])) / a[i]);
        an = max(an, n * (i - 1) + potential_full_cnt * (m - i + 1 + k) + r_cnt);
        base_t = sum[i] * n;
        if (base_t > t) {
            an = max(an, n * (i - 1) + (t - sum[i - 1] * n) / a[i]);
            break;
        }
        potential_full_cnt = (t - base_t) / (sum[m] - sum[i]);
        an = max(an, n * i + potential_full_cnt * (m - i + k));
        potential_full_cnt++;
        LL need = potential_full_cnt * sum[m] + (n - potential_full_cnt) * sum[i - 1];
        if (need <= t) {
            an = max(an, n * (i - 1) + potential_full_cnt * (m - i + 1 + k) + (t - need) / a[i]);
        }
    }
    cout << an << '\n';
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
