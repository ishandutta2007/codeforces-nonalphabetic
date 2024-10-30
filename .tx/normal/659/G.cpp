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

const int mod = 1e9 + 7;

lint d[1111111][2];
lint h[1111111];

int main() {
    scid(n);
    for (int i = 1; i <= n; i++) {
        scid(x);
        h[i] = x - 1;
    }

    for (int i = 1; i <= n; i++) {
        d[i][0] = (d[i - 1][0] + h[i] + min(h[i], h[i - 1]) * d[i - 1][1]) % mod;
        d[i][1] = (min(h[i], h[i + 1]) + min(min(h[i], h[i - 1]), h[i + 1]) * d[i - 1][1]) % mod;
    }

    cout << d[n][0];

    return 0;
}