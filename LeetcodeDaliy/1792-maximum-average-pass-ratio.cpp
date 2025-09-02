
// LeetCode Daily: 2025-09-01
// Problem: maximum average pass ratio    (1792)
// URL: https://leetcode.com/problems/maximum-average-pass-ratio
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(nlogn), Sc-O(1)
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0;
        int n = classes.size();
        priority_queue<pair<double,int>> maxHeap;
        for(int i=0;i<n;i++){
            int a = classes[i][0]; // pass
            int b = classes[i][1]; // total
            maxHeap.push({((a+1)/((double)b+1) - (a/(double)b)),i});
        }
        while(extraStudents){
            int i = maxHeap.top().second;
            maxHeap.pop();
            classes[i][0]++;
            classes[i][1]++;
            int a = classes[i][0]; // pass
            int b = classes[i][1]; // total
            maxHeap.push({((a+1)/((double)b+1) - (a/(double)b)),i});
            extraStudents--;
        }
        for(int i=0;i<n;i++){
            int a = classes[i][0]; // pass
            int b = classes[i][1]; // total
            ans+=(a/(double)b);
        }
        return ans/n;
    }
};

//  ==================== PYTHON SOLUTION ====================

        

// /* ==================== JAVA SOLUTION ====================
class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        int n = classes.length;
        PriorityQueue<double[]> maxHeap = new PriorityQueue<>(
            (a, b) -> Double.compare(b[0], a[0])
        );
        
        for (int i = 0; i < n; i++) {
            int pass = classes[i][0];
            int total = classes[i][1];
            double improvement = calculateImprovement(pass, total);
            maxHeap.offer(new double[]{improvement, i});
        }
        
        while (extraStudents > 0) {
            double[] top = maxHeap.poll();
            int i = (int) top[1];
            classes[i][0]++;
            classes[i][1]++;
            double newImprovement = calculateImprovement(classes[i][0], classes[i][1]);
            maxHeap.offer(new double[]{newImprovement, i});
            
            extraStudents--;
        }
        
        double totalRatio = 0;
        for (int[] cls : classes) {
            totalRatio += (double) cls[0] / cls[1];
        }
        
        return totalRatio / n;
    }
    
    private double calculateImprovement(int pass, int total) {
        double currentRatio = (double) pass / total;
        double newRatio = (double) (pass + 1) / (total + 1);
        return newRatio - currentRatio;
    }

}

