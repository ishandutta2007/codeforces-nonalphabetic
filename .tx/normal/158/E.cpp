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

int t[4444];
int d[4444];

int dp[4444][4444];

int main() {
    sciid(n, k);

    if (n == k) {
        cout << 86400;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scii(t[i], d[i]);
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = max(dp[i][0], t[i]) + d[i];
        for (int j = 1; j <= i + 1 && j <= k; j++) {
            dp[i + 1][j] = min(dp[i][j - 1], max(dp[i][j], t[i]) + d[i]);
        }
    }

    t[n] = 86401;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i + 1 && j <= k; j++) {
            int tf = dp[i + 1][j];
            int ef = t[min(n, i + 1 + k - j)];
            ans = max(ans, ef - tf);
        }
    }

    cout << ans;

    return 0;
}