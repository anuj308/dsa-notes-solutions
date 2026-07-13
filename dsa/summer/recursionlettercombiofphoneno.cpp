
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/


 void func(string s,string& digits,int i,int& n,vector<string>& mpp,vector<string>& ans){
    for(auto it : mpp[digits[i]-'0']){
        string news = s + it;
        if(i!=(n-1)) func(news,digits,i+1,n,mpp,ans);
        else ans.push_back(news);
    }
}
vector<string> letterCombinations(string digits) {
    int n = digits.length();
    vector<string> ans;
    string s = "";
    vector<string> mpp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    func(s,digits,0,n,mpp,ans);
    return ans;
}