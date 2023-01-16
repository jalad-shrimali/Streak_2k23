class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> start_dummy = {-1, newInterval[0]};
        vector<int> end_dummy = {newInterval[1], -1};
        
        //the smallest interval with end >= start_dummy[1]
        auto it1 = lower_bound(intervals.begin(), intervals.end(),
          start_dummy,
          [](const vector<int>& a, const vector<int>& b){
              return a[1] < b[1];
          });
        
        if(it1 == intervals.end()){
            intervals.push_back(newInterval);
            return intervals;
        }
        // cout << (*it1)[0] << ", " << (*it1)[1] << endl;
        
        //the smallest interval with start > end_dummy[0]
        auto it2 = upper_bound(intervals.begin(), intervals.end(),
          end_dummy,
          [](const vector<int>& a, const vector<int>& b){
              return a[0] < b[0];
          });
        if(it2 == intervals.begin()){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        
        //the largest interval with start <= end_dummy[0]
        it2 = prev(it2);
        
        // cout << (*it2)[0] << ", " << (*it2)[1] << endl;
        
        if(it1 == it2){
            *it1 = {min((*it1)[0], newInterval[0]),
                max((*it1)[1], newInterval[1])};
        }else if(it1 < it2){
            vector<int> insertInterval = {
                min((*it1)[0], newInterval[0]),
                max((*it2)[1], newInterval[1])
            };
            *it1 = insertInterval;
            //erase [it1+1, it2]
            intervals.erase(it1+1, it2+1);
        }else{
            //it2 < it1
            //newInterval should be insert btw it2 and it1
            intervals.insert(it1, newInterval);
        }
        
        return intervals;
    }
};
