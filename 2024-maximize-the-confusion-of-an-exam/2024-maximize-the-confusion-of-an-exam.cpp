class Solution {
public:
int solve(string answerKey,char target,int k){
    int left=0,ans=0,change=0;
    for(int r=0;r<answerKey.length();r++){
        if(answerKey[r]!=target){
            change++;
            while(change>k){
                if(answerKey[left]!=target){
                    change--;
                }
                left++;
            }
        }
         ans=max(ans,r-left+1);

    }
    return ans;
}
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey,'T',k),solve(answerKey,'F',k));
        
    }
};