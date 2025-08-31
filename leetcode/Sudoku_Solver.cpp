class Solution {
public:
    bool canPlace(vector<vector<char>>& board, int row, int col, int num){
        for(int r=0; r<9; r++){
            if(board[r][col] == num) return false;
        }
        for(int c=0; c<9; c++){
            if(board[row][c] == num) return false;
        }
        int r = (row/3)*3;
        int c = (col/3)*3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[r+i][c+j] == num){
                    return false;
                }
            }
        }
        return true;
    }

    bool sudoku(vector<vector<char>>& board, int row, int col){
        if(row == 9) return true;
        if(col == 9) return sudoku(board, row+1, 0);
        if(board[row][col] == '.'){
            for(int num=1; num<10; num++){
                if(canPlace(board, row, col, '0'+num)){
                    board[row][col] = '0'+num;
                    bool res = sudoku(board, row, col+1);
                    if(res) return true;
                    board[row][col] = '.';
                }
            }
            return false;
        }else{
            return sudoku(board, row, col+1);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board, 0, 0);
    }
};