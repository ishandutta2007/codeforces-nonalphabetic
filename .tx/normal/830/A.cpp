#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

int a[1111];
int b[2222];

void solve(istream& cin, ostream& cout) {
    int n, k, p;
    cin >> n >> k >> p;
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    rep(i, 0, k) {
        cin >> b[i];
    }
    sort(b, b + k);
    lint ans = 1e18;
    rep(l, 0, k - n + 1) {
        lint cur = 0;
        rep(i, 0, n) {
            cur = max(cur, 0LL + abs(a[i] - b[i + l]) + abs(b[i + l] - p));
        }
        ans = min(ans, cur);
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
}