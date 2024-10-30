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
template <typename T> using vc = std::vector<T>;

bool is_d(char c) {
    return c >= '0' && c <= '9';
}

void solve(istream& cin, ostream& cout) {
    string s;
    cin >> s;
    int n = s.size();
    int a = 0;
    int i = 0;
    int x = 0;
    while (is_d(s[i])) {
        x = x * 10 + s[i] - '0';
        i++;
    }
    a = x;
    while (i < n) {
        char p = s[i];
        int y = s[i] - '0';
        i++;
        while (i < n && is_d(s[i])) {
            y = y * 10 + s[i] - '0';
            i++;
        }
        if (p == '+') {
            a += y;
        } else {
            a -= y;
        }
    }
    cout << a;
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