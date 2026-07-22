class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
         map<int,int>mp;
        for(int x:nums) mp[x]++;
        for(auto it:mp){
            int mn=it.first;
            while(mp[mn]>0){
                for(int i=0;i<k;i++){
                    if(mp[mn+i]==0) return false;
                    mp[mn+i]--;
                }
            }
        }
        return true; 
    }
};