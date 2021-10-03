/* B. Tiling Challenge   https://codeforces.com/contest/1150 */
#include <bits/stdc++.h>
using namespace std;

class Board{
public:
    vector<vector<char>> board;
    int rows, cols, to_fill = 0;
    Board(int rows, int cols){
        this->rows = rows;
        this->cols = cols;
        this->board = vector<vector<char>> (rows ,vector<char> (cols));
    }

    void read_mat(){
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                cin >> this->board[i][j];
                if(this->board[i][j] == '.') ++to_fill;
            }
        }
    }
    
    void print_mat(){
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                cout << this->board[i][j];
            } cout << '\n';
        }
    }

    string solve(){ // kinda flood-fill
        for(int i=1; i<rows-1; ++i){
            for(int j=1; j<cols-1; ++j){
                if(this->board[i][j] == '.'){
                    if(this->board[i-1][j] == '.' &&  this->board[i+1][j] == '.' && this->board[i][j-1] == '.' && this->board[i][j+1] == '.'){
                        this->board[i][j] = this->board[i-1][j] = this->board[i+1][j] = this->board[i][j-1] = this->board[i][j+1] = '#';
                        to_fill -= 5;
                    }
                }
            }
        } return to_fill ? "NO\n" : "YES\n";
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Board board(n, n);
    board.read_mat();
    cout << board.solve();
    // board.print_mat();
}