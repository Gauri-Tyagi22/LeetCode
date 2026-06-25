class Solution {
public:
int binary(vector<int>&nums,int left,int right,int target){
    int ans=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            ans=mid;
            return mid;
        }
        if(nums[left]<=nums[mid]){
        if(nums[left]<=target && target<nums[mid]){
            right=mid-1;
        }
        else {
            left=mid+1;
        }
        }
        else{
            if(target>nums[mid] && target<=nums[right]){
            left=mid+1;
        }
        else {
            right=mid-1;
        }

        }
    }
    return ans;
}
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binary(nums,0,n-1,target);
        
    }
};