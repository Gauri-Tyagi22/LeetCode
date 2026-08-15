class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       int to=0;
       int n=nums.size();
       bool zero=true;
       for(int x:nums){
        to^=x;
        if(x>0) zero=false;
       }
       if(to>0) return n;
       return zero?0:n-1;
    }
};