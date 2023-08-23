class Solution {
public:
    string reorganizeString(string S) {
        int N = S.size();
        unordered_map<char, int> counter;
        
        for(char c : S){
            counter[c]++;
        }
        
        auto comp = [](const pair<char, int>& a, const pair<char, int>& b){
            return (a.second == b.second) ? (a.first > b.first) : a.second < b.second;};
        
        //the larger count, the earlier be popped
        //the smaller char order, the earlier be popped
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
        
        for(auto it = counter.begin(); it != counter.end(); it++){
            //early stopping
            if(it->second > (N+1)/2) return "";
            pq.push(make_pair(it->first, it->second));
        }
        
        string ans = "";
        
        while(pq.size() >= 2){
            //pop two elements at a time
            pair<char, int> cur = pq.top(); pq.pop();
            pair<char, int> next = pq.top(); pq.pop();
            
            //we don't need this check now, because we process two different char at one time 
            // if(ans.size() > 0 && cur.first == ans[ans.size()-1]) return "";
            ans += cur.first;
            
            // if(ans.size() > 0 && next.first == ans[ans.size()-1]) return "";
            ans += next.first;
            
            //push them back to the queue
            if(--cur.second > 0) pq.push(cur);
            if(--next.second > 0) pq.push(next);
        }
        
        //we jump out the loop when its size is 0 or 1
        if(!pq.empty()) ans += pq.top().first;
        
        return ans;
    }
};
