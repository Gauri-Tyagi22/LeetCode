class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,mxfreq=0;
        vector<int>freq(26,0);
        int ans=0;
        for(int r=0;r<s.length();r++){
            freq[s[r]-'A']++;
            mxfreq=max(mxfreq,freq[s[r]-'A']);
            while((r-left+1)-mxfreq>k){
                freq[s[left]-'A']--;
                left++;
            }
            ans=max(ans,r-left+1);
        }
        return ans;
    }
};