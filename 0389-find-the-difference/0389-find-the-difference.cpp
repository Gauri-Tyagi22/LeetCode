class Solution {
public:
    char findTheDifference(string s, string t) {
      char ans=0;
      for(char x:s)
        ans^=x;
      for(char x:t)
        ans^=x;
return ans;
    }
};