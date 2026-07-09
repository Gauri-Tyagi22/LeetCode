class Solution {
public:
vector<vector<string>>ans;
bool ispali(string s,int st,int end){
    while(st<end){
        if(s[st]!=s[end]){
            return false;
        }
        st++;
        end--;
    }
    return true;
}
void solve(string s,int i,vector<string>path){
    
    if(i==s.length()){
        ans.push_back(path);
        return;
    }
    for(int end=i;end<s.length();end++){
        if(ispali(s,i,end)){
            path.push_back(s.substr(i,end-i+1));
            solve(s,end+1,path);
            path.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string>path;
        solve(s,0,path);
        return ans;
    }
};