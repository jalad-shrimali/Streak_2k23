class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        int n = s.size();
        
        vector<vector<char>> zz(numRows, vector<char>(n, ' '));
        int r = 0, c = 0;
        //direction: false for down, true for up
        bool d = false;
        
        for(int i = 0; i < n; ++i){
            // cout << "(" << r << ", " << c << ")" << endl;
            zz[r][c] = s[i];
            if(!d){
                ++r;
            }else{
                --r;
                ++c;
            }
            
            if(r == 0 || r == numRows-1)
                d = !d;
        }
        
        string ans;
        
        for(int r = 0; r < numRows; ++r){
            for(int c = 0; c < n; ++c){
                if(zz[r][c] != ' '){
                    ans += zz[r][c];
                    if(ans.size() == n) break;
                }
            }
            if(ans.size() == n) break;
        }
        
        return ans;
    }
};
