class Solution {
public:
long long find(vector<int>&candies,int mid){
    long long to=0;
    for(int pile:candies){
        to+=pile/mid;

    }
    return to;
}
    int maximumCandies(vector<int>& candies, long long k) {
         int ans=0;
        int left=1;
        int right=*max_element(candies.begin(),candies.end());
        while(left<=right){
            int mid=left+(right-left)/2;
            long long hour=find(candies,mid);
            if(hour>=k){
                ans=mid;
                 left=mid+1;
               
            }
            else  right=mid-1;
        }
        return ans;
        
    }
};