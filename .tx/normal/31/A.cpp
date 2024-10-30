#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int pow3(int pow, int m) {
    if (pow == 0) {
        return 1;
    }
    lint t = pow3(pow / 2,  m);
    t = (t * t) % m;
    if (pow % 2 == 1) {
        t = (t * 3) % m;
    }
    return t;
}

int main() {
    scid(n);
    rveid(a, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) {
                    continue;
                }
                if (a[i] == a[j] + a[k]) {
                    cout << i + 1 << " " << j + 1 << " " << k + 1;
                    return 0;
                }
            }
        }
    }
    cout << -1;
    return 0;
}