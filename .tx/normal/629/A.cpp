#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

char a[111][111];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scanf("\n%s", a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '.') {
                continue;
            }
            for (int k = 0; k < i; k++) {
                if (a[k][j] != '.') {
                    ans++;
                }
            }
            for (int k = 0; k < j; k++) {
                if (a[i][k] != '.') {
                    ans++;
                }
            }
        }
    }
    cout << ans;

    return 0;
}