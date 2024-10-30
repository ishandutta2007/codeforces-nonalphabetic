#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<random>
#include<bitset>
using namespace std;
typedef long double ld;
#define double long double
inline int getint() {
	int val = 0;
	char c;
	while ((c = getchar()) && !(c >= '0' && c <= '9'));
	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));
	return val;
}
/*long long pw(long long et, int b) {
	if (b == 0)return 1;
	long long tmp = pw(et, b / 2);
	tmp = (tmp * tmp) % m;
	if (b % 2 == 1)tmp = (tmp * et) % m;
	return tmp;
}*/
const int Y = 1000100;
//const long long m = 998244353;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
const long long INF = 1e17;
long long dp[2][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(15);
	int t;
	cin >> t;
	dp[1][0] = INF;
	while (t--) {
		long long n, m, x, y;
		cin >> n >> m >> x >> y;
		y = min(y, 2 * x);
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < m; ++j) {
				dp[0][j + 1] = dp[1][j + 1] = INF;
				if (s[j] == '*') {
					dp[0][j + 1] = dp[0][j];
				}
				else {
					dp[0][j + 1] = min(dp[0][j] + x, dp[1][j] + y);
					dp[1][j + 1] = dp[0][j];
				}
			}
			ans += dp[0][m];
		}
		cout << ans << "\n";
	}
	return 0;
}
/* Fri Apr 17 2020 21:48:38 GMT+0300 (MSK) */

/* Sat Apr 18 2020 00:44:00 GMT+0300 (MSK) */