
// LeetCode Daily: 2025-08-28
// Problem: Sort Matrix by Diagonals     (3446)
// URL: https://leetcode.com/problems/sort-matrix-by-diagonals
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(1)
class Solution {
public:
    bool static cmp(int a,int b){
        return a > b;
    }
    void sortDiagonal(vector<vector<int>>& grid,int ro,int co,bool asc){
        int n = grid.size();
        vector<int> temp;
        int row = ro;
        int col = co;
        while(row<n && col<n){
            temp.push_back(grid[row][col]);
            row++;
            col++;
        }
        if(!asc) sort(temp.begin(),temp.end(),cmp);
        else sort(temp.begin(),temp.end());
        row = ro;
        col = co;
        int c = 0;
        while(row<n && col<n){
            grid[row][col]=temp[c];
            c++;
            row++;
            col++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0;i<n;i++){ // bottom left triangle , desc
            sortDiagonal(grid,i,0,false);
        }
        for(int i=1;i<n;i++){ // top right triangle, asc
            sortDiagonal(grid,0,i,true);
        }
        return grid;
    }
};

//  ==================== PYTHON SOLUTION ====================
// # Tc-O(N), Sc-O(1)
class Solution(object):
    def diagonalSort(self,grid,row,col,asc):
        n = len(grid)
        r = row
        c = col
        temp = []
        while(r<n and c<n):
            temp.append(grid[r][c])
            r+=1
            c+=1
        if asc:
            temp = sorted(temp)
        else:
            temp = sorted(temp,reverse=True)
        r = row
        c = col
        ind = 0
        while(r<n and c<n):
            grid[r][c]=temp[ind]
            ind+=1
            r+=1
            c+=1
    def sortMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(grid)
        for i in range(n):
            self.diagonalSort(grid,i,0,False)
        for i in range(1,n):
            self.diagonalSort(grid,0,i,True)

        return grid
        
        

// /* ==================== JAVA SOLUTION ====================
// # Tc-O(N), Sc-O(1)
class Solution {
    public void diagonalSort(int[][] grid,int ro,int co,boolean asc){
        int n = grid.length;
        int row = ro;
        int col = co;
        int dLen = 0;
        while(row<n && col<n){
            row++;
            col++;
            dLen++;
        }
        row = ro;
        col = co;
        int[] temp = new int[dLen];
        int index = 0;
        while(row<n && col<n){
            temp[index++] = grid[row][col];
            row++;
            col++;
        }
        Arrays.sort(temp);
        if(!asc){
            for(int i=0;i<dLen/2;i++){
                int t = temp[i];
                temp[i]=temp[dLen-i-1];
                temp[dLen-i-1]=t;
            }
        }
        row =ro;
        col =co;
        index = 0;
        while(row<n && col<n){
            grid[row][col]=temp[index++];
            row++;
            col++;
        }

    }
    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;
        for(int i=0;i<n;i++){
            diagonalSort(grid,i,0,false);
        }
        for(int i=1;i<n;i++){
            diagonalSort(grid,0,i,true);
        }
        return grid;
    }
}

