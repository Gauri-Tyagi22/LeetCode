class Solution {
public:
    int maximumLengthSubstring(string s) {
      int l=0;
      vector<int>freq(26);
      int ans=0;
      for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++;
        while(freq[s[i]-'a']>2){
            freq[s[l]-'a']--;
            l++;
        }
        ans=max(ans,i-l+1);
      }
      return ans;  
    }
};