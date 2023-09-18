class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //greater: smaller element will be poped earlier
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans(k);
        
        //first sort by soldier count and then by row id
        for(int i = 0; i < mat.size(); i++){
            pq.push(accumulate(mat[i].begin(), mat[i].end(), 0) * 100 + 
                   i);
        }
        
        for(int i = 0; i < k; i++){
            ans[i] = pq.top()%100;
            pq.pop();
        }
        
        return ans;
    }
};
