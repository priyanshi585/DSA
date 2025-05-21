#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row[n] = {0};
        int col[m] = {0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
}

int main()
{
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}} ;
    setZeroes(matrix);
    int rowIndex = 0;
    for (auto& row : matrix) {
        int colIndex = 0;
        for (auto& val : row) {
            cout << "matrix[" << rowIndex << "][" << colIndex << "] = " << val << endl;
            colIndex++;
        }
        rowIndex++;
    }

}
