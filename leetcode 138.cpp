//using the map old2new
//Runtime: 16 ms, faster than 58.60% of C++ online submissions for Copy List with Random Pointer.
//Memory Usage: 11.5 MB, less than 12.63% of C++ online submissions for Copy List with Random Pointer.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        
        Node* dummy = new Node(-1);
        Node* newprev = dummy;
        unordered_map<Node*, Node*> old2new;
        
        Node* cur = head;
        
        while(cur){
            Node* node = new Node(cur->val);
            //temporarily point to random nodes in old list
            //later we will update it
            node->random = cur->random;
            old2new[cur] = node;
            newprev->next = node;
            newprev = newprev->next;
            cur = cur->next;
        }
        
        Node* newcur = dummy->next;
        
        cur = head;
        newcur = dummy->next;
        while(cur){
            newcur->random = (newcur->random) ? old2new[newcur->random] : nullptr;
            cur = cur->next;
            newcur = newcur->next;
        }
        
        return dummy->next;
    }
};
