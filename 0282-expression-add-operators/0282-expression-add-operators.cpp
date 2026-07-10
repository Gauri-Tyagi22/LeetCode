class Solution {
public:
vector<string>ans;
void solve(string num,int target,int idx,long long currval,long long prevval,string exp){
   if(idx==num.length()){
    if(currval==target){
        ans.push_back(exp);
        
    }
    return;
   }
   long long number=0;
   for(int i=idx;i<num.length();i++){
    if(i>idx && num[idx]=='0') break;
    number=number*10+(num[i]-'0');
    string curr=num.substr(idx,i-idx+1);
    if(idx==0){
        solve(num,target,i+1,number,number,curr);
    }
    else{
        solve(num,target,i+1,currval+number,number,exp+"+"+curr);
         solve(num,target,i+1,currval-number,-number,exp+"-"+curr);
          solve(num,target,i+1,currval-prevval+prevval*number,number*prevval,exp+"*"+curr);
    }
   }
}
    vector<string> addOperators(string num, int target) {
        solve(num,target,0,0,0,"");
        return ans;
    }
};