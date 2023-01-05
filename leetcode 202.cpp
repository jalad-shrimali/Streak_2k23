class Solution {
public:
    bool isHappy(int n) {
    // int sumsq=0;
    // while(n>0){
    //     int n1=n%10;
    //     sumsq+=n1*n1;
    //     n/=10;
    // }
    // while(sumsq>0){
    //     int n1=sumsq%10;
    //     sumsq+=n1*n1;
    //     sumsq/=10;
    // }
    // if(sumsq==1)return true;
    // else return false;
    int counter=6;
    int val, index;
    while(counter){
        val=0;
        while(n){
            index=n%10;
            val+=index*index;
            n/=10;
        }
        if(val==1) return true;
        n = val;
        counter-=1;
    }
    return false;
    }
};
