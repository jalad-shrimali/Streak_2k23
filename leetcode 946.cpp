class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        stack<int> stk;
        int last = -1;
        
        //jump out when we cannot push or pop the stack
        while((i < pushed.size() || j < popped.size()) && (stk.size() != last)){
            last = stk.size();
            cout << i << " " << j << " " << endl;
            if(!stk.empty() && stk.top() == popped[j]){
                stk.pop();
                // cout << "pop " << popped[j] << endl;
                j++;
            }else if(i < pushed.size()){
                stk.push(pushed[i]);
                // cout << "push " << pushed[i] << endl;
                i++;
            }
        }
        
        return stk.size() == 0;
    }
};
