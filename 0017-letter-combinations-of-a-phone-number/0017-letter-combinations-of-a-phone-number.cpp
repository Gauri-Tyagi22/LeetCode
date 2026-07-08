class Solution {
public:
  vector<string> ans;
    vector<string> mp = {
        "",     
        "",     
        "abc",  
        "def",  
        "ghi",  
        "jkl",  
        "mno",  
        "pqrs", 
        "tuv",  
        "wxyz"  
    };
    void solve(string &digits, int index, string &curr) {
        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }
        string letters = mp[digits[index] - '0'];
        for (char ch : letters) {
            curr.push_back(ch);
            solve(digits, index + 1, curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        string curr;
        solve(digits, 0, curr);

        return ans;
    }
};