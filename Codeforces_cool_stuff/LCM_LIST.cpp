#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b);
ll lcm_list(ll array[], ll k);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        ll array[k];
        for(int i=0; i<k; ++i) array[i] = 0;
        array[k-1] = n;
        for(int i=k-2; i>=0; --i){
            --array[k-1];
            ++array[i];
        }
        while(lcm_list(array, k) > (double)n/2){
            for(int i=k-2; i>=0; --i){
                --array[k-1];
                ++array[i];
            }
        }

        for(int i=0; i<k; ++i){
            cout << array[i] << ' ' ;
        } cout << '\n';
    }
}

ll lcm_list(ll array[], ll k){
    ll res = array[0];
    for (ll i = 1; i < k; i++) {
        res = (((array[i] * res)) / (gcd(array[i], res)));
    } return res;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}