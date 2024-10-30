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
    void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            g[x].push_back(y);
        }

        vector<int> used(n);
        vector<int> dd(n);
        vector<int> onc(n);

        function<void(int)> dfs = [&](int v) {
            used[v] = 1;
            for (int i : g[v]) {
                if (used[i] == 1) {
                    onc[i] = 1;
                } else if (used[i] == 2) {
                    dd[i] = 1;
                } else {
                    dfs(i);
                }
            }
            used[v] = 2;
        };

        dfs(0);

        function<void(int)> dfs2 = [&](int v) {
            for (int i : g[v]) {
                if (!onc[i]) {
                    onc[i] = 1;
                    dfs2(i);
                }
            }
        };

        function<void(int)> dfs3 = [&](int v) {
            for (int i : g[v]) {
                if (!dd[i]) {
                    dd[i] = 1;
                    dfs3(i);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (onc[i]) {
                dfs2(i);
            }
            if (dd[i]) {
                dfs3(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                cout << "0 ";
            } else if (onc[i]) {
                cout << "-1 ";
            } else if (dd[i]) {
                cout << "2 ";
            } else {
                cout << "1 ";
            }
        }
        cout << "\n";
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