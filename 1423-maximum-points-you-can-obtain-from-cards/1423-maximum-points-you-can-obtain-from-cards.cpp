class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
      
        int sum=0;
        for(int i=n-k;i<n;i++){
            sum+=cardPoints[i];
        }
        int ans=sum;
        for(int i=0;i<=k-1;i++){
           sum+=cardPoints[i];
           sum-=cardPoints[n-k+i];
           ans=max(ans,sum);
        }
        return ans;
    }
};