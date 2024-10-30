#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int a[555][555];
int x[555];

lint ans[555];

int main() {
    scid(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sci(a[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        sci(x[n - 1 - i]);
        x[n - 1 - i]--;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = min(a[i][j], a[i][x[k]] + a[x[k]][j]);
            }
        }

        lint s = 0;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                s += a[x[i]][x[j]];
            }
        }
        ans[n - 1 - k] = s;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}