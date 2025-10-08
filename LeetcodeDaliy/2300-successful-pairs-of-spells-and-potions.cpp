
// LeetCode Daily: 2025-10-08
// Problem: 2300. Successful Pairs of Spells and Potions
// URL: https://leetcode.com/problems/successful-pairs-of-spells-and-potions
// Difficulty: MEDIUM

// ==================== C++ SOLUTION ====================
//Tc-O(N*logn), Sc-O(1)
class Solution {
public:
        int lowerBound(long long s,vector<int>& potions,int m,long long success){
            int high = m-1;
            int low = 0;
            int ans = -1;
            while(high>=low){
                int mid = (high+low)/2;
                if(potions[mid]*s>=success){
                    ans = mid;
                    high = mid -1;
                }else low = mid + 1;
            }
            return ans;
        }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        long long n = spells.size();
        long long m = potions.size();
        for(long long i=0;i<n;i++){
            int a = 0;
            int index = lowerBound(spells[i],potions,m,success);
            if(index==-1) ans.push_back(0);
            else ans.push_back(m-index);
        }
        return ans;
    }
};
/* ==================== PYTHON SOLUTION ====================
# Tc-O(N*log n), Sc-O(1)


/* ==================== JAVA SOLUTION ====================
# Tc-O(n*log n), Sc-O(1)
class Solution {
    public int lowerBound(long s,int[] potions,int m,long success){
        int high = m-1;
        int low = 0;
        int ans = -1;
        while(high>=low){
            int mid = (high+low)/2;
            if(potions[mid]*s>=success){
                ans = mid;
                high = mid -1;
            }else low = mid + 1;
        }
        return ans;
    }
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length;
        int[] ans = new int[n];
        Arrays.sort(potions);
        for(int i=0;i<n;i++){
            int a = 0;
            int index = lowerBound(spells[i],potions,m,success);
            if(index==-1) ans[i]=0;
            else ans[i]=m-index;
        }
        return ans;
    }
}

*/