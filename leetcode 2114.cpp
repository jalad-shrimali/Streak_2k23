class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
           int ans = 0;
        for (auto& s : sentences)
            ans = max<int>(ans, count(s.begin(), s.end(), ' ') + 1);
        return ans;
    }
};
