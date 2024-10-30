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
        int n, a, b;
        string x;
        cin >> n >> a >> b >> x;
        auto d = make_vector<int, -1>(n + 1, n + 2, a, b);
        auto pr = d;
        auto pa = d;
        auto pb = d;
        d[0][0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int r = 0; r <= i; r++) {
                for (int ma = 0; ma < a; ma++) {
                    for (int mb = 0; mb < b; mb++) {
                        if (d[i][r][ma][mb] != -1) {
                            d[i + 1][r + 1][(ma * 10 + x[i] - '0') % a][mb] = 1;
                            pr[i + 1][r + 1][(ma * 10 + x[i] - '0') % a][mb] = r;
                            pa[i + 1][r + 1][(ma * 10 + x[i] - '0') % a][mb] = ma;
                            pb[i + 1][r + 1][(ma * 10 + x[i] - '0') % a][mb] = mb;

                            d[i + 1][r][ma][(mb * 10 + x[i] - '0') % b] = 1;
                            pr[i + 1][r][ma][(mb * 10 + x[i] - '0') % b] = r;
                            pa[i + 1][r][ma][(mb * 10 + x[i] - '0') % b] = ma;
                            pb[i + 1][r][ma][(mb * 10 + x[i] - '0') % b] = mb;
                        }
                    }
                }
            }
        }

        int p = -1;
        int pp = int(1e9);
        for (int i = 1; i < n; i++) {
            if (d[n][i][0][0] != -1) {
                if (abs(i - (n - i)) < pp) {
                    pp = abs(i - (n - i));
                    p = i;
                }
            }
        }
        if (p == -1) {
            cout << "-1\n";
            return;
        }
        string ans(n, 0);
        int ca = 0, cb = 0;
        int cr = p;
        for (int i = n - 1; i >= 0; i--) {
            int na = pa[i + 1][cr][ca][cb];
            int nb = pb[i + 1][cr][ca][cb];
            int nr = pr[i + 1][cr][ca][cb];
            if (nr == cr) {
                ans[i] = 'B';
            } else {
                ans[i] = 'R';
            }
            ca = na;
            cb = nb;
            cr = nr;
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