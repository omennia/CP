// Disclaimer: Vi coisas sobre geometria online
// e o código das combinações foi adaptado de um site online.
// a ideia foi autoria minha
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;


long double distance(pair<int, int> a, pair<int, int> b){
	// formula: sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
	return sqrt((b.first-a.first)*(b.first-a.first) + (b.second-a.second)*(b.second-a.second));
}
class reta{
public:
	int x1, x2, y1, y2;
	long double declive;
	long double b;
	bool vertical = false;
	reta(int x1, int y1, int x2, int y2){
		this->x1 = x1; this->y1 = y1;
		this->x2 = x2; this->y2 = y2;
		if(x2 - x1 == 0){
			vertical = true;
			declive = -1;
		} else {
			declive = (long double)(y2 - y1) / (x2 - x1);
			b = y1 - declive * x1; // equacao de uma reta
		}
	}

	pair<long double, long double> intersection(reta r1){
		// y = m1x + b1  || y = m2x + b2
		// no ponto de intersecao
		// m1x + b1 = m2x + b2
		// m1x - m2x = b2 - b1
		// x(m1 - m2) = b2 - b1
		// x = (b2 - b1) / (m1 - m2);
		if(this->vertical || r1.vertical){  // no caso de uma das retas ser vertical ( só pode ser uma )
			if(this->vertical){
				int x = (long double) this->x1;
				int y = (long double) r1.declive * x + r1.b;
				return(make_pair(x, y));
			} else{
				int x = (long double) r1.x1;
				int y = (long double) this->declive * x + this->b;
				return(make_pair(x, y));
			}
		}

		long double x = (long double) (r1.b - this->b) / (this->declive - r1.declive);
		// substituimos numa das retas
		// y = m1x + b1;
		long double y = (long double) this->declive * x + this->b;
		return(make_pair(x, y));
	}
};
void read(vector<reta> &ret){
	for(int i=0; i<n; ++i){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		ret.push_back(reta(x1, y1, x2, y2));
	}
}
void print_details(vector<reta> &arr){
	for(auto elem : arr){
		if(elem.vertical) cout << "vertical" << '\n';
		else {
			cout << (elem.y2 - elem.y1) << '\\' << (elem.x2 - elem.x1) << ": ";
			cout << elem.declive << '\n';
		}
	} cout << "==================\n";
}
long double perimeter(vector<reta> &ret, int a, int b, int c){
	pair<long double, long double> res1 = ret[a].intersection(ret[b]);
	// cout << "("<<res1.first<<", "<<res1.second<<")" << '\n';

	pair<long double, long double> res2 = ret[a].intersection(ret[c]);
	// cout << "("<<res2.first<<", "<<res2.second<<")" << '\n';

	pair<long double, long double> res3 = ret[c].intersection(ret[b]);
	// cout << "("<<res3.first<<", "<<res3.second<<")" << '\n';


	long double res = 0;
	res += distance(res1, res2);
	res += distance(res2, res3);
	res += distance(res3, res1);
	return res;
}


vector<int> comb;
vector<int> rets;
vector<reta> ret;

long double global_max = -1;


void find_max(const vector<int> &v) {
  static int count = 0;
  int a = v[0]-1, b = v[1]-1, c = v[2]-1;
//   cout << a <<' ' << b << ' ' << c << '\n';
  global_max = max(global_max, perimeter(ret, 0, 1, 2));
}

void solve(int offset, int k) {
  if (k == 0) {
    find_max(comb);
    return;
  }
  for (int i = offset; i <= rets.size() - k; ++i) {
    comb.push_back(rets[i]);
    solve(i+1, k-1);
    comb.pop_back();
  }
}


signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	// formula do declive:
	// y2-y1 / x2-x1

	read(ret);
	// print_details(ret);

	// Como as retas têm declives diferentes, então só existem
	// 3 pontos de intercecao entre as tres retas
	
	const int k = 3; // sao sempre 3 retas
	for (int i = 0; i < n; ++i) { 
		rets.push_back(i+1); 
	}
	solve(0, k);

	cout << fixed;
	cout << setprecision(10) << global_max << '\n';
	
}