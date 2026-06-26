class Solution {
public:
    int mySqrt(int x) {
        int ans=-1;
        int left=0,right=x-1;
        if(x==0 || x==1) return x;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(1LL*mid*mid<=x){
                int sol=mid;
                ans=max(sol,ans);
                left=mid+1;
            }
            else  right=mid-1;
            
        }
        return ans;
    }
};