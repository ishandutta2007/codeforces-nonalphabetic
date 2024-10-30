#include <cmath>
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
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

struct pt
{
  int x, y;
};

pt operator - (const pt &a, const pt &b)
{
  return {a.x - b.x, a.y - b.y};
}

pt operator + (const pt &a, const pt &b)
{
  return {a.x + b.x, a.y + b.y};
}

ll operator * (const pt &a, const pt &b)
{
  return a.x * (ll) b.y - a.y * (ll) b.x;
}

ll len(const pt &p)
{
  return p.x * (ll) p.x + p.y * (ll) p.y;
}

pt s;

const int N = 300 + 7;

int ok[N][N];
ll dp[N][N];
vector <pt> f;
pt mn;

bool operator < (const pt &a, const pt &b)
{
  if ((a - s) * (b - s) != 0)
  {
    return (a - s) * (b - s) < 0;
  }
  else
  {
    return len(a - s) < len(b - s);
  }
}

ll sq(const pt &a, const pt &b, const pt &c)
{
  return abs((c - a) * (b - a));
}

bool in(const pt &who, const pt &a, const pt &b, const pt &c)
{
  return sq(a, b, c) == sq(a, b, who) + sq(a, c, who) + sq(b, c, who);
}

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <pt> e;
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    e.push_back({x, y});
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    f.clear();
    for (int j = 0; j < n; j++)
    {
      if (e[j].x > e[i].x || (e[j].x == e[i].x && e[j].y > e[i].y))
      {
        f.push_back(e[j]);
      }
    }
    s = e[i];
    sort(f.begin(), f.end());
    int k = f.size();
    for (int i = 0; i < k; i++)
    {
      for (int j = i + 1; j < k; j++)
      {
        ok[i][j] = 0;
      }
    }
    for (int i = 0; i < k; i++)
    {
      for (int j = i + 1; j < k; j++)
      {
        ok[i][j] = 1;
        /*
        for (int t = i + 1; t < j; t++)
        {
          if ((f[j] - f[t]) * (f[t] - f[i]) <= 0)
          {
            ok[i][j] = (ok[i][j] * (ll) 2) % mod;
          }
        }
         */
        /*
        if (!ok[i][j])
        {
            cout << f[i].x << ' ' << f[i].y << " -> " << f[j].x << ' ' << f[j].y << ' ' << s.x << ' ' << s.y << endl;
        }
        */
      }
    }
    vector <pair <int, int> > e;
    for (int i = 0; i < k; i++)
    {
      for (int j = i + 1; j < k; j++)
      {
        e.push_back({i, j});
      }
    }
    mn = {-1, 1000000000};
    sort(e.begin(), e.end(), [] (pair <int, int> a, pair <int, int> b)
    {
      pt x = f[a.second] - f[a.first];
      pt y = f[b.second] - f[b.first];
      if (x * mn == 0)
      {
        if (y * mn == 0)
        {
          return len(x) < len(y);
        }
        else
        {
          return y * mn < 0;
        }
      }
      if (y * mn == 0)
      {
        return x * mn > 0;
      }
      if (x * mn < 0 && y * mn < 0)
      {
        if (x * y == 0)
        {
          return len(x) < len(y);
        }
        return x * y < 0;
      }
      else if (x * mn > 0 && y * mn > 0)
      {
        if (x * y == 0)
        {
          return len(x) < len(y);
        }
        return x * y < 0;
      }
      else
      {
        return x * mn > 0;
      }
    });
    for (int i = 0; i < k; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        dp[i][j] = 0;
      }
    }
    for (int i = 0; i < k; i++) dp[i][0] = 1;
    vector <vector <int> > was(n);
    for (auto c : e)
    {
      int i = c.first, go = c.second;
      for (int j = 0; j < 3; j++)
      {
        dp[go][j + 1] += dp[i][j] * (ll) ok[i][go];
      }
    }
    for (int i = 0; i < k; i++)
    {
      ans += dp[i][3];
    }
  }
  cout << ans << '\n';
}