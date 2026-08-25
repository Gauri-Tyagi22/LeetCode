class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>set(nums.begin(),nums.end());
        for(int i=1;i<=101;i++){
            int mul=i*k;
            if(set.find(mul)==set.end()) return mul;
        }
return -1;
    }
};