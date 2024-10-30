#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    int cur = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (cur == 0 || x <= last * 2) {
            cur++;
        } else {
            cur = 1;
        }
        last = x;
        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}//nhnfmm