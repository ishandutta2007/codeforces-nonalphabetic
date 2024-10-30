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

int a[555][555];

int main() {
    sciid(n, k);
    int x = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < k; j++) {
            a[i][j] = x++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = k; j <= n; j++) {
            a[i][j] = x++;
        }
    }

    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i][k];
    }

    cout << s << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}