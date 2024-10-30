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

llong min(int a, llong b) {
    return min<llong>(a, b);
}

llong min(llong a, int b) {
    return min<llong>(a, b);
}

llong max(int a, llong b) {
    return max<llong>(a, b);
}

llong max(llong a, int b) {
    return max<llong>(a, b);
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
    bool is_sq(vector<pair<int, int>> ps) {
        sort(begin(ps), end(ps));
        do {
            bool ok = true;
            ok &= ps[0].first == ps[1].first;
            ok &= ps[1].second == ps[2].second;
            ok &= ps[2].first == ps[3].first;
            ok &= ps[3].second == ps[0].second;
            if (ok) {
                return true;
            }
        } while (next_permutation(begin(ps), end(ps)));
        return false;
    }

    void solve() {
        int n;
        cin >> n;
        vector<string> a(n);
        vector<pair<int, int>> ps;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < isz(a[i]); j++) {
                if (a[i][j] == '*') {
                    ps.emplace_back(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '*') {
                    continue;
                }
                if (i != ps[0].first && j != ps[0].second) {
                    continue;
                }
                ps.emplace_back(i, j);
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        if (a[i][j] == '*' || ps.back() == pair(x, y)) {
                            continue;
                        }
                        if (x != ps[1].first && y != ps[1].second) {
                            continue;
                        }
                        ps.emplace_back(x, y);
                        if (is_sq(ps)) {
                            a[i][j] = '*';
                            a[x][y] = '*';
                            for (int t = 0; t < n; t++) {
                                cout << a[t] << "\n";
                            }
                            return;
                        }
                        ps.pop_back();
                    }
                }
                ps.pop_back();
            }
        }
        assert(false);
    }
};

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
    return 0;
}