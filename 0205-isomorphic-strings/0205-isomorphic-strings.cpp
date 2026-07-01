class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>smap;
        unordered_map<char,char>tmap;
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++){
            char c1=s[i];
            char c2=t[i];
            if(smap.count(c1)){
                if(smap[c1]!=c2) return false;
              
            }
              else smap[c1]=c2;
            if(tmap.count(c2)){
                if(tmap[c2]!=c1) return false;
                
            }
            else tmap[c2]=c1;
        }
return true;
        
    }
};