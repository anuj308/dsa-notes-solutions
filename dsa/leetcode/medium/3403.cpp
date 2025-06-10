class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        string res;
        int maxSubString = n - numFriends + 1;
        for (int i = 0; i < n; i++) {
            res = max(res, word.substr(i, min(maxSubString, n - i)));
        }
        return res;
    }
};