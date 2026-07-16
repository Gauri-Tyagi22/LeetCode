class Solution {
public:
    long long gcdSum(vector<int>& nums) {
int n=nums.size();
        vector<int>prefixgrid;
        int mx=0;
        for(int i=0;i<nums.size();i++){
               if(mx<nums[i]){
                mx=nums[i];
               }
                prefixgrid.push_back(gcd(mx,nums[i]));
               
        }
        sort(prefixgrid.begin(),prefixgrid.end());
        int left=0,right=prefixgrid.size()-1;
        long long sum=0;
        while(left<right){
            
            sum+=gcd(prefixgrid[left],prefixgrid[right]);
            left++;
            right--;
        }
        return sum;
    }
};