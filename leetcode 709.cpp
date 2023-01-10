class Solution {
public:
    string toLowerCase(string s) {
      for(int i = 0; i < s.size(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                s.replace(i,1,1, s[i]+'a'-'A'); //str.replace(int pos, int len, int n, char c)
                // str.replace(i, 1, string(1, (char)(str[i]+'a'-'A'))); //str.replace(int pos, int len, string str)
            }
        }
        return s;  
    }
};
