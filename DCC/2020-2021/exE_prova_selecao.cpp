#include <bits/stdc++.h>
using namespace std;
#define coords 6
#define ll long long

void print(vector<pair<ll, ll>> &arr){
	for(auto elem : arr){
		cout << "("<<elem.first<<", "<<elem.second<<")" << ' ';
	} cout << '\n';
}

ll solve(pair<ll, ll> fst, pair<ll, ll> snd, pair<ll, ll> trd){
	ll a = fst.first,  b = fst.second;
	ll c = snd.first, d = snd.second;
	ll e = trd.first, f = trd.second;
	ll val = LLONG_MAX;

	val = min(val, (a+c+e) * max({ b, d, f }));
	val = min(val, (a+c+f) * max({ b, d, e }));
	val = min(val, max(a+c, f) * (max(b, d) + e));
	val = min(val, max(a+c, e) * (max(b, d) + f));
	if(b > d){ // por o rectangulo com o lado maior em baixo
		swap(b, d); swap(a, c);
	}
	val = min(val, max(d, b+e) * (c + max(a, f)));
	swap(e, f);
	val = min(val, max(d, b+e) * (c + max(a, f)));

	swap(c, d);
	val = min(val, max(d, b+e) * (c + max(a, f)));
	swap(e, f);
	val = min(val, max(d, b+e) * (c + max(a, f)));
	return val;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll t; cin >> t;
	while(t--){
		vector<pair<ll, ll>> arr(coords/2);
		for(ll i=0; i<coords; i += 2){
			cin >> arr[i/2].first >> arr[i/2].second;
			if(arr[i/2].first > arr[i/2].second) swap(arr[i/2].first, arr[i/2].second);
		}
		// print(arr);

		ll res = LLONG_MAX;
		for(int i=0; i<3; ++i){
			for(int j=0; j<3; ++j){
				for(int k=0; k<3; ++k){
					if(i == j || i == k || k == j) continue;
					res = min(res, solve(arr[i], arr[j], arr[k]));
				}
			}
		}
		cout << res << '\n';
	}
}