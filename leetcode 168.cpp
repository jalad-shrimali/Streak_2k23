class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            int remainder = (columnNumber - 1) % 26;  
            result = char('A' + remainder) + result;  
            columnNumber = (columnNumber - 1) / 26;   
        }
        
        return result;
    }
};
