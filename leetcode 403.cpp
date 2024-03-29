class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size() == 0) return true;
        set<int> sstones(stones.begin(), stones.end());
        stones = vector<int>(sstones.begin(), sstones.end());
        
        int goal = stones.back();
        // cout << "goal: " << goal << endl;
        
        unordered_map<int, unordered_set<int>> pos2steps;
        //the first position is always 0
        pos2steps[0].insert(1);
        
        int n = stones.size();
        for(int i = 0; i < n; ++i){
            int pos = stones[i];
            for(int step : pos2steps[pos]){
                int npos = pos + step;
                if(npos == goal) return true;
                if(sstones.find(npos) == sstones.end()){
                    //there is no stone here
                    continue;
                }
                for(int nstep = step-1; nstep <= step+1; ++nstep){
                    if(nstep <= 0) continue;
                    pos2steps[npos].insert(nstep);
                }
            }
        }
        
        return false;
    }
};
