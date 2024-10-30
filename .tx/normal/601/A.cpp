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

bool w[444][444];
int d[444];

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        w[--x][--y] = w[y][x] = true;
    }
    bool exists = !w[0][n - 1];
    queue<int> q;
    q.push(0);
    for (int i = 1; i < n; i++) {
        d[i] = 1e9;
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (w[v][i] == exists && d[i] > d[v] + 1) {
                d[i] = d[v] + 1;
                q.push(i);
            }
        }
    }
    if (d[n - 1] == 1e9) {
        cout << -1;
    } else {
        cout << d[n - 1];
    }
    return 0;
}