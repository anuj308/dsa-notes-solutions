
// LeetCode Daily: 2025-08-30
// Problem: valid sodoku    (36)
// URL: https://leetcode.com/problems/valid-sudoku
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(1) Sc-O(1)
class Solution {
public:
    bool valid(vector<vector<char>>& board,int rowStart,int rowEnd,int colStart,int colEnd){
        unordered_map<int,int> temp;
        for(int i=rowStart;i<=rowEnd;i++){
            for(int j=colStart;j<=colEnd;j++){
                int val = (int)board[i][j];
                if(val=='.') continue;
                if(temp.find(val)==temp.end()){
                    temp[val]++;
                }else return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){ // rows
            unordered_map<int,int> temp;
            for(int j=0;j<9;j++){
                int val = (int)board[i][j];
                if(val=='.') continue;
                if(temp.find(val)==temp.end()){
                    temp[val]++;
                }else return false;
            }
        }
        for(int i=0;i<9;i++){ // cols
            unordered_map<int,int> temp;
            for(int j=0;j<9;j++){
                int val = (int)board[j][i];
                if(val=='.') continue;
                if(temp.find(val)==temp.end()){
                    temp[val]++;
                }else return false;
            }
        }
        for(int i=0;i<9;i+=3){ // boxes
            if(!valid(board,0,2,i,i+2)) return false;
            if(!valid(board,3,5,i,i+2)) return false;
            if(!valid(board,6,8,i,i+2)) return false;
        }

        return true;
    }
};
//  ==================== PYTHON SOLUTION ====================
// # Tc-O(1), Sc-O(1)

        
        

// /* ==================== JAVA SOLUTION ====================
// # Tc-O(1), Sc-O(1)
class Solution {
    public boolean valid(char[][] board,int startRow,int endRow,int startCol, int endCol) {
        Set<Character> rowSet = new HashSet<>();
        for(int i=startRow;i<=endRow;i++){
            for(int j=startCol;j<=endCol;j++){
                char val = board[i][j];
                if(val=='.') continue;
                if(rowSet.contains(val)) return false;
                rowSet.add(val);
            }
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
        for(int i=0;i<9;i++){
            Set<Character> rowSet = new HashSet<>();
            for(int j=0;j<9;j++){
                char val = board[i][j];
                if(val=='.') continue;
                if(rowSet.contains(val)) return false;
                rowSet.add(val);
            }
        }
        for(int i=0;i<9;i++){
            Set<Character> rowSet = new HashSet<>();
            for(int j=0;j<9;j++){
                char val = board[j][i];
                if(val=='.') continue;
                if(rowSet.contains(val)) return false;
                rowSet.add(val);
            }
        }
        for(int i=0;i<9;i+=3){
            if(!valid(board,0,2,i,i+2)) return false;
            if(!valid(board,3,5,i,i+2)) return false;
            if(!valid(board,6,8,i,i+2)) return false;
        }
        return true;
    }       
}