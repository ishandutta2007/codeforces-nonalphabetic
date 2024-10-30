#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    int ans = count(begin(a), end(a), c);
    vector<int> sc(n);
    for (int i = 0; i < n; i++) {
        sc[i] = a[i] == c;
        if (i) {
            sc[i] += sc[i - 1];
        }
    }

    vector<int> mx(555555, -1e9);
    vector<int> cnt(555555);
    for (int i = 0; i < n; i++) {
        if (a[i] == c) {
            continue;
        }
        int sr = sc[n - 1] - (i ? sc[i - 1] : 0);
        int sl = sc[i];
        mx[a[i]] = max(mx[a[i]], sl - cnt[a[i]]);
        ans = max(ans, sr + cnt[a[i]] + mx[a[i]] + 1);
        cnt[a[i]]++;
    }

    cout << ans;

    return 0;
}//izzewn