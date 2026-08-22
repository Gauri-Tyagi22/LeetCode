class Solution {
public:
    bool checkDivisibility(int n) {
        int ds=0,pro=1;
        int org=n;
        while(n>0){
            int d=n%10;
            ds+=d;
            pro*=d;
            n=n/10;
        }
        return org%(ds+pro)==0;
    }
};