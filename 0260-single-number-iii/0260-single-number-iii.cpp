class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
        }
        long long x=ans;
        long long mask=x&(-x);
       int ans1 = 0, ans2 = 0;

for (int num : nums) {
    if (num & mask)
        ans1 ^= num;
    else
        ans2 ^= num;
}
        return {ans1,ans2};
    }
};