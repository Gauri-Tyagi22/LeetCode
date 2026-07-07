class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>ans;
        long long sum=0;
        while(n){
            int curr=n%10;
            if(curr!=0) {
            ans.push_back(curr);
            sum+=curr;
            }
            n=n/10;
        }
         reverse(ans.begin(),ans.end());
        long long num=0;
        for(int i=0;i<ans.size();i++){
            num=num*10+ans[i];
        }
        return num*sum;
    }
};