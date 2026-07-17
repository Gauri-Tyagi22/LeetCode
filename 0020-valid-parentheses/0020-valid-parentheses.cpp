class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s.length()==0 || s.length()==1) return false;
        for(char c:s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }
            else {
                if (st.empty())
    return false;
            if(c==')'){
                if(st.top()=='(') st.pop();
                 else return false;
            }
            else if(c=='}'){
                if(st.top()=='{') st.pop();
                else return false;
            }
            else {
                if(st.top()=='[')  st.pop();
                else return false;
            }
            }
        }
            return st.empty();
        }
    
};