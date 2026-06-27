class Solution {
public:
int sol(vector<int>&quantities,int mid,int n){
    int count=0;
    for(int i=0;i<quantities.size();i++){
        count+=ceil(double(quantities[i])/(double)(mid));
    }
    return count<=n;
}
    int minimizedMaximum(int n, vector<int>& quantities) {
          
        int left=1;
        int right=*max_element(quantities.begin(),quantities.end());
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(sol(quantities,mid,n)){
                ans=mid;
                right=mid-1;
                
            }
            else left=mid+1 ;
        }
        return ans;
        
    }
};