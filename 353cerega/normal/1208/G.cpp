#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>
#include <map>
#include <string>
#include <ctime>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <bitset>
#include <queue>
#include "stdlib.h"
using namespace std;

/*long long pew(long long a, long long step)
{
if (step == 0)
{
return 1;
}
long long b = pew((a*a) % mod, step / 2);
if (step % 2 == 0)
{
return b;
}
else
{
return (b*a) % mod;
}
}

void precal(int cnt)
{
long long tmp = 1;
f[0] = 1;
obrf[0] = 1;
for (int i = 1; i <= cnt; i++)
{
tmp *= i;
tmp %= mod;
f[i] = tmp;
obrf[i] = pew(tmp, mod - 2);
}
}*/


/*void make_set(int v) {
parent[v] = v;
Rank[v] = 0;
siz[v] = 1;
}

int find_set(int v) {
if (v == parent[v])
return v;
return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
a = find_set(a);
b = find_set(b);
if (a != b) {
if (Rank[a] < Rank[b])
swap(a, b);
parent[b] = a;
siz[a] += siz[b];
if (Rank[a] == Rank[b])
++Rank[a];
}
}*/

/*long long gcd(long long ll, long long rr)
{
if (ll < rr)
return gcd(rr, ll);
if (rr == 0)
return ll;
return gcd(ll%rr, rr);
}*/

/*void QSort(int ll, int rr)
{
int ee = ll;
int ff = rr;

long long q = rand();
q = c[ll+q%(rr-ll+1)];
while (ee <= ff)
{
while (c[ee] < q) ee++;
while (c[ff] > q) ff--;
if (ee <= ff)
{
swap(c[ee], c[ff]);
swap(s[ee], s[ff]);
ee++;
ff--;
}
}
if (ff > ll) QSort(ll, ff);
if (ee < rr) QSort(ee, rr);
}*/

long long gcd(long long a, long long b)
{
	if (a < b)
	{
		return gcd(b, a);
	}
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(a%b, b);
	}
}

long long mod = 1000000007;

/*long long mul(long long a, long long b)
{
	return (a*b) % mod;
}
long long sum(long long a, long long b)
{
	return (a + b) % mod;
}
long long sub(long long a, long long b)
{
	return (a - b + mod) % mod;
}

long long pew(long long a, long long b)
{
	if (b == 0)
	{
		return 1;
	}
	long long tmp = pew(a, b / 2);
	if (b % 2 == 0)
	{
		return mul(tmp, tmp);
	}
	else
	{
		return mul(mul(tmp, tmp), a);
	}
}*/

vector<long long> pr, mind(2000001), phi(2000001);


/*long long check(long long n)
{
	if (n == 1)
	{
		return 0;
	}
	for (long long j = 0; pr[j]*pr[j] <= n; j++)
	{
		if (n%pr[j] == 0)
		{
			return 0;
		}
	}
	return 1;
}*/


/*vector<long long> mult(vector<long long> a, vector<long long> b)
{
	vector<long long> tmp(3999);
	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j < 2000; j++)
		{
			tmp[i + j] = sum(tmp[i + j], a[i] * b[j]);
		}
	}
	for (int i = 2000; i < 3999; i++)
	{
		tmp[i - 1999] = sum(tmp[i - 1999], tmp[i]);
		tmp[i - 2000] = sum(tmp[i - 2000], tmp[i]);
		tmp[i] = 0;
	}
	tmp.resize(2000);
	return tmp;
}*/


long long cnt = 0;

long long L(long long a, long long p)
{
	if (a == 1)
	{
		return 1;
	}
	if (a % 2 == 0)
	{
		long long tmp = 1;
		if ((p*p - 1) / 8 % 2 == 1)
		{
			tmp = -1;
		}
		return L(a / 2, p)*tmp;
	}
	long long tmp = 1;
	if ((a - 1)*(p - 1) / 4 % 2 == 1)
	{
		tmp = -1;
	}
	return L(p%a, a)*tmp;
}


long long d6 = 1000LL * 1000;
long long d12 = 1000LL * 1000 * 1000 * 1000;
long long d18 = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
long long d11 = 1000LL * 1000 * 1000 * 100;



int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("a1.in", "r", stdin);
	//freopen("a1.out", "w", stdout);
	for (int i = 2; i <= 2000000; i++)
	{
		if (mind[i] == 0)
		{
			mind[i] = i;
			pr.push_back(i);
			cnt++;
		}
		for (int j = 0; pr[j] < mind[i] and pr[j] * i <= 2000000; j++)
		{
			mind[i*pr[j]] = pr[j];
		}
		if (mind[i] * i <= 2000000)
		{
			mind[i*mind[i]] = mind[i];
		}
	}
	int n, k;
	cin >> n >> k;
	if (k == 1)
	{
		cout << 3 << endl;
		return 0;
	}
	long long ans = 2;
	vector<long long> kek;
	for (int i = 3; i <= n; i++)
	{
		phi[i] = 1;
		int q = i;
		int del = 1;
		int tmp = 0;
		while (q > 1)
		{
			if (mind[q] != del)
			{
				tmp = 1;
				del = mind[q];
				phi[i] *= del - 1;
			}
			else
			{
				phi[i] *= del;
			}
			q /= mind[q];
		}
		kek.push_back(phi[i]);
	}
	sort(kek.begin(), kek.end());
	for (int i = 0; i < k; i++)
	{
		ans += kek[i];
	}
	cout << ans << endl;
}