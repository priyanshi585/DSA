#include<iostream>
#include<vector>
using namespace std;

void addSolution(vector<vector<int>> &ans , vector<vector<int>> &board , int n){
    vector<int> temp ;
    for(int i = 0 ;i<n ;i++){
        for(int j= 0; j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col , vector<vector<int> > &board ,int n){
    int x = row; 
    int y = col;

    while(y>=0){
        if(board[x][y] == 1){
            return false;
        }
        y-- ;
    }

    //for upper diagonal:
    x= row ;
    y = col;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        y-- ;
        x--;
    }

    //for lower diagonal:
    x = row ;
    y = col;
    while(x<n && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        y-- ;
        x++;
    }
    return true;
}

void solve(int col , vector<vector<int>> &ans , vector<vector<int>> &board , int n)
{
    if(col==n){
        addSolution(board , ans , n);
        return;
    }

    for(int row = 0; row<n ;row++){
        if(isSafe(row , col , board , n)){
           board[row][col] = 1;
           solve(col+1 , ans , board , n);
           board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> board(n , vector<int> (n ,0));
    vector<vector<int>> ans;
    solve(0 , ans , board, n);
    return ans;
}

void printBoards(const vector<vector<int>>& ans, int n) {
    for (const auto& board : ans) {
        for (int i = 0; i < n * n; ++i) {
            cout << board[i] << " ";
            if ((i + 1) % n == 0)
                cout << endl;
        }
        cout << "----------------\n";
    }
}

int main() {
    int n = 4;
    vector<vector<int>> ans = nQueen(n); // Assume nQueen returns vector<vector<int>>

    printBoards(ans , n);

    return 0;
}
