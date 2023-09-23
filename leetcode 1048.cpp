class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int N = words.size();
        
        sort(words.begin(), words.end(), [](string& a, string& b){
            return (a.size() == b.size()) ? (a < b) : (a.size() < b.size());
        });
        
        //at start, each word forms a chain of length 1
        vector<int> length(N, 1);
        int maxLen = 1;
        
        //start from 2nd last word
        for(int i = N-2; i >= 0; i--){
            string word = words[i];
            
            for(int j = i+1; j < N; j++){
                string successor = words[j];
                if(successor.size() == word.size()+1){
                    //check if word is a predecessor of successor
                    bool found = false;
                    for(int k = 0; k < successor.size(); k++){
                        if(successor.substr(0, k) + successor.substr(k+1) == word)
                            found = true;
                    }
                    if(found){
                        length[i] = max(length[i], length[j]+1);
                    }
                }
            }
            
            maxLen = max(maxLen, length[i]);
        }
        
        return maxLen;
    }
};
