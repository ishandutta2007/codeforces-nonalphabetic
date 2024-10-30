#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

using lint = long long;
template <typename A, typename B> auto min(A a, B b) { return a < b ? a : b; };
template <typename A, typename B> auto max(A a, B b) { return a < b ? b : a; };
template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define STRESS 0

void solve(istream& cin, ostream& cout) {
    int n = 14;
    vector<lint> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    lint ans = 0;
    rep(s, 0, n) {
        vector<lint> b = a;
        lint x = b[s];
        b[s] = 0;
        int i = s + 1;
        while (x && i < 14) {
            b[i]++;
            x--;
            i++;
        }
        lint y = x / 14;
        rep(t, 0, 14) {
            b[t] += y;
        }
        x %= 14;
        i = 0;
        while (x) {
            b[i]++;
            x--;
            i++;
        }
        lint sc = 0;
        for (lint f : b) {
            if (f % 2 == 0) {
                sc += f;
            }
        }
        ans = max(ans, sc);
    }
    cout << ans;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//smpzwz