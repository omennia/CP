#include <bits/stdc++.h>
using namespace std;

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, k; cin >> n >> m >> k;
	int res = 0;
	
	if(n <= m){
		res = n*(n+1) / 2;
	}

	cout << res << '\n';
}