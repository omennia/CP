/* https://codeforces.com/contest/1581/problem/C */
#include <bits/stdc++.h>
using namespace std;
int r, c;
#define pairs pair<int, int>

void read(vector<vector<int>> &mat){
	for(int i=0; i<r; ++i){
		string s; cin >> s;
		for(int j=0; j<c; ++j){
			mat[i][j] = (int)s[j] - '0';
		}
	}
}
void print(vector<vector<int>> &mat){
	for(auto elem : mat){
		for(auto cur : elem){
			cout << cur << ' ';
		} cout << '\n';
	}
}
void print(vector<vector<pair<int, int>>> &arr){
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			cout << "("<< arr[i][j].first<<", "<<arr[i][j].second<<") "; 
		} cout << '\n';
	}
}
void pre_fix(vector<vector<int>> &mat, vector<vector<pair<int, int>>> &ones, vector<vector<pair<int, int>>> &zeros){
	int col_zeros = 0, row_zeros = 0;
	int col_ones = 0, row_ones = 0;
	// format (rows, cols)
	// first row
	for(int i=0; i<c; ++i){
		col_ones += mat[0][i] == 1;
		col_zeros += mat[0][i] == 0;
		ones[0][i] = make_pair(col_ones, mat[0][i] == 1);
		zeros[0][i] = make_pair(col_zeros, mat[0][i] == 0);
	}

	// first column
	for(int i=0; i<r; ++i){
		row_ones += mat[i][0] == 1;
		row_zeros += mat[i][0] == 0;
		ones[i][0] = make_pair(mat[i][0] == 1, row_ones);
		zeros[i][0] = make_pair(mat[i][0] == 0, row_zeros);
	}

	// rest of the matrix
	for(int i=1; i<r; ++i){
		for(int j=1; j<c; ++j){
			int one = mat[i][j] == 1;
			int zero = mat[i][j] == 0;
			col_ones = ones[i][j-1].first + one;
			col_zeros = zeros[i][j-1].first + zero;
			row_ones = ones[i-1][j].second + one;
			row_zeros = zeros[i-1][j].second + zero;
			ones[i][j] = make_pair(col_ones, row_ones);
			zeros[i][j] = make_pair(col_zeros, row_zeros);
		}
	}
}

int find_min(vector<vector<int>> &mat, int y, int x, vector<vector<pair<int, int>>> &ones, vector<vector<pair<int, int>>> &zeros){
	int minimum = INT_MAX;

	for(int ry=y+5; ry <= r; ++ry){
		for(int rx=x+4; rx <= c; ++rx){
			int expected_ones = 2*(rx-x - 2) + 2*(ry-y-2);
			int expected_zeros = (rx-x - 2) * (ry-y-2);

			
			int actual_ones = 0;
			actual_ones += ones[y][rx-1].first - ones[y][x].first;      // first row
			actual_ones += ones[ry-1][rx-1].first - ones[ry-1][x].first;    // last row
			actual_ones += ones[ry-1][x].second - ones[y][x].second;	  // first col
			actual_ones += ones[ry-1][rx-1].second - ones[y][rx-1].second;  // last col

			// subtracting corners
			actual_ones -= mat[y][x] == 1;
			actual_ones -= mat[y][rx-1] == 1;
			actual_ones -= mat[ry-1][x] == 1;
			actual_ones -= mat[ry-1][rx-1] == 1;

			// cout << "actual_ones: " << actual_ones << '\n';
			// cout << "expected_ones: " << expected_ones << "  expected_zeros: " << expected_zeros << '\n';

			// counting zeros;
			int actual_zeros = 0;
			for(int i=y+1; i<ry-1; ++i){
				actual_zeros += zeros[i][rx-2].first - zeros[i][x+1].first;
				actual_zeros += zeros[i][x+1].first != zeros[i][x].first;  // DO THIS LOGIC FOR ONES
			}
			// cout << "actual_zeros: " << actual_zeros << '\n';

			int res = abs(expected_ones - actual_ones) + abs(expected_zeros - actual_zeros);
			minimum = min(minimum, res); 
		}
		cout << "minimum: " << minimum << '\n';
	}
	return minimum;
}



signed main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while(t--){
		cin >> r >> c;
		vector<vector<int>> mat(r, vector<int> (c));
		vector<vector<pair<int, int>>> ones(r, vector<pair<int, int>> (c));
		vector<vector<pair<int, int>>> zeros(r, vector<pair<int, int>> (c));
		read(mat);
		print(mat);
		cout << '\n';
		pre_fix(mat, ones, zeros);


		// print(ones);
		// cout << '\n';
		// print(zeros);


		int actual_min = INT_MAX;
 
 
		for(int i=0; i<r-4; ++i){
			for(int j=0; j<c-3; ++j){
				actual_min = min(actual_min, find_min(mat, i, j, ones, zeros));
			}
		}
		cout << actual_min << '\n';

		

	}
}

