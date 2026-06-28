class Solution {
public:
int check(vector<int>&nums,int mid){
    int count=1;
    long long sum=0;
   
    for(int i=0;i<nums.size();i++){
        if(sum+nums[i]<=mid) sum+=nums[i];
        else{
            count++;
            sum=nums[i];
        }
    }
    return count;
}
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right=0;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            right+=nums[i];
        }
        while(left<=right){
            int mid=left+(right-left)/2;
            if(check(nums,mid)<=k){
                ans=mid;
               right=mid-1;
            }
            else  left=mid+1;
        }
        return ans;
    }
};