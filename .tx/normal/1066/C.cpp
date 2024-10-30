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
    vector<int> p(222222);
    int l = 1, r = 0;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        --x;
        if (s == "L") {
            p[x] = --l;
        } else if (s == "R") {
            p[x] = ++r;
        } else {
            cout << min(p[x] - l, r - p[x]) << "\n";
        }
    }


    return 0;
}//gnwjkh