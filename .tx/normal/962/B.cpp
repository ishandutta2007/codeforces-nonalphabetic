#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define min(a, b) std::min<decltype((a) < (b) ? (a) : (b))>(a, b)
#define max(a, b) std::max<decltype(!((a) < (b)) ? (a) : (b))>(a, b)
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            continue;
        }
        bool ca = a > 0 && (i == 0 || s[i - 1] != 'a');
        bool cb = b > 0 && (i == 0 || s[i - 1] != 'b');
        if (ca && (a > b || !cb)) {
            s[i] = 'a';
            a--;
            ans++;
        } else if (cb && (b >= a || !ca)) {
            s[i] = 'b';
            b--;
            ans++;
        }
    }
    cout << ans;

    return 0;
}