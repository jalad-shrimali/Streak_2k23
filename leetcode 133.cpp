class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        
        unordered_map<Node*, Node*> old2new;
        
        old2new[node] = new Node(node->val);
        
        queue<Node*> q;
        
        //visit the old graph
        q.push(node);
        
        while(!q.empty()){
            Node* cur = q.front(); q.pop();
            
            for(Node* nei : cur->neighbors){
                if(old2new.find(nei) != old2new.end()){
                    //create the edge
                    old2new[cur]->neighbors.push_back(old2new[nei]);
                    continue;
                }
                old2new[nei] = new Node(nei->val);
                //visit the old graph
                q.push(nei);
                //create the edge
                old2new[cur]->neighbors.push_back(old2new[nei]);
            }
        }
        
        return old2new[node];
    }
};
