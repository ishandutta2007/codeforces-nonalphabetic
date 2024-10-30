#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

int main() {
    sciid(n, k);
    if (n == 4 || k < n + 1) {
        cout << -1;
        return 0;
    }

    sciid(a, b);
    sciid(c, d);

    cout << a << " " << c << " ";
    for (int i = 1; i <= n; i++) {
        if (i == a || i == b || i == c || i == d) {
            continue;
        }
        cout << i << " ";
    }
    cout << d << " " << b << "\n";
    cout << c << " " << a << " ";
    for (int i = 1; i <= n; i++) {
        if (i == a || i == b || i == c || i == d) {
            continue;
        }
        cout << i << " ";
    }
    cout << b << " " << d << "\n";

    return 0;
}