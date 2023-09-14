class Solution {
public:
    unordered_map<string, multiset<string>> edges;
    vector<string> route;
    
    void dfs(string cur){
        while(!edges[cur].empty()){
            string next = *edges[cur].begin();
            edges[cur].erase(edges[cur].begin());
            // cout << next << " ";
            dfs(next);
        }
        /*
        end node has odd degree,
        so we will stuck at end node,
        now we write it to the end of route
        */
        route.insert(route.begin(), cur);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(vector<string>& ticket : tickets){
            edges[ticket[0]].insert(ticket[1]);
        }
        /*
        all nodes' degrees are even,
        except for start node and end node
        */
        
        dfs("JFK");
        
        return route;
    }
};
