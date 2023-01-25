class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        
        vector <vector <int>> adj(n);
        vector <vector <int>> dis(2,vector <int> (n,INT_MAX));
        
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        
        
        function <void(int,int)> bfs=[&](int node,int type){
            vector <int> vis(n,0);
            
            queue <pair <int,int>> q;
            q.push({node,0});
            vis[node]=1;
            dis[type][node]=0;
            
            while(q.empty()!=1){
                auto temp=q.front();
                q.pop();
                
                int cost=temp.second;
                int u=temp.first;
                
                dis[type][u]=min(dis[type][u],cost);
                
                for(auto v:adj[u]){
                    if(vis[v]==0){
                        q.push({v,cost+1});
                        vis[v]=1;
                    }
                }
            }
        };
        
        
        bfs(node1,0);
        bfs(node2,1);
        
        int res=INT_MAX;
        int node=-1;
        
        for(int i=0;i<n;i++){
            if(dis[0][i]!=INT_MAX and dis[1][i]!=INT_MAX){
                if(dis[0][i]+dis[1][i]<res){
                    res=min(dis[0][i]+dis[1][i],res);
                    node=i;
                }
                
            }
        }
        
        
        return (res==INT_MAX)?-1:node;
        
    }
};
