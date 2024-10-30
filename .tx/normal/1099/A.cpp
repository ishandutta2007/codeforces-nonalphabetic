#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int w, h;
    cin >> w >> h;

    int u1, d1, u2, d2;
    cin >> u1 >> d1 >> u2 >> d2;

    for (int i = h; i > 0; i--) {
        w += i;
        if (i == d1) {
            w = max(0, w - u1);
        }
        if (i == d2) {
            w = max(0, w - u2);
        }
    }

    cout << w << "\n";

    return 0;
}//xkmtku