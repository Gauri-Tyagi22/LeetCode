class Solution {
public:
    int smallestNumber(int n, int t) {
    for(int i=n;;i++){
        int x=i;
        int ans=1;
        while(x>0){
        ans*=(x%10);
        x=x/10;
        }
        if(ans%t==0) return i;
       
    }
    return -1;
    }
};