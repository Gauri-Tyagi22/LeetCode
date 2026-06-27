class Solution {
public:
int sol(vector<int>&nums,int mid,int threshold){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=ceil((double)(nums[i])/(double)(mid));
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(sol(nums,mid,threshold)<=threshold){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};