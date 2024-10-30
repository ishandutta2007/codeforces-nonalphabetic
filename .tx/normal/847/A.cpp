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
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        --l[i]; --r[i];
    }

    while (true) {
        int x = 0;
        while (l[x] != -1) {
            x = l[x];
        }
        int f = x;
        int cnt = 1;
        while (r[x] != -1) {
            cnt++;
            x = r[x];
        }

        if (cnt == n) {
            break;
        }
        for (int i = 0; i < n; i++) {
            if (i != f && l[i] == -1) {
                r[x] = i;
                l[i] = x;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << l[i] + 1 << " " << r[i] + 1 << "\n";
    }

    return 0;
}//jfvqew