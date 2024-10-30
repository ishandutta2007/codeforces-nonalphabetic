#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    vector <int> cnt(n);
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    a = cnt;
    sort(a.begin(), a.end());
    auto check = [&] (int x) {
      auto b = a;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (b[i]) {
          b[i]--;
          cnt++;
          if (cnt == x) break;
        } 
      }
      if (cnt < x) return false;
      for (int i = 0; i < n; i++) {
        if (b[i] >= x) {
          return true;
        }
      }
      return false;
    };
    int l = 0, r = n + 1;
    while (l < r - 1) {
      int m = (l + r) / 2;
      if (check(m)) l = m;
      else r = m;
    }
    cout << l << '\n';
  }
}