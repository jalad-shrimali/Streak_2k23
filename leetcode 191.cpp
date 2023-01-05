class Solution {
public:
    int hammingWeight(uint32_t n) {
        // int count=0;
        // while(n>0){
        //     if(n%2==1){
        //         count++;
        //     }
        //     n=n/10;
        // }
        // return count;
    //--------------------------------------------------
    //     int count=0, mask=1;
    //     for(int i=0;i<32;i++)
    //     {
    //         if((count & mask)!=0)count++;
    //         mask = mask << 1;
    //     }
    //     return count;
    // }
        //--------------------------------------------------
    int count=0;
    if(n==0)return 0;
    if(n==1)return 1;
    return hammingWeight(n & (n-1))+1;
    }
};
