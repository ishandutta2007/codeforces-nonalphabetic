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

int a[1111][1111];
int n;

bool isBlack(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n || a[i][j] == 0) {
        return false;
    }
    return true;
}

bool check(int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!isBlack(x + i, y + j)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    sci(n);
    scid(m);
    int mn = 0;
    while (m-- > 0) {
        mn++;
        sciid(x, y);
        a[--x][--y] = 1;
        for (int i = x - 3; i <= x + 3; i++) {
            for (int j = y - 3; j <= y + 3; j++) {
                if (check(i, j)) {
                    cout << mn;
                    return 0;
                }
            }
        }
    }
    cout << -1;

    return 0;
}