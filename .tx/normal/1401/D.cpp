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
        const int M = int(1e9) + 7;
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int m;
        cin >> m;
        vector<int> p(m);
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        while (isz(p) < n - 1) {
            p.push_back(1);
        }
        sort(begin(p), end(p));
        while (isz(p) > n - 1) {
            int x = p.back();
            p.pop_back();
            p.back() = 1LL * p.back() * x % M;
        }
        vector<int> sz(n);
        vector<llong> es;
        function<void(int, int)> dfs = [&](int v, int p) {
            sz[v] = 1;
            for (int u : g[v]) {
                if (u == p) {
                    continue;
                }
                dfs(u, v);
                sz[v] += sz[u];
            }
            if (p != -1) {
                es.push_back(1LL * sz[v] * (n - sz[v]));
            }
        };

        dfs(0, -1);
        sort(begin(es), end(es));
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = (ans + es[i] * p[i]) % M;
        }
        cout << ans << "\n";
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