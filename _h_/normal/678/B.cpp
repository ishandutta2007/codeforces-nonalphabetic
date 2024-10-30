#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

bool leap(int y){
	return y%400==0 || (y%4 == 0 && y%100 != 0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int y;
	cin >> y;
	bool l = leap(y);
	int sh = 0;
	while(5){
		sh++;
		if(leap(y)) ++sh;
		++y;
		if(sh%7 == 0 && leap(y) == l){
			cout << y << endl;
			return 0;
		}
	}
}