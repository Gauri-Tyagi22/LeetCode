class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        int oddcount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0)
                oddcount++;
                if(mp.count(oddcount-k))
                    count+=mp[oddcount-k];
                
                mp[oddcount]++;
            
        }
        return count;
    }
};