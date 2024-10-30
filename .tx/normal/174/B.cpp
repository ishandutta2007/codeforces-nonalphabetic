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
        string s;
        cin >> s;
        int n = isz(s);
        if (s.back() == '.') {
            cout << "NO\n";
            return;
        }

        auto fail = []() { cout << "NO\n"; cout.flush(); exit(0); };

        vector<string> a(1);
        for (char c : s) {
            if (c == '.') {
                if (isz(a.back()) == 0) {
                    fail();
                }
                a.emplace_back();
            } else {
                a.back().push_back(c);
            }
        }
        if (isz(a) < 2) {
            fail();
        }

        vector<string> ans;
        for (int i = 0; i + 1 < isz(a); i++) {
            if (isz(a[i]) > 8) {
                fail();
            }
            ans.push_back(a[i]);
            if (i + 2 == isz(a)) {
                if (isz(a[i + 1]) > 3) {
                    fail();
                }
                ans.back() += "." + a[i + 1];
                break;
            }

            int t = min(3, isz(a[i + 1]) - 1);
            if (t == 0) {
                fail();
            }
            ans.back() += "." + a[i + 1].substr(0, t);
            a[i + 1] = a[i + 1].substr(t, isz(a[i + 1]) - t);
        }

        cout << "YES\n";
        for (string& s : ans) {
            cout << s << "\n";
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
 //ss