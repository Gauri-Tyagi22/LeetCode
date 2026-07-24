class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(int b:bills){
            if(b==5) five++;
            if(b==10){
                if(five) {
                    five--;
                    ten++;
                }
                else return false;
            }
            if(b==20){
                if(five && ten){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five-=3;
                }
                else return false;
            }
        }
        return true;
    }
};