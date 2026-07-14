class Solution {
public:
    int captureForts(vector<int>& forts) {
        int last=-1,ans=0;
        for(int i=0;i<forts.size();i++){
            if(forts[i]==0) continue;
          else  if(forts[i]==1|| forts[i]==-1){
                if(last!=-1 && forts[last]!=forts[i]){
                    ans=max(ans,i-last-1);
                }
            
                last=i;
            }
        }
        return ans;
    }
};