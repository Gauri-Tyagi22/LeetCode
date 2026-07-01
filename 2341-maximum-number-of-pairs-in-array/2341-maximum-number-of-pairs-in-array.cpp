class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int n:nums){
            mp[n]++;
        }
        int pairs=0;
        int left=0;
        for(auto p:mp){
           pairs+=p.second/2;
           left+=p.second%2;
        }
        return {pairs,left};
    }
};