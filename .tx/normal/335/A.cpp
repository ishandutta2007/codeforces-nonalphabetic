#ifndef CONTESTSMTH_HEADER_H
#define CONTESTSMTH_HEADER_H

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename V = __gnu_pbds::null_type>
using htable = __gnu_pbds::gp_hash_table<K, V>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
#ifdef VSE
mt19937 rng(0);
#else
mt19937 rng((size_t) make_shared<char>().get());
#endif

#endif //CONTESTSMTH_HEADER_H

#ifndef CONTESTSMTH_UTILS_H
#define CONTESTSMTH_UTILS_H



template <typename T, T val = T()>
auto make_vector(size_t d) {
    return vector<T>(d, val);
}

template <typename T, T val = T(), typename ...Ds>
auto make_vector(size_t d, Ds... ds) {
    return vector<decltype(make_vector<T, val>(ds...))>(d, make_vector<T, val>(ds...));
}

template <typename T>
void relmax(T& a, const T& b) {
    a = max(a, b);
}

template <typename T>
void relmin(T& a, const T& b) {
    a = min(a, b);
}

#endif //CONTESTSMTH_UTILS_H


struct Solver {
    void solve() {
        string s;
        int m;
        cin >> s >> m;
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int l = 0;
        int r = int(1e9);
        while (l + 1 < r) {
            int md = (l + r) >> 1;
            int cur = 0;
            for (int i = 0; i < 26; i++) {
                cur += (cnt[i] + md - 1) / md;
            }
            if (cur > m) {
                l = md;
            } else {
                r = md;
            }
        }
        if (r == int(1e9)) {
            cout << "-1\n";
        } else {
            cout << r << "\n";
            int out = 0;
            for (int i = 0; i < 26; i++) {
                int x = (cnt[i] + r - 1) / r;
                for (int j = 0; j < x; j++) {
                    cout << char(i + 'a');
                    out++;
                }
            }
            while (out < m) {
                cout << 'a';
                out++;
            }
            cout << "\n";
        }
    }
};

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
    return 0;
}
 //ivbzat