class Solution {
public:
int solve(vector<int>&weights,int days,int mid){
    int count=1,load=0;
    for(int w:weights){
        if(load+w>mid){
            count++;
            load=w;
        }
        else load+=w;
    }
    return count;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int left=*max_element(weights.begin(),weights.end());
        int right=0;
        int ans=-1;
        for(int w:weights){
            right+=w;
        }
        while(left<=right){
            int mid=left+(right-left)/2;
            if(solve(weights,days,mid)<=days){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }

        return ans;
    }
};