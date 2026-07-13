class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>mp;
        int l=0;
        int ans=0;
        for(int r=0;r<s.length();r++){
            while(mp.count(s[r])){
                mp.erase(s[l]);
                l++;
            }
            mp.insert(s[r]);
        
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};