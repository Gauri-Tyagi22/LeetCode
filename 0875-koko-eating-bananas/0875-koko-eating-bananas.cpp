class Solution {
public:
long long find(vector<int>&piles,int mid){
    long long to=0;
    for(int pile:piles){
        to+=(pile+mid-1)/mid;

    }
    return to;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        while(left<=right){
            int mid=left+(right-left)/2;
            long long hour=find(piles,mid);
            if(hour<=h){
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};