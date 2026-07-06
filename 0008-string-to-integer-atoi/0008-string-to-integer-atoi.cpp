class Solution {
public:
int solve(string s,long long num,int i,int sign){
    if(i>=s.length() || !isdigit(s[i])) return sign*num;
    num=num*10+(s[i]-'0');
    long long val=sign*num;
    if(val>INT_MAX) return INT_MAX;
    if(val<INT_MIN) return INT_MIN;
    return solve(s,num,i+1,sign);
}
    int myAtoi(string s) {
        int i=0;
        while(i<s.length() && s[i]==' ')
            i++;
      int sign=1;
      if(i<s.length() && (s[i]=='+' || s[i]=='-')){
        if(s[i]=='-'){
            sign=-1;

        }
       i++;
      }
       return solve(s,0,i,sign);
    }
};