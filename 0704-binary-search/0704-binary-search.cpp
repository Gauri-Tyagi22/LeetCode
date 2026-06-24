class Solution {
public:
int binary(vector<int>&nums,int left,int right,int target){
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            right=mid-1;
        }
        else left=mid+1;
    }
    return -1;
}

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binary(nums,0,n-1,target);
        
    }
};