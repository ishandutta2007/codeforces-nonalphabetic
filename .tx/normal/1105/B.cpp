#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c = 0;
    char last = 0;
    vector<int> aa(33);
    for (int i = 0; i < n; i++) {
        if (s[i] == last) {
            c++;
        } else {
            if (c) {
                aa[last - 'a'] += c / k;
            }
            c = 1;
            last = s[i];
        }
    }

    if (c) {
        aa[last - 'a'] += c / k;
    }

    cout << *max_element(begin(aa), end(aa)) << "\n";

    return 0;
}