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

    int n, k;
    cin >> n >> k;
    int ans = 1;
    int l;
    cin >> l;
    int rest = k;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x - l > k) {
            cout << -1;
            return 0;
        }
        if (x - l > rest) {
            ans++;
            rest = k;
        }
        rest -= x - l;
        l = x;
    }

    cout << ans;

    return 0;
}//prgepw