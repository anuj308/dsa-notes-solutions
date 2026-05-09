
// LeetCode Daily: 2026-05-09
// Problem: 1914. Cyclically Rotating a Grid
// URL: https://leetcode.com/problems/cyclically-rotating-a-grid/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(n^2), Sc-O(N^2)
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int depth = min(n/2,m/2);
        vector<vector<int>> layers(depth);
        for(int t=0;t<depth;t++){
            for(int i=t;i<m-t;i++){
                layers[t].push_back(grid[t][i]);
            }
            for(int i=t+1;i<n-t;i++){
                layers[t].push_back(grid[i][m-1-t]);
            }
            for(int i=m-1-t;i>t;i--){
                layers[t].push_back(grid[n-1-t][i-1]);
            }
            for(int i=n-1-t;i>t+1;i--){
                layers[t].push_back(grid[i-1][t]);
            }
        }
        for(int t=0;t<depth;t++){
            int lsize = layers[t].size();
            int s=k%lsize;
            for(int i=t;i<m-t;i++){
                grid[t][i]=layers[t][s];
                s++;
                if(s==lsize) s=0;
            }
            for(int i=t+1;i<n-t;i++){
                grid[i][m-1-t]=layers[t][s];
                s++;
                if(s==lsize) s=0;
            }
            for(int i=m-1-t;i>t;i--){
                grid[n-1-t][i-1]=layers[t][s];
                s++;
                if(s==lsize) s=0;
            }
            for(int i=n-1-t;i>t+1;i--){
                grid[i-1][t]=layers[t][s];
                s++;
                if(s==lsize) s=0;
            }
        }

        return grid;
    }
};
/* ==================== PYTHON SOLUTION ====================
        
*/

/* ==================== JAVA SOLUTION ====================

*/

/* ==================== js SOLUTION ====================

*/

/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var rotateGrid = function(grid, k) {
    let n = grid.length;
    let m = grid[0].length;
    let depth = Math.min(Math.floor(n/2),Math.floor(m/2));
    const layers = Array.from({length:depth},()=>[]);
    for(let t=0;t<depth;t++){
        for(let i=t;i<m-t;i++){
            layers[t].push(grid[t][i]);
        }
        for(let i=t+1;i<n-t;i++){
            layers[t].push(grid[i][m-1-t]);
        }
        for(let i=m-1-t-1;i>=t;i--){
            layers[t].push(grid[n-1-t][i]);
        }
        for(let i=n-1-t-1;i>t;i--){
            layers[t].push(grid[i][t]);
        }
    }
    for(let t=0;t<depth;t++){
        let lsize = layers[t].length;
        let s = k % lsize;
        for(let i=t;i<m-t;i++){
            grid[t][i]=layers[t][s];
            s++;
            if(s==lsize) s=0;
        }
        for(let i=t+1;i<n-t;i++){
            grid[i][m-1-t]=layers[t][s];
            s++;
            if(s==lsize) s=0;
        }
        for(let i=m-1-t-1;i>=t;i--){
            grid[n-1-t][i]=layers[t][s];
            s++;
            if(s==lsize) s=0;
        }
        for(let i=n-1-t-1;i>t;i--){
            grid[i][t]=layers[t][s];
            s++;
            if(s==lsize) s=0;
        }
    }
    return grid;
};