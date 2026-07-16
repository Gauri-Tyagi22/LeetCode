class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int>freq(3,0);
        int left=0;
        int ans=0;
        for(int r=0;r<s.length();r++){
            freq[s[r]-'a']++;
    while(freq[0]>0 && freq[1]>0 && freq[2]>0){
        ans+=n-r;
        freq[s[left]-'a']--;
        left++;
    }
        }
        return ans;
    }
};