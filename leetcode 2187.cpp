class Solution {
public:

long long minimumTime(vector<int>& time, int totalTrips) {
    
    long long left =0, right=1e14,mid;
    
    while(left <= right){
        
        mid=(left +right)/2; // calculating the mid value
        long long ans=0;     //store the number of days
        
        for(int i=0;i<time.size();i++)  //find the sum of time taken by buses till the "mid" index of array
            ans+= mid/time[i];
        
        if(ans < totalTrips) left =mid+1;   //if ans < totalTrips, then we have to go to right block
        
        else right=mid-1;       // go to the left block
        
    }
        
    return left;    

}
};
