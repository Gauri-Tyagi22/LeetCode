class Solution {
public:
int find(int mn,int mx){
    int res=0;
    for(int i=1;i<=mn;i++){
        if(mn%i==0 && mx%i==0){
            int ans=i;
            res=max(res,ans);
        }
    }
    return res;
}
    int findGCD(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        return find(mn,mx);
    }
};