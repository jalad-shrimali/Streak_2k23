class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // int n=arr.size();
        // for(int i=0;i<n;i++){
        //     int temp;
        //     if(arr[i]>arr[i+1]){
        //         temp=arr[i];
        //         arr[i]=arr[i+1];
        //         arr[i+1]=temp;
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(arr[i] - arr[i+1] == arr[i+1]-arr[i+2])return true;
        // }
        // return false;
        int n = arr.size();
        if(n <= 2) return true;
        
        sort(arr.begin(), arr.end());
        
        int diff = arr[1] - arr[0];
        
        for(int i = 1; i+1 < n; ++i){
            if(arr[i+1] - arr[i] != diff){
                return false;
            }
        }
        
        return true;
    }
};
