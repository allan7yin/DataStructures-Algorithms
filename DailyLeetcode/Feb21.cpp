class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int s=0;
        while(left < right){
           left>>=1;  //l left
           right>>=1;  //r right
           s++;
       }
       return left<<s;
    }
};