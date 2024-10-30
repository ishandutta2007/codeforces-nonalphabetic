#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;
const ll inf = 1LL<<60;
const ll md = 1e9+7;
const ld eps = 1e-14;

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	for(string &ss:s)cin>>ss;
	vi hor(n), ver(n);
	int ans = 0;
	rep(i,0,n) rep(j,0,n) if(s[i][j] == 'C'){
		ans += hor[i]++;
		ans += ver[j]++;
	}
	cout << ans << endl;
}