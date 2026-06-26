class Solution {
public:
    bool isPerfectSquare(int num) {
         
        int left=0,right=num-1;
        if(num==0 || num==1) return true;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(1LL*mid*mid==num){
                
                return true;
            }
            else if(1LL*mid*mid<num) left=mid+1;
            else  right=mid-1;
            
        }
        return false;
    }
};