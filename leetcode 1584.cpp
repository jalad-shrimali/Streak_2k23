class Solution {
public:
    int getDist(vector<int>& pi, vector<int>& pj){
        return abs(pi[0]-pj[0]) + abs(pi[1]-pj[1]);
    }
    
#ifdef ARRAY
    int minnode(bool mstset[], int dist[], int n){
#else
    int minnode(vector<bool>& mstset, vector<int>& dist){
        int n = mstset.size();
#endif
        int minv = INT_MAX;
        int mini = -1;
        
        for(int i = 0; i < n; ++i){
            if(!mstset[i] && dist[i] < minv){
                minv = dist[i];
                mini = i;
            }
        }
        
        return mini;
    }
    
    int primMST(vector<vector<int>>& graph){
        int n = graph.size();
        

#ifdef ARRAY
        bool mstset[n];
        int parent[n];
        int dist[n];
        
        //memset only work for char!
        //it interpret its second argument as "unsigned char" and set n "bytes"!
        // memset(mstset, false, n);
        // memset(parent, -1, n);
        // memset(dist, INT_MAX, n);
        fill(mstset, mstset+n, false);
        fill(parent, parent+n, -1);
        fill(dist, dist+n, INT_MAX);
#else
        vector<bool> mstset(n, false); //whether is in MST
        vector<int> parent(n, -1);
        vector<int> dist(n, INT_MAX); //distance to MST
#endif
        
        // mstset[0] = true;
        parent[0] = -1;
        dist[0] = 0;
        
        /*
        in each iteration, we add one node into MST,
        and then update dist and parent,
        we only need to do n-1 iterations,
        because for the last node, it won't update dist and parent
        */
        for(int i = 0; i < n-1; ++i){
#ifdef ARRAY
            int u = minnode(mstset, dist, n);
#else
            int u = minnode(mstset, dist);
#endif
            
            mstset[u] = true;
            
            //update dist and parent with the newly added "u"
            for(int v = 0; v < n; ++v){
                //u and v are always connected in this problem
                if(!mstset[v] && graph[u][v] < dist[v]){
                    dist[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }
        
        int cost = 0;
        //note here i starts from 1
        for(int i = 1; i < n; ++i){
            cost += graph[parent[i]][i];
        }
        
        return cost;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        if(n == 1) return 0;
        
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
        
        for(int i = 0; i < n; ++i){
            // graph[i][i] = 0;
            vector<int>& pi = points[i];
            for(int j = i+1; j < n; ++j){
                vector<int>& pj = points[j];
                int dist = getDist(pi, pj);
                graph[i][j] = graph[j][i] = dist; 
            }
        }
        
        return primMST(graph);    
    }
};
